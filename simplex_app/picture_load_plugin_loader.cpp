#include "picture_load_plugin_loader.h"

picture_load_plugin_loader::picture_load_plugin_loader(QObject *parent, MainWindow *w)
{
    this->parent_=parent;
    main_window=w;
}
void picture_load_plugin_loader::load_plugins(QDir root_dir)
{
    root_dir.cd("plugins");
    root_dir.cd("picture_load_plugins");
    foreach (QString fileName, root_dir.entryList(QDir::Files))
    {

        QPluginLoader pluginLoader(root_dir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin)
        {
            Picture_Load_Plugin_Interface* picture_load_plugin_interface = qobject_cast<Picture_Load_Plugin_Interface*>(plugin);
            if (picture_load_plugin_interface)
            {
                QAction* menu_action=new QAction(picture_load_plugin_interface->Name(),main_window);
                QVariant v = qVariantFromValue(reinterpret_cast<void *>(picture_load_plugin_interface));
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
    auto *picture_shower = reinterpret_cast<Picture_Load_Plugin_Interface *>(v.value<void *>());
    picture_shower->show_picture(main_window);

}
