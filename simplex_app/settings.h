#pragma once

#include <simplex_method_calculator.h>
#include <QDialog>
#include <QString>
namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0, int variable_index=0, const QString &variable_name="x");
    explicit Settings(int variable_index=0, const QString &variable_name="x");

    QString get_variable_name();
    ~Settings();
signals:
    void settings_changed(int variable_index,QString variable_name);
private slots:


    void on_OK_Button_clicked();

    void on_Cancel_clicked();

private:
    Ui::Settings *ui;
};


