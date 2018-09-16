#pragma once
#include <QString>
#include <QWidget>
#include <QStandardItemModel>
#include <QItemDelegate>
#include <QStyledItemDelegate>
class Mainwindow_Gui_Plugin_Interface
{
public:
    virtual QString Name() const = 0;

signals:
    virtual void make_indulo_matrix()=0;
    virtual void sor_oszlop_db(int,int) = 0;
    virtual void make_kanonikus()=0;
    virtual void szamol()=0;
    virtual void vegigszamol(bool vegigszamolando)=0;
    virtual void kanonikus_clicked()=0;
    virtual void indulo_matrix_clicked()=0;


public slots:
    virtual void do_set_indulo_model_view(QStandardItemModel*)=0;
    virtual void do_set_kanonikus_alak_model_view(QStandardItemModel*)=0;
    virtual void do_set_indulo_matrix_model_view(QStandardItemModel*)=0;
    virtual void do_set_utolso_elotti_allapot_model_view(QStandardItemModel*)=0;
    virtual void do_set_utolso_allapot_model_view(QStandardItemModel*)=0;
    virtual void do_when_indulo_feladat_changed()=0;
    virtual void do_when_vegigszamol_changed(bool vegigszamolando)=0;
    virtual void do_when_external_exercise_loaded(int,int)=0;
    virtual void do_when_got_kanonikus_clicked()=0;
    virtual void do_when_got_indulo_matrix_clicked()=0;
    virtual void do_set_delegate_for_numbers(QStyledItemDelegate*)=0;
    virtual void do_set_non_numeric_delegate(QItemDelegate*)=0;
    virtual void do_when_button_kezd_clicked(int termteny, int korlfelt)=0;





//    virtual void do_set_delegator_for_numbers()=0;

};
Q_DECLARE_INTERFACE(Mainwindow_Gui_Plugin_Interface,"com.imaddes.simplex.mainwindow_gui_plugin_interface/1.0.0")
