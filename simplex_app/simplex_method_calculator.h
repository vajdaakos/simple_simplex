#pragma once
#include "mainwindow.h"
#include "pivoter.h"
#include <QStandardItemModel>
#include <QObject>
#include <QWidget>
#include <QString>
#include "settings.h"
#include "gui_plugin_loader.h"
#include "pivot_selector_plugin_loader.h"
#include "result_report_plugin_loader.h"
#include "exercise_load_plugin_loader.h"
#include "picture_load_plugin_loader.h"
#include "delegate_for_numbers.h"
#include "non_numeric_delegate.h"
class  Result_Report_plugin_Loader;
class picture_load_plugin_loader;
class gui_plugin_loader;
class Pivot_Selector_Plugin_Loader;
class exercise_load_plugin_loader;
class Simplex_method_calculator: public QWidget
{
    Q_OBJECT
    friend class gui_plugin_loader;
    friend class Pivot_Selector_Plugin_Loader;
    friend class exercise_load_plugin_loader;

public:
    Simplex_method_calculator();
    void start(int, char *[], QDir plugins_dir);

private:
    QStandardItemModel *indulo_feladat;
    QStandardItemModel *kanonikus_alak;
    QStandardItemModel *indulo_matrix;
    QStandardItemModel *utolso_elotti_allapot;
    QStandardItemModel *utolso_allapot;
    QStringList *horizontal_header;
    QStringList *vertical_header;
    QStandardItemModel *temp_for_exercise_load;

    gui_plugin_loader* gui_plugin_loader_;
    Pivot_Selector_Plugin_Loader* pivot_selector_plugin_loader_;
    exercise_load_plugin_loader* exercise_load_plugin_loader_;
    Result_Report_plugin_Loader* result_reporter_plugin_loader_;
    picture_load_plugin_loader* picture_load_plugin_loader_;

    Delegate_for_numbers* delegate_for_numbers;
    Non_numeric_Delegate* non_numeric_delegate;


    QString pivot_modszer;
    MainWindow* w;
    QString variable_name;
    pivoter *pivoter_;
    int variable_index;
    int lepesszam;
    bool vegigszamolom=false;


    void set_up();
    void set_up_plugins(QDir plugins_dir);

    void set_variable_index(int variable_index);
    void set_variable_name(QString variable_name);
    int get_variable_index();
    QString get_variable_name();

    void initialize_indulo_feladat(int term_tenyezok, int korl_feltetelek);
    void set_cell_to_null(int row, int col);
    void set_relation_signs(int row, int col);
    void set_headers(int term_tenyezok, int korl_feltetelek);
    void set_horizontal_headers(int term_tenyezok);
    void set_vertical_headers(int korl_feltetelek);

    void append_rows_and_clear(QList<QStandardItem *> items);

    void initialize_kanonikus();
    void copy_row(int row,QList<QStandardItem *> items);
    void do_when_make_kanonikus_handle_default_case(int row, QList<QStandardItem *> items);
    void set_kanonikus_vertical_header_normal_case(int row);
    void do_when_make_kanonikus_handle_greather_than(int row, QList<QStandardItem *> items);
    void do_when_make_kanonikus_handle_equation(int row,QList<QStandardItem *> items);
    void set_kanonikus_vertical_header_equation_case(int row);
    void do_when_make_kanonikus_handle_minimum(int row,QList<QStandardItem *> items);
    void set_kanonikus_vertical_header_minimum_case();
    void set_kanonikus_horizontal_header();
    void insert_surplus_variable(QList<QStandardItem *>items);
    void insert_surplus_variable_header(int row, int z);
    void copy_model_from_to(QStandardItemModel* from, QStandardItemModel* to);

    bool is_two_phase(QStandardItemModel* model);
    bool is_first_phase_ready(QStandardItemModel *model);
    void remove_surplus_from_column(QStandardItemModel* model);
    void copy_model_data_from_to(QStandardItemModel *from, QStandardItemModel *to);

signals:
    void set_indulo_feladat_model_view(QStandardItemModel*);
    void set_kanonikus_alak_model_view(QStandardItemModel*);
    void set_indulo_matrix_model_view(QStandardItemModel*);
    void set_utolso_elotti_allapot_model_view(QStandardItemModel*);
    void set_utolso_allapot_model_view(QStandardItemModel*);
    void set_delegate_for_numbers(QStyledItemDelegate*);
    void set_non_numeric_delegate(QItemDelegate*);
    void indulo_feladat_changed();
    void external_exercise_loaded(int,int);
    void got_kanonikus_clicked();
    void got_indulo_matrix_clicked();
    void button_kezd_clicked(int termteny, int korlfelt);
    void szamoldvegig(bool vegig);

public slots:
    void variable_numbers_defined(int, int);
    void do_settings_change(int,QString);
    void do_set_beallitasok();
    void do_when_make_kanonikus();
    void do_when_make_indulo_matrix();
    void do_when_szamol_clicked();
    void do_when_post_pivot_element(QModelIndex index);
    void do_when_indulo_feladat_changed(QModelIndex i, QModelIndex i2, QVector<int> j);
    void do_when_exercise_loaded(QStandardItemModel*);
    void do_when_kanonikus_clicked();
    void do_when_indulo_matrix_clicked();
    void do_show_nevjegy();
    void do_when_vegigszamol(bool vegig);


};

