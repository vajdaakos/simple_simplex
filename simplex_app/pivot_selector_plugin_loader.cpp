#include "pivot_selector_plugin_loader.h"

Pivot_Selector_Plugin_Loader::Pivot_Selector_Plugin_Loader(QObject *parent, MainWindow *w) : QObject(parent)
{
    this->parent_=parent;
    main_window=w;
}
void Pivot_Selector_Plugin_Loader::load_plugins(QDir plugins_dir)
{

    auto *pivot_selector_plugin_group=new QActionGroup (main_window);
    pivot_selector_plugin_group->setExclusive(true);
    plugins_dir.cd("plugins");
    plugins_dir.cd("pivot_selector_plugins");
    foreach (QString fileName, plugins_dir.entryList(QDir::Files))
    {
        QPluginLoader pluginLoader(plugins_dir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin)
        {
            Pivot_Selector_Plugin_Interface* pivot_selector_interface = qobject_cast<Pivot_Selector_Plugin_Interface*>(plugin);
            if (pivot_selector_interface)
            {

                QAction* menu_action=new QAction(pivot_selector_interface->Name(),main_window);
                main_window->pivot_plugin_menu->addAction(menu_action);
                pivot_selector_plugin_group->addAction(menu_action);
                QVariant v = qVariantFromValue((void *) pivot_selector_interface);


                menu_action->setData(v);
                menu_action->setCheckable(true);


                connect(main_window->pivot_plugin_menu,SIGNAL(triggered(QAction*)),this,SLOT(set_pivot_selector(QAction*)));
                connect(dynamic_cast<QObject*>(pivot_selector_interface),SIGNAL(post_pivot_element(QModelIndex)),parent_,SLOT(do_when_post_pivot_element(QModelIndex)));
                if(fileName.contains("_default"))
                {
                    menu_action->setChecked(true);
                    active_pivot_selector_plugin=pivot_selector_interface;

                }
            }
        }
    }

}

void Pivot_Selector_Plugin_Loader::set_pivot_selector(QAction *menu_action)
{

    QVariant v = menu_action->data();
    auto *pivot_selector = reinterpret_cast<Pivot_Selector_Plugin_Interface *>(v.value<void *>());

    active_pivot_selector_plugin=pivot_selector;

}

