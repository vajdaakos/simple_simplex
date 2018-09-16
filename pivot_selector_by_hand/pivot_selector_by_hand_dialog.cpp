#include "pivot_selector_by_hand_dialog.h"
#include "ui_pivot_selector_by_hand_dialog.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QMessageBox>
Pivot_Selector_By_Hand_Dialog::Pivot_Selector_By_Hand_Dialog(QStandardItemModel* model,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pivot_Selector_By_Hand_Dialog)
{

    ui->setupUi(this);
    this->ui->tableView->setModel(model);
}

Pivot_Selector_By_Hand_Dialog::~Pivot_Selector_By_Hand_Dialog()
{
    delete ui;
}

void Pivot_Selector_By_Hand_Dialog::on_pushButton_clicked()
{
    QStandardItemModel* model=dynamic_cast<QStandardItemModel*>(this->ui->tableView->model());
    if(this->ui->tableView->selectionModel()->selectedIndexes().count()<1 || this->ui->tableView->selectionModel()->selectedIndexes().at(0).row()==0 || this->ui->tableView->selectionModel()->selectedIndexes().at(0).column()>this->ui->tableView->model()->columnCount()-2 || model->verticalHeaderItem(this->ui->tableView->selectionModel()->selectedIndexes().at(0).row())->text()=="c" )
    {

        QMessageBox::warning(this, tr("Simple Szimplex"),tr("Válassz pivotelemet! Nem választhatsz a (másodlagos) célfüggvény sorából és az utolsó oszlopból!"),QMessageBox::Ok);
    }
    else
    {

        this->accept();
        emit pivot_selected(this->ui->tableView->selectionModel()->selectedIndexes().at(0));
    }

}

void Pivot_Selector_By_Hand_Dialog::on_pushButton_2_clicked()
{
    this->accept();
    dynamic_cast<Pivot_selector_by_hand*>(parent())->do_when_pivot_element_selected(this->ui->tableView->model()->index(0,0));
}
