#ifndef PIVOT_SELECTOR_SORMAX_H
#define PIVOT_SELECTOR_SORMAX_H
#include <QObject>
#include <QtPlugin>
#include "pivot_selector_plugin_interface.h"

class Pivot_selector_sormax :public QObject, public Pivot_Selector_Plugin_Interface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.imaddes.Oszlopmax_Pivot_Selector_Plugin/1.0.0" FILE "pivot_selector_maxoszlop.json")
    Q_INTERFACES(Pivot_Selector_Plugin_Interface)
public:
    Pivot_selector_sormax();
    void pivot_element_wanted(QStandardItemModel* model) Q_DECL_OVERRIDE;

signals:
    void post_pivot_element(QModelIndex) Q_DECL_FINAL;

public slots:

private:
    QString Name() const override;
    int  select_max_from_row(int row,QStandardItemModel* model);

};

#endif // PIVOT_SELECTOR_SORMAX_H
