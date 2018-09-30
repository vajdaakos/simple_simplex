#include "nevjegy.h"
#include "ui_nevjegy.h"
#include <QDebug>
Nevjegy::Nevjegy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nevjegy)
{
    ui->setupUi(this);
    pic1.load(":/Icon/simplex_icon");
    this->ui->label->setPixmap(pic1.scaled(96,96,Qt::KeepAspectRatio));
    ui->email->setTextInteractionFlags(Qt::TextSelectableByMouse);
    this->setFixedSize(320,200);


}

Nevjegy::~Nevjegy()
{
    delete ui;
}
