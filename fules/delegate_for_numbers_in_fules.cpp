#include "delegate_for_numbers_in_fules.h"
#include <QDoubleSpinBox>

Delegate_for_numbers_in_fules::Delegate_for_numbers_in_fules(QObject *parent): QStyledItemDelegate(parent)
{

}
QWidget *Delegate_for_numbers_in_fules::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    auto *editor = new QDoubleSpinBox(parent);
    editor->setFrame(false);
    editor->setDecimals(3);
    editor->setMinimum(-9999999999);
    editor->setMaximum(9999999999);


    return editor;
}
//! [1]

//! [2]
void Delegate_for_numbers_in_fules::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    double value = index.model()->data(index, Qt::EditRole).toDouble();

    auto *spinBox = dynamic_cast<QDoubleSpinBox*>(editor);
    spinBox->setValue(value);
}
//! [2]

//! [3]
void Delegate_for_numbers_in_fules::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    auto *spinBox = dynamic_cast<QDoubleSpinBox*>(editor);
    spinBox->interpretText();
    double value = spinBox->value();

    model->setData(index, value, Qt::EditRole);
}
//! [3]

//! [4]
void Delegate_for_numbers_in_fules::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
//! [4]
