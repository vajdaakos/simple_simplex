#include "pivoter.h"

pivoter::pivoter(QObject *parent)
{

}

void pivoter::do_pivot(QStandardItemModel* last, QStandardItemModel* output, QModelIndex pivot_element_)
{

        QModelIndex pivot_element=last->index(pivot_element_.row(),pivot_element_.column());


        double pivot=(last->data(last->index(pivot_element.row(),pivot_element.column())).toDouble());

        for (int row=0;row<last->rowCount();++row)
        {
            if (row != pivot_element.row())
            {
                output->setVerticalHeaderItem(row,((last->verticalHeaderItem(row)->clone())));
            }
        }
        for (int col=0;col<last->columnCount();++col)
        {
            if (col != pivot_element.column())
            {
                output->setHorizontalHeaderItem(col,((last->horizontalHeaderItem(col)->clone())));
            }
        }
        output->setHorizontalHeaderItem(pivot_element.column(),((last->verticalHeaderItem(pivot_element.row())->clone())));
        output->setVerticalHeaderItem(pivot_element.row(),((last->horizontalHeaderItem(pivot_element.column())->clone())));
        output->setData(output->index(pivot_element.row(),pivot_element.column()),1/(pivot));
        for (int row=0;row<last->rowCount();++row)
        {
            if (row != pivot_element.row())
            {
                double pivot_oszl_elem=last->data(last->index(row,pivot_element.column(),QModelIndex())).toDouble();
                output->setData((output->index(row,pivot_element.column())),-1/(pivot)*(pivot_oszl_elem));
            }
        }
        for (int col=0;col<output->columnCount();++col)
        {
            if (col!=pivot_element.column())
            {

                  double pivot_oszl_elem=(last->data(last->index(pivot_element.row(),col))).toDouble();
                output->setData(output->index(pivot_element.row(),col),(pivot_oszl_elem)/(pivot));
            }
        }

        for (int row=0;row<last->rowCount();++row)
        {
            for (int col=0;col<last->columnCount();++col)
            {
                if (row !=pivot_element.row() && col != pivot_element.column())
                {
                    double regi=last->data(last->index(row,col)).toDouble();
                    double pivot_oszl_eredeti=last->data(last->index(row,pivot_element.column())).toDouble();
                    double d_j=output->data(output->index(pivot_element.row(),col)).toDouble();
                    output->setData(output->index(row, col,QModelIndex()),regi-((pivot_oszl_eredeti)*(d_j)));
                }
            }
        }




}
