#ifndef PIVOT_SELECTOR_MINMAX_H
#define PIVOT_SELECTOR_MINMAX_H
#include <QObject>
#include <QtPlugin>
#include "pivot_selector_plugin_interface.h"

class Pivot_selector_minmax :public QObject, public Pivot_Selector_Plugin_Interface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.imaddes.Default_Pivot_Selector_Plugin/1.0.0" FILE "pivot_selector_minmax.json")
    Q_INTERFACES(Pivot_Selector_Plugin_Interface)
public:
    Pivot_selector_minmax();
    void pivot_element_wanted(QStandardItemModel* model) Q_DECL_OVERRIDE;

signals:
    void post_pivot_element(QModelIndex) Q_DECL_FINAL;

public slots:

private:
    QString Name() const override;

};

#endif // PIVOT_SELECTOR_MINMAX_H
