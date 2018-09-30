#ifndef PICTURE_LOADER_DIALOG_H
#define PICTURE_LOADER_DIALOG_H
#include <QPixmap>
#include <QDialog>

namespace Ui {
class picture_loader_dialog;
}

class picture_loader_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit picture_loader_dialog(QWidget *parent = 0);
    ~picture_loader_dialog();

private:
    Ui::picture_loader_dialog *ui;
    QPixmap pic1;
    QPixmap pic2;
};

#endif // PICTURE_LOADER_DIALOG_H
