#ifndef RESULT_REPORTER_DIALOG_H
#define RESULT_REPORTER_DIALOG_H
#include <QStandardItemModel>
#include <QString>
#include <QDialog>

namespace Ui {
class result_reporter_dialog;
}

class result_reporter_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit result_reporter_dialog(QStandardItemModel* indulo, QStandardItemModel* result, int lsz, QString pivot_modszer, QString vari_name, QWidget *parent = 0);
    ~result_reporter_dialog();

private slots:

    void on_result_reporter_dialog_finished(int result);

private:
    QStandardItemModel* indulo;
    QStandardItemModel* result;
    QStandardItemModel* eredmeny_indulo;
    QStandardItemModel* eredmeny_result;

    int lsz;
    QString pivot_modszer;
    QString vari_name;
    Ui::result_reporter_dialog *ui;
    void copy_model_from_to(QStandardItemModel *from, QStandardItemModel *to);
};

#endif // RESULT_REPORTER_DIALOG_H
