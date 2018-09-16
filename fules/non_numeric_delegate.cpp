#include "non_numeric_delegate.h"
#include <QComboBox>
#include <QWidget>
#include <QModelIndex>
#include <QString>
Non_numeric_Delegate::Non_numeric_Delegate(QObject *parent) : QItemDelegate(parent)
{

}

QWidget *Non_numeric_Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.row()==0)
    {
        QComboBox *editor = new QComboBox(parent);
        editor->addItem("max");
        editor->addItem("min");

        return editor;
    }
    else
    {
    QComboBox *editor = new QComboBox(parent);
    editor->addItem("=>");
    editor->addItem("<=");
    editor->addItem("=");
    return editor;
    }
}
void Non_numeric_Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
      int value = index.model()->data(index, Qt::EditRole).toUInt();
      comboBox->setCurrentIndex(value);
}
void Non_numeric_Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
QComboBox *combobox = static_cast<QComboBox*>(editor);
    QString value = combobox->currentText();
    model->setData(index,value,Qt::EditRole);


}
void Non_numeric_Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
