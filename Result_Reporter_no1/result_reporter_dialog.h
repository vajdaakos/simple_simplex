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
    explicit result_reporter_dialog(QStandardItemModel* indulo, QStandardItemModel* result, int lsz, const QString& pivot_modszer, const QString &vari_name, QWidget *parent = nullptr);
    ~result_reporter_dialog();

private slots:

    void on_result_reporter_dialog_finished();

private:
    QStandardItemModel* indulo;
    QStandardItemModel* result;
    QStandardItemModel* eredmeny_indulo;
    QStandardItemModel* eredmeny_result;
//    bool megengedett;
    bool is_megengedett();
//    bool optimalis;
    bool is_optimalis();
//    bool degeneralt;
    bool is_degeneralt();
    bool is_alternative();
    bool is_kesz();
    //bool x_marad;
    bool x_marad();
    //bool v_marad;
    bool v_marad();
    int lsz;
    QString pivot_modszer;
    QString vari_name;
    Ui::result_reporter_dialog *ui;
    void copy_model_from_to(QStandardItemModel *from, QStandardItemModel *to);
};

#endif // RESULT_REPORTER_DIALOG_H
