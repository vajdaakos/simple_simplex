#pragma once

#include <QDialog>

namespace Ui {
class Nevjegy;
}

class Nevjegy : public QDialog
{
    Q_OBJECT

public:
    explicit Nevjegy(QWidget *parent = nullptr);
    ~Nevjegy();

private:
    Ui::Nevjegy *ui;
    QPixmap pic1;
};


