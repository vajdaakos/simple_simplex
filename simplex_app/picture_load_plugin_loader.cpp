#include "picture_load_plugin_loader.h"

picture_load_plugin_loader::picture_load_plugin_loader(QObject *parent, MainWindow *w)
{
    this->parent_=parent;
    main_window=w;
}
void picture_load_plugin_loader::load_plugins(QDir plugins_dir)
{
    plugins_dir.cd("plugins");
    plugins_dir.cd("picture_load_plugins");
    foreach (QString fileName, plugins_dir.entryList(QDir::Files))
    {

        QPluginLoader pluginLoader(plugins_dir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin)
        {
            Picture_Load_Plugin_Interface* picture_load_plugin_interface = qobject_cast<Picture_Load_Plugin_Interface*>(plugin);
            if (picture_load_plugin_interface)
            {
                QAction* menu_action=new QAction(picture_load_plugin_interface->Name(),main_window);
                QVariant v = qVariantFromValue((void *) picture_load_plugin_interface);
                menu_action->setData(v);
                main_window->elmelet_plugin_menu->addAction(menu_action);
                connect(main_window->elmelet_plugin_menu,SIGNAL(triggered(QAction*)),this,SLOT(trigger_plugin(QAction*)));
            }
        }

    }
}
void picture_load_plugin_loader::trigger_plugin(QAction* menu_action)
{

    QVariant v = menu_action->data();
    Picture_Load_Plugin_Interface* picture_shower = (Picture_Load_Plugin_Interface *) v.value<void *>();
    picture_shower->show_picture(main_window);

}
