#include "simplex_method_calculator.h"
#include <QScopedPointer>
#include "settings.h"
#include "nevjegy.h"
#include <QMessageBox>
#include <QDir>



Simplex_method_calculator::Simplex_method_calculator()
{
    this->variable_index=1;
    this->variable_name="x";
    pivoter_=new pivoter();
    indulo_feladat=new QStandardItemModel();
    kanonikus_alak=new QStandardItemModel();
    indulo_matrix=new QStandardItemModel();
    utolso_elotti_allapot=new QStandardItemModel();
    utolso_allapot=new QStandardItemModel();
    horizontal_header=new QStringList;
    vertical_header=new QStringList;
    temp_for_exercise_load=new QStandardItemModel;
    delegate_for_numbers=new Delegate_for_numbers(this);
    non_numeric_delegate=new Non_numeric_Delegate(this);
}

void Simplex_method_calculator::start(const QDir& root_dir)
{
    w=new MainWindow();
    w->add_menus(this);
    do_set_beallitasok();
    connect(this->indulo_feladat,SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)),this,SLOT(do_when_indulo_feladat_changed(QModelIndex,QModelIndex,QVector<int>)));
    set_up_plugins(root_dir);
    w->showMaximized();
}


void Simplex_method_calculator::do_settings_change(int var_index, QString var_name)
{
    do_when_make_kanonikus();
    this->variable_index=var_index;
    this->variable_name=var_name;
    if (indulo_feladat->columnCount()>2 && indulo_feladat->rowCount()>1)
    {
        set_headers(indulo_feladat->columnCount()-2,indulo_feladat->rowCount()-1);
    }


}
void Simplex_method_calculator::set_variable_index(int variable_index)
{
    this->variable_index=variable_index;
}
void Simplex_method_calculator::set_variable_name(QString variable_name)
{
    this->variable_name=variable_name;
}
int Simplex_method_calculator::get_variable_index()
{
    return this->variable_index;
}
QString Simplex_method_calculator::get_variable_name()
{
    return this->variable_name;
}
void Simplex_method_calculator::initialize_indulo_feladat(int term_tenyezok, int korl_feltetelek)
{
    lepesszam=0;
    horizontal_header->clear();
    vertical_header->clear();

    indulo_feladat->clear();

    kanonikus_alak->clear();
    indulo_matrix->clear();
    utolso_elotti_allapot->clear();
    utolso_allapot->clear();



    indulo_feladat->setColumnCount(term_tenyezok+2);
    indulo_feladat->setRowCount(korl_feltetelek+1);
    emit button_kezd_clicked(term_tenyezok, korl_feltetelek);
}
void Simplex_method_calculator::set_cell_to_null(int row, int col)
{
    QModelIndex index = indulo_feladat->index(row,col,QModelIndex());
    indulo_feladat->setData(index,0.0);
}
void Simplex_method_calculator::set_relation_signs(int row, int col)
{
    QModelIndex index = indulo_feladat->index(row,col,QModelIndex());
    if (row != 0 )
    {
        indulo_feladat->setData(index,"<=");

    }
    else
    {
        indulo_feladat->setData(index,"max");
    }
}
void Simplex_method_calculator::set_horizontal_headers(int term_tenyezok)
{
    horizontal_header->clear();
    for(int col = 0; col < (term_tenyezok); ++col)
    {
        QString oszlopcim= get_variable_name() + QString::number(col+get_variable_index());
        horizontal_header->append(oszlopcim);
    }
    horizontal_header->append("<=");
    horizontal_header->append("b");
}
void Simplex_method_calculator::set_vertical_headers(int korl_feltetelek)
{
    vertical_header->clear();
    vertical_header->append("c");
    for(int row = 1; row < korl_feltetelek+1; ++row)
    {
        QString sorcim= "Korl_" + QString::number(row);
        vertical_header->append(sorcim);
    }
}
void Simplex_method_calculator::set_headers(int term_tenyezok, int korl_feltetelek)
{

    set_horizontal_headers(term_tenyezok);
    set_vertical_headers(korl_feltetelek);
    if (utolso_elotti_allapot->columnCount()>2 && utolso_elotti_allapot->rowCount()>1)
    {
        indulo_feladat->setHorizontalHeaderLabels(*horizontal_header);
        indulo_feladat->setVerticalHeaderLabels(*vertical_header);
        do_when_kanonikus_clicked();
        do_when_indulo_matrix_clicked();

    }
    else if  (kanonikus_alak->columnCount()>2 && indulo_feladat->rowCount()>1)
    {
        indulo_feladat->setHorizontalHeaderLabels(*horizontal_header);
        indulo_feladat->setVerticalHeaderLabels(*vertical_header);

        do_when_kanonikus_clicked();
    }
    else if (indulo_feladat->columnCount()>2 && indulo_feladat->rowCount()>1)
    {
        indulo_feladat->setHorizontalHeaderLabels(*horizontal_header);
        indulo_feladat->setVerticalHeaderLabels(*vertical_header);

    }



}
void Simplex_method_calculator::variable_numbers_defined(int term_tenyezok, int korl_feltetelek)
{

    initialize_indulo_feladat(term_tenyezok,  korl_feltetelek);
    for(int row = 0; row < korl_feltetelek+1; ++row)
    {
        for(int col = 0; col < term_tenyezok; ++col)
        {
            set_cell_to_null(row,col);
        }
        set_relation_signs(row,term_tenyezok);
        set_cell_to_null(row, term_tenyezok+1);

    }
    set_headers(term_tenyezok, korl_feltetelek);
}
void Simplex_method_calculator::initialize_kanonikus()
{
    kanonikus_alak->clear();
    indulo_matrix->clear();
    utolso_elotti_allapot->clear();
    utolso_allapot->clear();
    horizontal_header->clear();
    vertical_header->clear();
}
void Simplex_method_calculator::append_rows_and_clear(QList<QStandardItem *> items)
{
    kanonikus_alak->appendRow(items);
    items.clear();

}
void Simplex_method_calculator::set_kanonikus_vertical_header_normal_case(int row)
{
    if (row==0)
    {
        vertical_header->append("c");
    }
    else
    {
        QString sorcim= "Korl_" + QString::number(row);
        vertical_header->append(sorcim);
    }
}
void Simplex_method_calculator::copy_row(int row,QList<QStandardItem *> items)
{
    for(int col = 0; col < (indulo_feladat->columnCount()); ++col)
    {
        if (col==(indulo_feladat->columnCount())-2)
        {
            items.append(new QStandardItem ("="));
        }
        else
        {
            items.append(indulo_feladat->item(row,col)->clone());
        }
    }
    append_rows_and_clear(items);
}
void Simplex_method_calculator::do_when_make_kanonikus_handle_default_case(int row,QList<QStandardItem *> items)
{

    copy_row(row,items);
    set_kanonikus_vertical_header_normal_case(row);

}
void Simplex_method_calculator::do_when_make_kanonikus_handle_greather_than(int row,QList<QStandardItem *> items)
{
    copy_row(row,items);
    set_kanonikus_vertical_header_equation_case(row);

}
void Simplex_method_calculator::set_kanonikus_vertical_header_equation_case(int row)
{
    if (row==0)
    {
        vertical_header->append("c");
    }
    else
    {
        QString sorcim= "*Korl_" + QString::number(row);
        vertical_header->append(sorcim);
    }
}
void Simplex_method_calculator::do_when_make_kanonikus_handle_equation(int row,QList<QStandardItem *> items)
{
    for(int col = 0; col < (indulo_feladat->columnCount()); ++col)
    {
        if (col==(indulo_feladat->columnCount())-2)
        {
            items.append(new QStandardItem ("="));
        }
        else
        {
            items.append(indulo_feladat->item(row,col)->clone());
        }
    }
    set_kanonikus_vertical_header_equation_case(row);
    append_rows_and_clear(items);
}
void Simplex_method_calculator::set_kanonikus_vertical_header_minimum_case()
{
    vertical_header->append("c");
}
void Simplex_method_calculator::do_when_make_kanonikus_handle_minimum(int row,QList<QStandardItem *> items)
{
    QModelIndex index=indulo_feladat->index(row,((indulo_feladat->columnCount())-2)+1);
    for(int col = 0; col < (indulo_feladat->columnCount())-2; ++col)
    {
        QModelIndex index = indulo_feladat->index(row,col,QModelIndex());
        items.append(new QStandardItem (QString::number(((indulo_feladat->data(index).toDouble()))*-1)));
    }
    items.append(new QStandardItem (QString("max")));
    items.append(new QStandardItem (QString::number(indulo_feladat->data(index).toDouble()*-1)));
    set_kanonikus_vertical_header_minimum_case();
    append_rows_and_clear(items);
}
void Simplex_method_calculator::set_kanonikus_horizontal_header()
{
    for(int col = 0; col < (kanonikus_alak->columnCount())-2; ++col)
    {
        QString oszlopcim= variable_name + QString::number(col+variable_index);
        horizontal_header->append(oszlopcim);
    }
    horizontal_header->append("=");
    horizontal_header->append("b");
    kanonikus_alak->setHorizontalHeaderLabels(*horizontal_header);
    kanonikus_alak->setVerticalHeaderLabels(*vertical_header);
}
void Simplex_method_calculator::insert_surplus_variable_header(int row,int z)
{
    kanonikus_alak->setHorizontalHeaderItem(indulo_feladat->columnCount()-3+z,new QStandardItem ("v"+QString::number(row)));
    kanonikus_alak->setData(kanonikus_alak->index(row,(indulo_feladat->columnCount())-3+z+1),"=");
}
void Simplex_method_calculator::insert_surplus_variable(QList<QStandardItem *>items)
{
    int z=0;
    for(int row = 1; row < indulo_feladat->rowCount(); ++row)
    {

        if ((indulo_feladat->data(indulo_feladat->index(row,(indulo_feladat->columnCount())-2,QModelIndex())).toString()=="=>"))
        {
            z++;

            for (int j=0;j<indulo_feladat->rowCount();++j)
            {
                if (j==row)
                {
                    items.append(new QStandardItem ("-1"));
                }
                else
                {
                    items.append(new QStandardItem ("0"));
                }
            }
            kanonikus_alak->insertColumn(indulo_feladat->columnCount()-3+z,items);
            items.clear();
            insert_surplus_variable_header(row,z);
        }


    }
}
void Simplex_method_calculator::do_when_make_kanonikus()
{
    if (indulo_feladat->columnCount()>1 && indulo_feladat->rowCount()>2)
    {
        QList<QStandardItem *> items;
        initialize_kanonikus();
        for(int row = 0; row < indulo_feladat->rowCount(); ++row)
        {

            QModelIndex index = indulo_feladat->index(row,(indulo_feladat->columnCount())-2,QModelIndex());
            if ((indulo_feladat->data(index).toString())==("max") || (indulo_feladat->data(index).toString())=="<=")
            {
                do_when_make_kanonikus_handle_default_case(row,items);
            }
            else if(indulo_feladat->data(index).toString()==("=>"))
            {
                do_when_make_kanonikus_handle_greather_than(row,items);
            }
            else if((indulo_feladat->data(index).toString())==("="))
            {
                do_when_make_kanonikus_handle_equation(row,items);
            }
            else if ((indulo_feladat->data(index).toString())==("min"))
            {
                do_when_make_kanonikus_handle_minimum(row,items);
            }
        }
        set_kanonikus_horizontal_header();
        insert_surplus_variable(items);
        kanonikus_alak->setData(kanonikus_alak->index(0,kanonikus_alak->columnCount()-1),(kanonikus_alak->data(kanonikus_alak->index(0,kanonikus_alak->columnCount()-1)).toDouble())*-1);
    }
}
void Simplex_method_calculator::do_when_make_indulo_matrix()
{
    if (kanonikus_alak->columnCount()>1 && kanonikus_alak->rowCount()>2)
    {
        horizontal_header->clear();
        vertical_header->clear();
        indulo_matrix->clear();
        utolso_allapot->clear();
        utolso_elotti_allapot->clear();
        QList<QStandardItem *> items;
        QList<QStandardItem *> items2;
        QList<QStandardItem *> items3;
        this->lepesszam=0;

        int z=0;

        for (int j=0;j<kanonikus_alak->columnCount();++j)
        {
            double t=0;
            for (int i=1;i<kanonikus_alak->rowCount();++i)
            {


                if (((kanonikus_alak->verticalHeaderItem(i))->text().at(0))=='*')
                {

                    t+=(kanonikus_alak->data(kanonikus_alak->index(i,j)).toDouble());
                    z=1;


                }

            }
            items.append(new QStandardItem (QString::number(t)));


        }
        if (z==1)
        {
            kanonikus_alak->insertRow(0,items);
            kanonikus_alak->setVerticalHeaderItem(0,new QStandardItem("*c"));


        }
        items.clear();
        for (int col=0;col<(kanonikus_alak->columnCount())-2;++col)
        {
            QList<QStandardItem *> items;
            QList<QStandardItem *> items2;
            QList<QStandardItem *> items3;
            for (int row=0;row<kanonikus_alak->rowCount();++row)
            {
                QModelIndex index = kanonikus_alak->index(row,col,QModelIndex());

                items.append(new QStandardItem (QString::number(((kanonikus_alak->data(index).toDouble())))));
                items2.append(new QStandardItem (QString::number(((kanonikus_alak->data(index).toDouble())))));
                items3.append(new QStandardItem (QString::number(((kanonikus_alak->data(index).toDouble())))));
            }
            indulo_matrix->appendColumn(items);
            utolso_elotti_allapot->appendColumn(items2);
            utolso_allapot->appendColumn(items3);

        }
        for (int col=0; col<(kanonikus_alak->rowCount());++col)
        {
            for (int row=0; row<kanonikus_alak->rowCount();++row)
            {
                if (col==0)
                    vertical_header->append((kanonikus_alak->verticalHeaderItem(row))->text());
            }
        }
        for (int col=0;col<indulo_matrix->columnCount();++col)
        {
            horizontal_header->append((kanonikus_alak->horizontalHeaderItem(col))->text());
        }
        for(int row=0;row<kanonikus_alak->rowCount();++row)
        {
            QModelIndex index = kanonikus_alak->index(row,(kanonikus_alak->columnCount())-1,QModelIndex());

            items.append(new QStandardItem (QString::number(((kanonikus_alak->data(index).toDouble())))));
            items2.append(new QStandardItem (QString::number(((kanonikus_alak->data(index).toDouble())))));
            items3.append(new QStandardItem (QString::number(((kanonikus_alak->data(index).toDouble())))));
        }
        horizontal_header->append("Érték");
        indulo_matrix->appendColumn(items);
        utolso_elotti_allapot->appendColumn(items2);
        utolso_allapot->appendColumn(items3);



        indulo_matrix->setHorizontalHeaderLabels(*horizontal_header);
        indulo_matrix->setVerticalHeaderLabels(*vertical_header);

        utolso_elotti_allapot->setHorizontalHeaderLabels(*horizontal_header);
        utolso_elotti_allapot->setVerticalHeaderLabels(*vertical_header);

        utolso_allapot->setHorizontalHeaderLabels(*horizontal_header);
        utolso_allapot->setVerticalHeaderLabels(*vertical_header);

        vertical_header->clear();
        horizontal_header->clear();
        items.clear();
        if (z==1)
        {
            kanonikus_alak->removeRow(0);



        }
    }

}
void Simplex_method_calculator::copy_model_from_to(QStandardItemModel *from, QStandardItemModel *to)
{
    copy_model_data_from_to(from,to);
    for (int row=0;row<to->rowCount();++row)
    {
        to->setVerticalHeaderItem(row,from->verticalHeaderItem(row)->clone());
    }
    for (int col=0;col<from->columnCount();++col)
    {
        to->setHorizontalHeaderItem(col,from->horizontalHeaderItem(col)->clone());
    }

}void Simplex_method_calculator::copy_model_data_from_to(QStandardItemModel *from, QStandardItemModel *to)
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
}
void Simplex_method_calculator::do_when_post_pivot_element(QModelIndex index)
{
    if(index.row()>0)
    {
        ++lepesszam;
        copy_model_from_to(utolso_allapot,utolso_elotti_allapot);
        utolso_elotti_allapot->item(index.row(),index.column())->setData(QColor(Qt::green),Qt::BackgroundRole);
        utolso_allapot->clear();
        utolso_allapot->setColumnCount(utolso_elotti_allapot->columnCount());
        utolso_allapot->setRowCount(utolso_elotti_allapot->rowCount());
        pivoter_->do_pivot(utolso_elotti_allapot,utolso_allapot,index);
        remove_surplus_from_column(utolso_allapot);
        if(vegigszamolom)
            do_when_szamol_clicked();

    }
    else
    {

        result_reporter_plugin_loader_->active_result_reporter_plugin->show_result_report(indulo_feladat, utolso_allapot,lepesszam,  pivot_selector_plugin_loader_->active_pivot_selector_plugin->Name(), variable_name,w);

    }
}

