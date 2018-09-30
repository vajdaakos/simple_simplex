#ifndef PIVOT_SELECTOR_BY_HAND_H
#define PIVOT_SELECTOR_BY_HAND_H
#include <QWidget>
#include <QtPlugin>
#include "pivot_selector_plugin_interface.h"

class Pivot_selector_by_hand :public QWidget, public Pivot_Selector_Plugin_Interface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.imaddes.Kezi_Pivot_Selector_Plugin/1.0.0" FILE "pivot_selector_by_hand.json")
    Q_INTERFACES(Pivot_Selector_Plugin_Interface)
public:
    Pivot_selector_by_hand();
    void pivot_element_wanted(QStandardItemModel* model) ;
signals:
    void post_pivot_element(QModelIndex) Q_DECL_FINAL;

public slots:
    void do_when_pivot_element_selected(QModelIndex pivotelement);

private:
    QString Name() const override;

};

#endif // PIVOT_SELECTOR_BY_HAND_H
