#ifndef COMBOBOXITEM_H
#define COMBOBOXITEM_H

#include <QObject>
#include <QString>
/**
 * @brief 
 *
 */
class ComboboxItem : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief 
     *
     * @param parent
     * @param int
     * @param int
     * @param int
     * @param 
     */
    explicit ComboboxItem(QObject *parent = nullptr, int=0, int=0, int=0, const QString& = "nincs");
    int id; /**< TODO: describe */
    int t; /**< TODO: describe */
    int k; /**< TODO: describe */
    QString m; /**< TODO: describe */
signals:

public slots:



};

#endif // COMBOBOXITEM_H