bool Simplex_method_calculator::is_two_phase(QStandardItemModel *model)
{
    if (((model->verticalHeaderItem(0))->text())=="*c")
        return true;

    return false;
}

bool Simplex_method_calculator::is_first_phase_ready(QStandardItemModel *model)
{

    for(int i=0;i<model->columnCount();++i)
    {
        if (utolso_allapot->data(utolso_allapot->index(0,i)).toDouble()>0)
            return false;
    }
    return true;

}
void Simplex_method_calculator::remove_surplus_from_column(QStandardItemModel* model)
{
    for (int i=0;i<model->columnCount();i++)
    {
        if (((model->horizontalHeaderItem(i))->text().at(0))=='*')
        {
            model->removeColumn(i);
            i--;
        }
    }
}

void Simplex_method_calculator::do_when_szamol_clicked()
{
    if (is_two_phase(utolso_allapot))
    {
        if (is_first_phase_ready(utolso_allapot))
            utolso_allapot->removeRow(0);
    }


    if (indulo_matrix->columnCount()>1 && indulo_matrix->rowCount()>2)
    {
        pivot_selector_plugin_loader_->active_pivot_selector_plugin->pivot_element_wanted(utolso_allapot);
    }

}
void Simplex_method_calculator::do_when_indulo_feladat_changed(QModelIndex i, QModelIndex i2, const QVector<int>& j)
{

    kanonikus_alak->clear();
    indulo_matrix->clear();
    utolso_allapot->clear();
    utolso_elotti_allapot->clear();
    emit indulo_feladat_changed();

}
void Simplex_method_calculator::do_when_exercise_loaded(QStandardItemModel* temp)
{

    initialize_indulo_feladat(temp->columnCount()-2,temp->rowCount()-1);

    copy_model_data_from_to(temp,indulo_feladat);
    set_headers(temp->columnCount()-2,temp->rowCount()-1);
    emit external_exercise_loaded(temp->columnCount()-2,temp->rowCount()-1);
    emit set_delegate_for_numbers(delegate_for_numbers);
    emit set_non_numeric_delegate(non_numeric_delegate);

}



