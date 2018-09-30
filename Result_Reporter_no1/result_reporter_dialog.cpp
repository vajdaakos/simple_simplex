#include "result_reporter_dialog.h"
#include "ui_result_reporter_dialog.h"
#include <QDebug>
result_reporter_dialog::result_reporter_dialog(QStandardItemModel *indulo, QStandardItemModel *result, int lsz, const QString& pivot_modszer, const QString& vari_name, QWidget *parent) :
    QDialog(parent),
    indulo(indulo),
    result(result),
    lsz(lsz),
    pivot_modszer(pivot_modszer),
    vari_name(vari_name),
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


        ui->szoveges_eredmeny->setText(ui->szoveges_eredmeny->text()+"<br><br>Az utoljára alkalmazot pivotelem választási módszer:");
        ui->szoveges_eredmeny->setText(ui->szoveges_eredmeny->text()+"<br>"+pivot_modszer);

        ui->szoveges_eredmeny->setText(ui->szoveges_eredmeny->text()+"<br>Pivotálások száma:"+QString::number(lsz));
    if (!is_megengedett())
    {
        ui->szoveges_eredmeny->setText(ui->szoveges_eredmeny->text()+"<br><br>A megoldás nem megengedett megoldás. A feltételek ellentmondást tartalmazhatnak vagy hibásan választottál pivotelemet.");
    }
    if (is_optimalis())
    {
        if (is_megengedett())
            ui->szoveges_eredmeny->setText(ui->szoveges_eredmeny->text()+"<br><br>A megoldás optimális megoldás.");
        if (is_degeneralt())
        {
            ui->szoveges_eredmeny->setText(ui->szoveges_eredmeny->text()+"<br><br>A megoldás degenerált.");
        }
        if (is_alternative())
        {
            ui->szoveges_eredmeny->setText(ui->szoveges_eredmeny->text()+"<br><br>Alternatív optimum lehetséges.");
        }

    }
    else if(!is_kesz())
    {
        ui->szoveges_eredmeny->setText(ui->szoveges_eredmeny->text()+"<br><br>A megoldás nem optimális megoldás, lehet további pivot elemet választani. A feladat nincs kész.");
    }
    else
    {
        ui->szoveges_eredmeny->setText(ui->szoveges_eredmeny->text()+"<br><br>A feladat nem korlátos.");
    }


    if (x_marad())
    {
        ui->szoveges_eredmeny->setText(ui->szoveges_eredmeny->text()+"<br><br>Az eredménytáblában a primál változók értékei:");
        for (int row=1;row<this->eredmeny_result->rowCount();++row)
        {
            if (this->eredmeny_result->verticalHeaderItem(row)->text().QString::startsWith(vari_name))
            {
                ui->szoveges_eredmeny->setText(ui->szoveges_eredmeny->text()+"<br><font color=red>"+(this->eredmeny_result->verticalHeaderItem(row))->text()+"</font> = "+QString::number(this->eredmeny_result->data(this->eredmeny_result->index(row,this->eredmeny_result->columnCount()-1)).toDouble()));
            }
        }

    }
    if (v_marad())
    {
        ui->szoveges_eredmeny->setText(ui->szoveges_eredmeny->text()+"<br><br>Az eredménytáblában a felesleg változók értékei:");
        for (int row=1;row<this->eredmeny_result->rowCount();++row)
        {
            if (this->eredmeny_result->verticalHeaderItem(row)->text().QString::startsWith("Korl") || this->eredmeny_result->verticalHeaderItem(row)->text().QString::startsWith("*Korl") || this->eredmeny_result->verticalHeaderItem(row)->text().QString::startsWith("v"))
            {
                ui->szoveges_eredmeny->setText(ui->szoveges_eredmeny->text()+"<br><font color=blue>"+(this->eredmeny_result->verticalHeaderItem(row))->text()+"</font> = "+QString::number(this->eredmeny_result->data(this->eredmeny_result->index(row,this->eredmeny_result->columnCount()-1)).toDouble()));
            }


        }

    }

    ui->szoveges_eredmeny->setText(ui->szoveges_eredmeny->text()+"<br>A célfüggvény értéke:<br><font color=green>"+(this->eredmeny_result->verticalHeaderItem(0))->text()+"</font> = "+QString::number(this->eredmeny_result->data(this->eredmeny_result->index(0,this->eredmeny_result->columnCount()-1)).toDouble()*-1));
    //if (v_marad==true)

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

bool result_reporter_dialog::is_megengedett()
{
    for (int row=1;row<this->eredmeny_result->rowCount();++row)
    {
        if (this->eredmeny_result->data(this->eredmeny_result->index(row,this->eredmeny_result->columnCount()-1)).toDouble()<0)
        {
            return false;

        }
    }

    return true;
}

bool result_reporter_dialog::is_optimalis()
{
for (int col=0;col<this->eredmeny_result->columnCount()-1;++col)
{
    if (this->eredmeny_result->data(this->eredmeny_result->index(0,col)).toDouble()>0)
    {        
        return false;

    }
}
return true;
}

bool result_reporter_dialog::is_alternative()
{
for (int col=0;col<this->eredmeny_result->columnCount()-1;++col)
{
    if (this->eredmeny_result->data(this->eredmeny_result->index(0,col)).toDouble()==0)
    {
        return true;

    }
}
return false;
}

bool result_reporter_dialog::is_degeneralt()
{
for (int row=1;row<this->eredmeny_result->rowCount();++row)
{
    if (this->eredmeny_result->data(this->eredmeny_result->index(row,this->eredmeny_result->columnCount()-1)).toDouble()==0 && this->eredmeny_result->verticalHeaderItem(row)->text().QString::startsWith(vari_name))
    {
        return true;

    }
}
return false;
}
bool result_reporter_dialog::x_marad()
{
    for (int row=1;row<this->eredmeny_result->rowCount();++row)
    {
        if (this->eredmeny_result->verticalHeaderItem(row)->text().QString::startsWith(vari_name))
        {
            return true;

        }
    }
    return false;
}

bool result_reporter_dialog::v_marad()
{
    for (int row=1;row<this->eredmeny_result->rowCount();++row)
    {
        if (this->eredmeny_result->verticalHeaderItem(row)->text().QString::startsWith("Korl") || this->eredmeny_result->verticalHeaderItem(row)->text().QString::startsWith("*Korl") || this->eredmeny_result->verticalHeaderItem(row)->text().QString::startsWith("v"))
        {
            return true;

        }
    }
    return false;
}
bool result_reporter_dialog::is_kesz()
{
    bool van_elem=false;
    for (int col=0;col<this->eredmeny_result->columnCount()-1;++col)
    {
        bool nemkorlatos=true;

        if (this->eredmeny_result->data(this->eredmeny_result->index(0,col)).toDouble()>0)
        {

            for (int row=1;row<this->eredmeny_result->rowCount()-1;++row)
            {
                if ((this->eredmeny_result->data(this->eredmeny_result->index(row,col)).toDouble())/(this->eredmeny_result->data(this->eredmeny_result->index(row,eredmeny_result->columnCount()-1)).toDouble())>0)
                 {

                    nemkorlatos=false;
                    van_elem=true;

                }
            }
        if(nemkorlatos)
            return nemkorlatos;

        }
    }
return van_elem;
}
