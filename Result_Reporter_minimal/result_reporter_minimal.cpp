#include "result_reporter_minimal.h"
#include "result_reporter_dialog.h"
#include <QDebug>
Result_Reporter_Minimal::Result_Reporter_Minimal(QWidget *parent) :QDialog(parent)
{

}

void Result_Reporter_Minimal::show_result_report(QStandardItemModel* indulo, QStandardItemModel* result, int lsz, QString pivot_modszer, QString vari_name,QWidget* parent)
{

this->indulo=indulo;

this->result=result;

result_reporter_dialog* dialogwindow=new result_reporter_dialog(this->indulo,this->result,lsz,pivot_modszer,vari_name,parent);
dialogwindow->setAttribute(Qt::WA_DeleteOnClose);
dialogwindow->show();

}

QString Result_Reporter_Minimal::Name() const
{
    return "Minimal";
}


void Result_Reporter_Minimal::copy_model_from_to(QStandardItemModel *from, QStandardItemModel *to)
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
