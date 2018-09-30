#ifndef COMBOBOXITEM_H
#define COMBOBOXITEM_H

#include <QObject>
#include <QString>
class ComboboxItem : public QObject
{
    Q_OBJECT
public:
    explicit ComboboxItem(QObject *parent = nullptr, int=0, int=0, int=0, const QString& = "nincs");
    int id;
    int t;
    int k;
    QString m;
signals:

public slots:



};

#endif // COMBOBOXITEM_H
