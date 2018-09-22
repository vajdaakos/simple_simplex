#include "exercise_load_plugin.h"
#include "db_loader.h"

Exercise_Load_Plugin::Exercise_Load_Plugin(QWidget *parent) :QDialog(parent)
{

}

QString Exercise_Load_Plugin::Name() const
{
    return "DUE Feladatbank";
}

void Exercise_Load_Plugin::post_exercise(QStandardItemModel* exercise)
{

    Db_loader db_loader_dialog_window(exercise,"http://server.realm/restapi.php/",this);

    connect(&db_loader_dialog_window,SIGNAL(elfogadva(QStandardItemModel *)),this,SLOT(do_elfogadva(QStandardItemModel*)));

    db_loader_dialog_window.setModal(true);
    db_loader_dialog_window.exec();
}
void Exercise_Load_Plugin::do_elfogadva(QStandardItemModel* exercise)
{
    emit do_post_exercise(exercise);
}
