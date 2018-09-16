#pragma once

#include <QObject>
#include <QWidget>
#include <QStandardItemModel>
class pivoter : public QObject
{
    Q_OBJECT
public:
    pivoter(QObject *parent = nullptr);
    void do_pivot(QStandardItemModel* elotte, QStandardItemModel* output, QModelIndex pivot_element_);

private slots:
};


