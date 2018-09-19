#ifndef PIVOT_SELECTOR_BY_HAND_DIALOG_H
#define PIVOT_SELECTOR_BY_HAND_DIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include "pivot_selector_by_hand.h"
namespace Ui {
class Pivot_Selector_By_Hand_Dialog;
}

class Pivot_Selector_By_Hand_Dialog : public QDialog
{
    Q_OBJECT
signals:
    void pivot_selected(QModelIndex pivotelem);
public:
    explicit Pivot_Selector_By_Hand_Dialog(QStandardItemModel* model, QWidget *parent = nullptr);
    ~Pivot_Selector_By_Hand_Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Pivot_Selector_By_Hand_Dialog *ui;
};

#endif // PIVOT_SELECTOR_BY_HAND_DIALOG_H
