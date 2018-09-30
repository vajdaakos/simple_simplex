#include "comboboxitem.h"
#include <utility>
ComboboxItem::ComboboxItem(QObject *parent, int id, int termteny, int korlfelt, const QString& megjegyzes) : QObject(parent)
{
    this->id=id;
    this->t=termteny;
    this->k=korlfelt;
    this->m=megjegyzes;
}