void Simplex_method_calculator::do_set_beallitasok()
{
    Settings settings(get_variable_index(),get_variable_name());

    connect(&settings,SIGNAL(settings_changed(int,QString)),this,SLOT(do_settings_change(int,QString)));
    settings.setModal(true);

    settings.exec();

}

void Simplex_method_calculator::set_up_plugins(const QDir& root_dir)
{
    gui_plugin_loader_= new gui_plugin_loader(this, w);
    pivot_selector_plugin_loader_=new Pivot_Selector_Plugin_Loader(this, w);
    result_reporter_plugin_loader_=new Result_Report_plugin_Loader(this,w);
    exercise_load_plugin_loader_=new exercise_load_plugin_loader(this,w);
    picture_load_plugin_loader_=new picture_load_plugin_loader(this,w);

    gui_plugin_loader_->load_plugins(root_dir);

    pivot_selector_plugin_loader_->load_plugins(root_dir);

    result_reporter_plugin_loader_->load_plugins(root_dir);

    exercise_load_plugin_loader_->load_plugins(root_dir);

    picture_load_plugin_loader_->load_plugins(root_dir);
}
void Simplex_method_calculator::do_when_kanonikus_clicked()
{
    emit got_kanonikus_clicked();
}
void Simplex_method_calculator::do_when_indulo_matrix_clicked()
{
    emit got_indulo_matrix_clicked();
}
void Simplex_method_calculator::do_show_nevjegy()
{
    Nevjegy nevjegy(w);
    nevjegy.setModal(true);
    nevjegy.exec();

}
void Simplex_method_calculator::do_when_vegigszamol(bool vegig)
{
    vegigszamolom=vegig;
    emit szamoldvegig(vegig);
}
