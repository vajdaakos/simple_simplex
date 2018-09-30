#pragma once
#include <QString>
#include <QWidget>
#include <QMainWindow>
class Picture_Load_Plugin_Interface
{
public:

    virtual void show_picture(QMainWindow* w)=0;
    virtual QString Name() const = 0;

};
Q_DECLARE_INTERFACE(Picture_Load_Plugin_Interface,"com.imaddes.simplex.picture_load_plugin_interface/1.0.0")

