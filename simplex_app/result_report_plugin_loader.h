#pragma once
#include <QObject>
#include <QPluginLoader>
#include <QString>
#include <QDir>
#include <QDebug>
#include <QString>
#include <QAction>
#include "result_report_plugin_interface.h"
#include "simplex_method_calculator.h"

class Result_Report_plugin_Loader: public QObject
{
    Q_OBJECT
    friend class Simplex_method_calculator;
public:
    explicit Result_Report_plugin_Loader(QObject *parent = nullptr, MainWindow *w=nullptr);
    void load_plugins(QDir plugins_dir);

signals:

public slots:
    void set_result_reporter(QAction* menu_action);
private:

    QObject* parent_;
    MainWindow* main_window;
    Result_Report_Plugin_Interface* active_result_reporter_plugin;


};


