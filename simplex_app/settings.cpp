#include "settings.h"
#include "ui_settings.h"
#include <QMessageBox>
Settings::Settings(QWidget *parent, int variable_index, QString variable_name) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    ui->variable_index->setValue(variable_index);
    ui->variable_name->setText(variable_name);
}
Settings::Settings(int variable_index, QString variable_name) :
       ui(new Ui::Settings)
{

    ui->setupUi(this);
    ui->variable_index->setValue(variable_index);

    ui->variable_name->setText(variable_name);
}
Settings::~Settings()
{
    delete ui;
}
void Settings::on_OK_Button_clicked()
{
    int varh=ui->variable_name->text().length();
    if (varh==0 || QString::compare(ui->variable_name->text().at(0),"*" )==0 || QString::compare(ui->variable_name->text(),"c" )==0 ||  QString::compare(ui->variable_name->text(),"Korl_" )==0 || QString::compare(ui->variable_name->text().at(0)," " )==0 || QString::compare(ui->variable_name->text().at(0),"v" )==0)
    {
       QMessageBox::warning(this,"Beviteli hiba!","Hibás változónév! A változó neve nem kezdődhet csillaggal (*), v-vel vagy whitespace-el, nem lehet \"c\" vagy \"Korl_\" és nem lehet üres! ");
    }
    else {
        emit settings_changed(ui->variable_index->value(), ui->variable_name->text());
        this->accept();
    }
}

void Settings::on_Cancel_clicked()
{
    this->reject();
}
