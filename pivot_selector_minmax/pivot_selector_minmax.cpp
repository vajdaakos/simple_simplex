#include "pivot_selector_minmax.h"

#include <QDebug>

Pivot_selector_minmax::Pivot_selector_minmax()=default;

QString Pivot_selector_minmax::Name() const
{
    return "Minmax";
}



void Pivot_selector_minmax::pivot_element_wanted(QStandardItemModel* model)
{

    QModelIndex pivotelem=model->index(0,0);
    int colmax=-1;
    int rowmin=-1;
    int finalrowmin=-1;
    double max=-1;
    for (int col=0;col<(model->columnCount())-1;++col)
    {
        double pmin=qInf();

        if (((model->data(model->index(0,col))).toDouble())>0)
        {
            for (int row=1;row<model->rowCount();++row)
            {
                if ( (model->verticalHeaderItem(row))->text().at(0) !='c')
                {
                    double sor_jobb_o=model->data(model->index(row,model->columnCount()-1)).toDouble();
                    double sorba_belep=model->data(model->index(row,col)).toDouble();
                    if(sorba_belep>0  && (sor_jobb_o/sorba_belep)<pmin && (sor_jobb_o/sorba_belep)>=0)
                    {
                        pmin=sor_jobb_o/sorba_belep;
                        rowmin=row;
                    }
                }
            }
            if (pmin>max && pmin!=qInf() && pmin>=0)
            {
                finalrowmin=rowmin;
                max=pmin;
                colmax=col;
                pivotelem=model->index(finalrowmin,colmax);
            }
        }
    }
    if (colmax>=0 && finalrowmin>=0)
    {
        pivotelem=model->index(finalrowmin,colmax);
     }

    emit post_pivot_element(pivotelem);
}
