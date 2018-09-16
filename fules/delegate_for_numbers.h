#ifndef DELEGATE_FOR_NUMBERS_H
#define DELEGATE_FOR_NUMBERS_H
#include <QStyledItemDelegate>


class Delegate_for_numbers : public QStyledItemDelegate
{
    Q_OBJECT

public:
    Delegate_for_numbers(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const Q_DECL_OVERRIDE;

    void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const Q_DECL_OVERRIDE;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // DELEGATE_FOR_NUMBERS_H
