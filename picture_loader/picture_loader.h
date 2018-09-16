#ifndef PICTURE_LOADER_H
#define PICTURE_LOADER_H
#include <QWidget>
#include <QtPlugin>
#include "picture_load_plugin_interface.h"
#include "picture_loader_dialog.h"
class Picture_Loader:public QWidget, public Picture_Load_Plugin_Interface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.imaddes.simplex.picture_load_plugin_interface/1.0.0" FILE "picture_loader.json")
    Q_INTERFACES(Picture_Load_Plugin_Interface)
public:
    Picture_Loader();
    QString Name() const;

    void show_picture(QMainWindow* w);
};

#endif // PICTURE_LOADER_H
