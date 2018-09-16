#pragma once
#include <QWidget>
#include <QMainWindow>
#include <QString>
#include <QDir>
#include <QActionGroup>
#include <QDebug>
#include <QMenu>
#include <QMenuBar>
#include <QPluginLoader>
#include "excercise_load_plugin_interface.h"
#include "simplex_method_calculator.h"

class exercise_load_plugin_loader : public QObject
{
    Q_OBJECT
public:
    explicit exercise_load_plugin_loader(QObject *parent = nullptr, MainWindow *w=nullptr);
    void load_plugins(QDir plugins_dir);
private:

    QObject* parent_;
    MainWindow* main_window;

public slots:
    void trigger_plugin(QAction *menu_action);
};


