#pragma once

#include <QObject>
#include <QPluginLoader>
#include <QString>
#include <QDir>
#include <QMainWindow>
#include "pivot_selector_plugin_interface.h"
#include "simplex_method_calculator.h"

class Pivot_Selector_Plugin_Loader : public QObject
{
    Q_OBJECT
    friend class Simplex_method_calculator;
public:
    explicit Pivot_Selector_Plugin_Loader(QObject *parent = nullptr, MainWindow *w=nullptr);
    void load_plugins(QDir plugins_dir);

signals:

public slots:
    void set_pivot_selector(QAction* menu_action);
private:

    QObject* parent_;
    MainWindow* main_window;
    Pivot_Selector_Plugin_Interface* active_pivot_selector_plugin;


};

