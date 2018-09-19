#ifndef MAINVINDOW_GUI_PLUGIN_H
#define MAINVINDOW_GUI_PLUGIN_H

#include <QWidget>
#include <QStandardItemModel>
#include <QDebug>
#include <QtPlugin>
#include "mainwindow_gui_plugin_interface.h"
#include "delegate_for_numbers.h"
#include "non_numeric_delegate.h"
namespace Ui {
class Mainvindow_gui_plugin;
}

class Mainvindow_gui_plugin : public QWidget, public Mainwindow_Gui_Plugin_Interface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.imaddes.Fules_Mainwindow_gui_plugin/1.0.0" FILE "fules.json")
    Q_INTERFACES(Mainwindow_Gui_Plugin_Interface)
public:
    explicit Mainvindow_gui_plugin(QWidget *parent = nullptr);
    ~Mainvindow_gui_plugin() override;

    QString Name() const override;

signals:
    void sor_oszlop_db(int,int) Q_DECL_FINAL;
    void make_kanonikus() Q_DECL_FINAL;
    void make_indulo_matrix() Q_DECL_FINAL;
    void szamol() Q_DECL_FINAL;
    void vegigszamol(bool vegigszamolando) Q_DECL_FINAL;
    void kanonikus_clicked() Q_DECL_FINAL;
    void indulo_matrix_clicked() Q_DECL_FINAL;

public slots:
    void do_set_indulo_model_view(QStandardItemModel*) Q_DECL_OVERRIDE;
    void do_set_kanonikus_alak_model_view(QStandardItemModel*) Q_DECL_OVERRIDE;
    void do_set_indulo_matrix_model_view(QStandardItemModel*) Q_DECL_OVERRIDE;
    void do_set_utolso_elotti_allapot_model_view(QStandardItemModel*) Q_DECL_OVERRIDE;
    void do_set_utolso_allapot_model_view(QStandardItemModel*) Q_DECL_OVERRIDE;
    void do_when_indulo_feladat_changed() Q_DECL_OVERRIDE;
    void do_when_vegigszamol_changed(bool checked) Q_DECL_OVERRIDE;
    void do_when_external_exercise_loaded(int termtenyezo, int korl_felt) Q_DECL_OVERRIDE;
    void do_when_got_kanonikus_clicked() Q_DECL_OVERRIDE;
    void do_when_got_indulo_matrix_clicked() Q_DECL_OVERRIDE;
    void do_set_delegate_for_numbers(QStyledItemDelegate * delegate) Q_DECL_OVERRIDE;
    void do_set_non_numeric_delegate(QItemDelegate * delegate) Q_DECL_OVERRIDE;
    void do_when_button_kezd_clicked(int termteny, int korlfelt) Q_DECL_OVERRIDE;

private slots:
    void on_button_szamol_clicked();

    void on_button_indulo_matrix_clicked();

    void on_button_kezd_clicked();

    void on_button_kanonikus_clicked();



    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_toggled(bool checked);

private:
    Ui::Mainvindow_gui_plugin *ui;
    Delegate_for_numbers *number_delegator;
    Non_numeric_Delegate *non_numeric_delegate;
};

#endif // MAINVINDOW_GUI_PLUGIN_H
