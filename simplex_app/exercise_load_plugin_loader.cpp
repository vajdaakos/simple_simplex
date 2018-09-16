#include "exercise_load_plugin_loader.h"
#include <QDebug>
exercise_load_plugin_loader::exercise_load_plugin_loader(QObject *parent, MainWindow *w)
{
    this->parent_=parent;
    main_window=w;
}
void exercise_load_plugin_loader::load_plugins(QDir plugins_dir)
{
    plugins_dir.cd("plugins");
    plugins_dir.cd("exercise_load_plugins");
    foreach (QString fileName, plugins_dir.entryList(QDir::Files))
    {

        QPluginLoader pluginLoader(plugins_dir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin)
        {
            Exercise_Load_Plugin_Interface* exercise_load_plugin_interface = qobject_cast<Exercise_Load_Plugin_Interface*>(plugin);
            if (exercise_load_plugin_interface)
            {


                QAction* menu_action=new QAction(exercise_load_plugin_interface->Name(),main_window);
                QVariant v = qVariantFromValue((void *) exercise_load_plugin_interface);
                menu_action->setData(v);
                main_window->db_plugin_menu->addAction(menu_action);
                connect(main_window->db_plugin_menu,SIGNAL(triggered(QAction*)),this,SLOT(trigger_plugin(QAction*)));
                connect(dynamic_cast<QObject*>(exercise_load_plugin_interface),SIGNAL(do_post_exercise(QStandardItemModel*)),parent_,SLOT(do_when_exercise_loaded(QStandardItemModel*)));

            }
        }

    }
}
void exercise_load_plugin_loader::trigger_plugin(QAction* menu_action)
{

    QVariant v = menu_action->data();
    Exercise_Load_Plugin_Interface* loader = (Exercise_Load_Plugin_Interface *) v.value<void *>();
    loader->post_exercise(dynamic_cast<Simplex_method_calculator*>(parent_)->temp_for_exercise_load);

}
