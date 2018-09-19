
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "settings.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    auto *gui_plugin_menu=new QMenu(this);
    auto *pivot_plugin_menu=new QMenu(this);
    auto *result_reporter_plugin_menu=new QMenu(this);
    auto *db_plugin_menu=new QMenu(this);
    auto *elmelet_plugin_menu=new QMenu(this);
    auto *Settings_menu=new QMenu(this);
    auto *Help=new QMenu(this);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::add_menus(QWidget *parent_)
{
    QAction *menu_action;

    gui_plugin_menu=menuBar()->addMenu(tr("&Gui"));
    pivot_plugin_menu=menuBar()->addMenu(tr("&Pivot módszer"));
    result_reporter_plugin_menu=menuBar()->addMenu("E&redményjelentés");
    db_plugin_menu=menuBar()->addMenu(tr("&Feladat betöltése"));
    elmelet_plugin_menu=menuBar()->addMenu(tr("&Elmélet"));
    Settings_menu=menuBar()->addMenu(tr("&Beállítások"));
    menu_action=Settings_menu->addAction("Beállítások");
    connect(menu_action,SIGNAL(triggered()),parent_,SLOT(do_set_beallitasok()));
    Help_menu=menuBar()->addMenu(tr("&Súgó"));


    menu_action=Help_menu->addAction("Névjegy");
    connect(menu_action,SIGNAL(triggered()),parent_,SLOT(do_show_nevjegy()));



}
