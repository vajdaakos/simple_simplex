#include "pivot_selector_maxoszlop.h"
Pivot_selector_sormax::Pivot_selector_sormax()
{
}
QString Pivot_selector_sormax::Name() const
{
    return "Maxoszlop";
}
void Pivot_selector_sormax::pivot_element_wanted(QStandardItemModel* model)
{
    QModelIndex pivotelem=model->index(0,0);
    double pmin=qInf();
    int indulo_row=0;
    int rowmin=-0;
    if ( ((model->verticalHeaderItem(0))->text())=="*c")
    {
        indulo_row=2;
    }
    int max_column=select_max_from_row(0,model);
    if (((model->data(model->index(indulo_row,max_column))).toDouble())>0)
    {
        for (int row=indulo_row+1;row<model->rowCount();++row)
        {
            double sor_jobb_o=model->data(model->index(row,model->columnCount()-1)).toDouble();
            double sorba_belep=model->data(model->index(row,max_column)).toDouble();
            if(sorba_belep>0  && (sor_jobb_o/sorba_belep)<pmin && (sor_jobb_o/sorba_belep)>=0)
            {
                pmin=sor_jobb_o/sorba_belep;
                rowmin=row;
            }
        }
        pivotelem=model->index(rowmin,max_column);
    }

    emit post_pivot_element(pivotelem);
}
int Pivot_selector_sormax::select_max_from_row(int row, QStandardItemModel *model)
{
    int max_column=-1;
    double max_value=-1;
    for(int col=0;col<model->columnCount()-1;++col)
    {

        if (model->data(model->index(row,col)).toDouble()>max_value)
        {

            max_column=col;
            max_value=model->data(model->index(row,col)).toDouble();

        }
    }
    return max_column;
}
