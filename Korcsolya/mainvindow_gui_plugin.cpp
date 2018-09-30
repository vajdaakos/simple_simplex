#include "mainvindow_gui_plugin.h"
#include "ui_mainvindow_gui_plugin.h"

Mainvindow_gui_plugin::Mainvindow_gui_plugin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mainvindow_gui_plugin)
{
//    number_delegator=new Delegate_for_numbers(this);
//    non_numeric_delegate=new Non_numeric_Delegate(this);
    ui->setupUi(this);
    ui->button_indulo_matrix->setEnabled(false);
    ui->button_kanonikus->setEnabled(false);
    ui->button_szamol->setEnabled(false);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_5->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Mainvindow_gui_plugin::~Mainvindow_gui_plugin()
{
    delete ui;
}
void Mainvindow_gui_plugin::do_set_indulo_model_view(QStandardItemModel* model)
{

    this->ui->tableView->setModel(model);


}
void Mainvindow_gui_plugin::do_set_kanonikus_alak_model_view(QStandardItemModel* model)
{
    this->ui->tableView_2->setModel(model);
}
void Mainvindow_gui_plugin::do_set_indulo_matrix_model_view(QStandardItemModel* model)
{

    this->ui->tableView_3->setModel(model);


}
void Mainvindow_gui_plugin::do_set_utolso_elotti_allapot_model_view(QStandardItemModel* model)
{

    this->ui->tableView_4->setModel(model);


}
void Mainvindow_gui_plugin::do_set_utolso_allapot_model_view(QStandardItemModel* model)
{

    this->ui->tableView_5->setModel(model);


}
QString Mainvindow_gui_plugin::Name() const
{
    return "Korcsolya";
}


void Mainvindow_gui_plugin::on_button_szamol_clicked()
{

    emit szamol();
}



void Mainvindow_gui_plugin::on_button_indulo_matrix_clicked()
{
    emit indulo_matrix_clicked();

}

void Mainvindow_gui_plugin::do_when_got_indulo_matrix_clicked()
{
    this->ui->button_szamol->setEnabled(true);
    emit make_indulo_matrix();
}


void Mainvindow_gui_plugin::on_button_kezd_clicked()
{
    emit sor_oszlop_db(ui->termteny->value(),ui->korlfelt->value());


}

void Mainvindow_gui_plugin::do_when_button_kezd_clicked(int termteny, int korlfelt)
{
    ui->termteny->setValue(termteny);
    ui->korlfelt->setValue(korlfelt);
    ui->button_kanonikus->setEnabled(true);
    this->ui->button_szamol->setEnabled(false);
    this->ui->button_indulo_matrix->setEnabled(false);


    //minden delegátor alapból szám, a relációs jelek oszlopánál majd átváltom
    for (int col=0; col<ui->termteny->value()+2;++col)
    {
        ui->tableView->setItemDelegateForColumn(col,number_delegator);
    }
    ui->tableView->setItemDelegateForColumn(ui->termteny->value(),non_numeric_delegate);


}

void Mainvindow_gui_plugin::on_button_kanonikus_clicked()
{
    emit kanonikus_clicked();

}
void Mainvindow_gui_plugin::do_when_got_kanonikus_clicked()
{

    this->ui->button_kanonikus->setEnabled(true);
    this->ui->button_indulo_matrix->setEnabled(true);

    this->ui->button_szamol->setEnabled(false);

    emit make_kanonikus();
}
void Mainvindow_gui_plugin::do_when_indulo_feladat_changed()
{
    ui->button_kanonikus->setEnabled(true);
    this->ui->button_szamol->setEnabled(false);
    this->ui->button_indulo_matrix->setEnabled(false);

}

void Mainvindow_gui_plugin::on_radioButton_2_toggled(bool checked)
{
    emit vegigszamol(checked);
}
void Mainvindow_gui_plugin::do_when_vegigszamol_changed(bool checked)
{

    ui->radioButton_2->setChecked(checked);
    ui->radioButton->setChecked(!checked);
}

void Mainvindow_gui_plugin::on_radioButton_toggled(bool checked)
{
    emit vegigszamol(!checked);
}
void Mainvindow_gui_plugin::do_when_external_exercise_loaded(int termtenyezo ,int korl_felt)
{

    ui->termteny->setValue(termtenyezo);
    ui->korlfelt->setValue(korl_felt);
    ui->button_kezd->setEnabled(true);
    ui->button_kanonikus->setEnabled(true);
    ui->button_indulo_matrix->setEnabled(false);
    ui->button_szamol->setEnabled(false);
    for (int col=0; col<ui->termteny->value()+2;++col)
    {
        if(col!=ui->termteny->value())
        ui->tableView->setItemDelegateForColumn(col,number_delegator);
    }
    ui->tableView->setItemDelegateForColumn(ui->termteny->value(),non_numeric_delegate);
}
/**
 * @brief
 * A fő program altal biztosított numerikus delegátor beállítása.
 *
 * A fő program biztosít agy alap delegátort a numerikus adatoknak. Ebben az osztályban ezt használjuk numerikus delegátornak.
 *
 *
 * @param delegate
 * A főprogram által biztosított numerikus delegátorra mutató pointer.
 */
void Mainvindow_gui_plugin::do_set_delegate_for_numbers(QStyledItemDelegate *delegate)
{
    this->number_delegator=delegate;

}
/**
 * @brief
 * A fő program altal biztosított nem-numerikus delegátor beállítása.
 *
 * A fő program biztosít agy alap delegátort a nem-numerikus adatoknak. Ebben az osztályban ezt használjuk nem-numerikus delegátornak.
 *
 *
 * @param delegate
 * A főprogram által biztosított nem-numerikus delegátorra mutató pointer.
 */
void Mainvindow_gui_plugin::do_set_non_numeric_delegate(QItemDelegate * delegate)
{
    this->non_numeric_delegate=delegate;

}
