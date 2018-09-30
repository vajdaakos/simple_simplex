#pragma once
#include <QWidget>
#include <QObject>
#include <QItemDelegate>
#include <QModelIndex>
#include <QSize>
#include <QComboBox>

class QModelIndex;
class QWidget;
class QVariant;

class Non_numeric_Delegate_in_fules: public QItemDelegate
{
    Q_OBJECT
public:
    Non_numeric_Delegate_in_fules(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};

