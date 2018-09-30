#include "non_numeric_delegate_in_fules.h"
#include <QComboBox>
#include <QWidget>
#include <QModelIndex>
#include <QString>
Non_numeric_Delegate_in_fules::Non_numeric_Delegate_in_fules(QObject *parent) : QItemDelegate(parent)
{

}

QWidget *Non_numeric_Delegate_in_fules::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.row()==0)
    {
        auto *editor = new QComboBox(parent);
        editor->addItem("max");
        editor->addItem("min");

        return editor;
    }
    else
    {
    auto *editor = new QComboBox(parent);
    editor->addItem("=>");
    editor->addItem("<=");
    editor->addItem("=");
    return editor;
    }
}
void Non_numeric_Delegate_in_fules::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    auto *comboBox = dynamic_cast<QComboBox*>(editor);
      int value = index.model()->data(index, Qt::EditRole).toUInt();
      comboBox->setCurrentIndex(value);
}
void Non_numeric_Delegate_in_fules::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
auto *combobox = dynamic_cast<QComboBox*>(editor);
    QString value = combobox->currentText();
    model->setData(index,value,Qt::EditRole);


}
void Non_numeric_Delegate_in_fules::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
