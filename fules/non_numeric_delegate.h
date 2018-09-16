#ifndef NON_NUMERIC_DELEGATE_H
#define NON_NUMERIC_DELEGATE_H
#include <QWidget>
#include <QObject>
#include <QItemDelegate>
#include <QModelIndex>
#include <QSize>
#include <QComboBox>

class QModelIndex;
class QWidget;
class QVariant;

class Non_numeric_Delegate: public QItemDelegate
{
    Q_OBJECT
public:
    Non_numeric_Delegate(QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};

#endif // NON_NUMERIC_DELEGATE_H
