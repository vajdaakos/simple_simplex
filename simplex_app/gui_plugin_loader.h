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
#include "mainwindow_gui_plugin_interface.h"
#include "simplex_method_calculator.h"
class gui_plugin_loader : public QObject
{
    Q_OBJECT
    friend class Simplex_method_calculator;
public:
    explicit gui_plugin_loader(QObject *parent = nullptr, MainWindow *w=nullptr);
    void load_plugins(QDir plugins_dir);



signals:

public slots:
    void set_gui(QAction *menuitem);


private:

    QObject* parent_;
    MainWindow* main_window;

    void emit_signals_to_set_models_of_views();
    void emit_signals_to_set_delegates();


};

