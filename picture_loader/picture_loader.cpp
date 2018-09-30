#include "picture_loader.h"


Picture_Loader::Picture_Loader()=default;
QString Picture_Loader::Name() const
{

    return "Elmélet";
}

void Picture_Loader::show_picture(QMainWindow *w)
{
    auto *dialog=new picture_loader_dialog(w);
    dialog->setModal(false);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();


}
