#include "pivot_selector_by_hand.h"
#include  "pivot_selector_by_hand_dialog.h"
#include <QDebug>

Pivot_selector_by_hand::Pivot_selector_by_hand()
{
}
QString Pivot_selector_by_hand::Name() const
{
    return "Kézi";
}


void Pivot_selector_by_hand::pivot_element_wanted(QStandardItemModel* model)
{

    Pivot_Selector_By_Hand_Dialog pivot_select_dialog(model,this);
    pivot_select_dialog.setModal(true);
    connect(&pivot_select_dialog,SIGNAL(pivot_selected(QModelIndex)),this,SLOT(do_when_pivot_element_selected(QModelIndex)));
    pivot_select_dialog.exec();

    }
void Pivot_selector_by_hand::do_when_pivot_element_selected(QModelIndex pivotelement)
{
    emit post_pivot_element(pivotelement);
}

