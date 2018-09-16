#ifndef DB_LOADER_H
#define DB_LOADER_H
#include <QDialog>
#include <QStandardItemModel>
#include <QtNetwork>
#include <QUrl>

namespace Ui {
class Db_loader;
}

class Db_loader : public QDialog
{
    Q_OBJECT

public:
    explicit Db_loader(QStandardItemModel *exercise, QString baseurl, QWidget *parent = 0);
    ~Db_loader();
signals:
void elfogadva(QStandardItemModel *exercise);
private slots:


    void on_comboBox_activated(const QString &arg1);
    void keszvan();
    void keszvan_elem();

    void on_buttonBox_accepted();


private:

    void on_hibavan();
    Ui::Db_loader *ui;
    QStandardItemModel* exercise;
    QNetworkAccessManager* network_manager;
    QString baseurl;
    QNetworkRequest req;
    QNetworkReply* reply;
    QNetworkReply* reply2;

};

#endif // DB_LOADER_H
