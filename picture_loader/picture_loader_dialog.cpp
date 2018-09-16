#include "picture_loader_dialog.h"
#include "ui_picture_loader_dialog.h"

picture_loader_dialog::picture_loader_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::picture_loader_dialog)
{
    ui->setupUi(this);

    pic1.load(":/Images/img/egyfazisu.jpg");
    ui->label->setPixmap(pic1);
    pic2.load(":/Images/img/pivotalas.png");
    ui->label_2->setPixmap(pic2);
}

picture_loader_dialog::~picture_loader_dialog()
{
    delete ui;
}
