#include "comboboxitem.h"

ComboboxItem::ComboboxItem(QObject *parent, int id, int termteny, int korlfelt, QString megjegyzes) : QObject(parent)
{
    this->id=id;
    this->t=termteny;
    this->k=korlfelt;
    this->m=megjegyzes;
}
