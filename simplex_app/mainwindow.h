#pragma once
#include <QStandardItemModel>
#include <QMainWindow>
#include <QStackedLayout>
#include <QStackedWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class gui_plugin_loader;
    friend class Pivot_Selector_Plugin_Loader;
    friend class exercise_load_plugin_loader;
    friend class picture_load_plugin_loader;
    friend class Result_Report_plugin_Loader;
    friend class Simplex_method_calculator;

public:
    explicit MainWindow(QWidget *parent = 0);


    ~MainWindow();
private:

    QMenu* gui_plugin_menu;
    QMenu* pivot_plugin_menu;
    QMenu* result_reporter_plugin_menu;
    QMenu* db_plugin_menu;
    QMenu* elmelet_plugin_menu;
    QMenu* Settings_menu;
    QMenu* Help_menu;
    QStackedWidget* central_widget;
    void add_menus(QWidget* parent_);

public slots:


    //void here_you_are(Indulo_model_view*);
private:
    Ui::MainWindow *ui;

};

