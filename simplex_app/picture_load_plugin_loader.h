#pragma once
#include "picture_load_plugin_interface.h"
#include "simplex_method_calculator.h"
#include <QMainWindow>
#include <QString>
#include <QPluginLoader>
#include <QObject>
#include <QDir>

class picture_load_plugin_loader : public QObject
{
    Q_OBJECT

public:
    explicit picture_load_plugin_loader(QObject *parent = nullptr,MainWindow *w=nullptr);
    void load_plugins(QDir plugins_dir);
signals:

public slots:
    void trigger_plugin(QAction *menu_action);
private:
    QObject* parent_;
    MainWindow* main_window;

};


