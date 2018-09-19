#include "result_reporter_dialog.h"
#include "ui_result_reporter_dialog.h"
#include <QDebug>
#include <utility>
result_reporter_dialog::result_reporter_dialog(QStandardItemModel *indulo, QStandardItemModel *result, int lsz, QString pivot_modszer, QString vari_name, QWidget *parent) :
    QDialog(parent),
    indulo(indulo),
    result(result),
    lsz(lsz),
    pivot_modszer(std::move(pivot_modszer)),
    vari_name(std::move(vari_name)),
    ui(new Ui::result_reporter_dialog)
{
    eredmeny_indulo= new QStandardItemModel(this);
    eredmeny_result= new QStandardItemModel(this);
    eredmeny_indulo->setColumnCount(indulo->columnCount());
    eredmeny_indulo->setRowCount(indulo->rowCount());
    eredmeny_result->setColumnCount(result->columnCount());
    eredmeny_result->setRowCount(result->rowCount());

    Qt::WindowFlags flags = Qt::Dialog | Qt::WindowSystemMenuHint
            | Qt::WindowMinimizeButtonHint
            | Qt::WindowMaximizeButtonHint
            | Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);
    ui->setupUi(this);
    //model másolása

    copy_model_from_to(indulo,eredmeny_indulo);
    copy_model_from_to(result,eredmeny_result);


    ui->indulo_alak->setModel(this->eredmeny_indulo);
    ui->utolso_lepes_utan->setModel(this->eredmeny_result);



}

result_reporter_dialog::~result_reporter_dialog()
{
    delete ui;
}

void result_reporter_dialog::on_result_reporter_dialog_finished()
{
    this->deleteLater();
}

void result_reporter_dialog::copy_model_from_to(QStandardItemModel *from, QStandardItemModel *to)
{
    QList<QStandardItem *> items;

    to->clear();
    for (int row=0;row<from->rowCount();++row)
    {
        for (int col=0;col<from->columnCount();++col)
        {
            items.append(from->item(row,col)->clone());

        }
        to->appendRow(items);
        items.clear();

    }
    for (int row=0;row<to->rowCount();++row)
    {
        to->setVerticalHeaderItem(row,from->verticalHeaderItem(row)->clone());
    }
    for (int col=0;col<from->columnCount();++col)
    {
        to->setHorizontalHeaderItem(col,from->horizontalHeaderItem(col)->clone());
    }

}


