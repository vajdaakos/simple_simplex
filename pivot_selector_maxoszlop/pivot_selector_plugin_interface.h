#ifndef PIVOT_SELECTOR_PLUGIN_INTERFACE_H
#define PIVOT_SELECTOR_PLUGIN_INTERFACE_H
#include <QString>
#include <QWidget>
#include <QStandardItemModel>

class Pivot_Selector_Plugin_Interface
{
public:
    virtual QString Name() const = 0;

    virtual void pivot_element_wanted(QStandardItemModel*)=0;
signals:
    virtual void post_pivot_element(QModelIndex)=0;


public slots:

};
Q_DECLARE_INTERFACE(Pivot_Selector_Plugin_Interface,"com.imaddes.simplex.pivot_selector_plugin_interface/1.0.0")
#endif // PIVOT_SELECTOR_PLUGIN_INTERFACE_H
