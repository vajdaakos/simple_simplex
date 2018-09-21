#include "result_report_plugin_loader.h"

Result_Report_plugin_Loader::Result_Report_plugin_Loader(QObject *parent, MainWindow *w) : QObject(parent)
{
    this->parent_=parent;
    main_window=w;
}
void Result_Report_plugin_Loader::load_plugins(QDir plugins_dir)
{

    auto *result_reporter_plugin_group=new QActionGroup (main_window);
    result_reporter_plugin_group->setExclusive(true);
    plugins_dir.cd("plugins");
    plugins_dir.cd("result_reporter_plugins");
    foreach (QString fileName, plugins_dir.entryList(QDir::Files))
    {
        QPluginLoader pluginLoader(plugins_dir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin)
        {
            Result_Report_Plugin_Interface* result_reporter_interface = qobject_cast<Result_Report_Plugin_Interface*>(plugin);
            if (result_reporter_interface)
            {
                QAction* menu_action=new QAction(result_reporter_interface->Name(),main_window);
                main_window->result_reporter_plugin_menu->addAction(menu_action);
                result_reporter_plugin_group->addAction(menu_action);
                QVariant v = qVariantFromValue(reinterpret_cast<void *>(result_reporter_interface));
                menu_action->setData(v);
                menu_action->setCheckable(true);
                connect(main_window->result_reporter_plugin_menu,SIGNAL(triggered(QAction*)),this,SLOT(set_result_reporter(QAction*)));

               if(fileName.contains("_default"))
                {
                    menu_action->setChecked(true);
                    active_result_reporter_plugin=result_reporter_interface;

                }

            }
        }
    }

}

void Result_Report_plugin_Loader::set_result_reporter(QAction *menu_action)
{
    QVariant v = menu_action->data();
    auto *result_reporter = reinterpret_cast<Result_Report_Plugin_Interface*>(v.value<void *>());
    active_result_reporter_plugin=result_reporter;


}
