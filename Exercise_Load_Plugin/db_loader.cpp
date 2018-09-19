#include "db_loader.h"
#include "ui_db_loader.h"
#include "exercise_load_plugin.h"
#include <QtNetwork>
#include <QUrl>
#include <QJsonDocument>
#include <QMessageBox>
#include "comboboxitem.h"
#include <QSharedDataPointer>
#include <QStringRef>
#include <QPushButton>
Db_loader::Db_loader(QStandardItemModel* exercise, QString const &baseurl="http://web-okt.duf.hu/opkut.php/", QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Db_loader)
{



    this->exercise=exercise;
    this->exercise->clear();
    network_manager= new QNetworkAccessManager(this);
    ui->setupUi(this);
    ui->comboBox->addItem("Várakozás az adatokra... ",-1);
    QUrl url(baseurl + "feladat");
    this->baseurl=baseurl;
    req=QNetworkRequest(url);
    this->req.setRawHeader(QByteArray("User-Agent"),QByteArray("Mozilla/5.0 (Windows NT 10.0; WOW64; rv:56.0) Gecko/20100101 Firefox/56.0"));
    reply = network_manager->get(req);
    ui->betekint->setModel(this->exercise);
    connect(this->reply,SIGNAL(finished()),this,SLOT(keszvan()));
    ui->comboBox->setEnabled(false);
    ui->URL->setText(baseurl);
    QPushButton* b = ui->buttonBox->button(QDialogButtonBox::Cancel);
    b->setText(tr("&Mégse"));
    ui->URL->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->betekint->setEditTriggers(QAbstractItemView::NoEditTriggers);


}

Db_loader::~Db_loader()
{
    delete ui;
}

void Db_loader::on_comboBox_activated(const QString &arg1)
{

    ui->label->setText(ui->comboBox->currentData().value<QSharedPointer<ComboboxItem>>()->m);
    QUrl url2(this->baseurl + "elem?filter=FID,eq," + QString::number(ui->comboBox->currentData().value<QSharedPointer<ComboboxItem>>()->id));
    req=QNetworkRequest(url2);

    this->req.setRawHeader(QByteArray("User-Agent"),QByteArray("Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US) AppleWebKit/534.10 (KHTML, like Gecko) Chrome/7.0.540.0 Safari/534.10"));
    reply2 = network_manager->get(req);
    connect(this->reply2,SIGNAL(finished()),this,SLOT(keszvan_elem()));
}

void Db_loader::keszvan()
{
    ui->comboBox->setEnabled(true);

    QJsonDocument doc=QJsonDocument::fromJson(this->reply->readAll());
    if ( reply->error() != QNetworkReply::NoError ) {
        qWarning() <<"ErrorNo: "<< reply->error() << " for url: " << reply->url().toString();

        on_hibavan();
        return;
    }
    if(!doc.isNull()){

        ui->comboBox->clear();
        ComboboxItem* item_0=new ComboboxItem(this,0,0,0,"Válassz feladatot!");
        QSharedPointer<ComboboxItem> elem_0(item_0);
        QVariant var_0=QVariant::fromValue(elem_0);
        ui->comboBox->addItem("Válassz betöltendő feladatot! ",var_0);
        ui->label->setText("Válassz feladatot!");

        for(int i=0;i<doc.object()["feladat"].toObject()["records"].toArray().count();++i)
        {
            ComboboxItem* item=new ComboboxItem(this,doc.object()["feladat"].toObject()["records"].toArray()[i].toArray()[0].toInt(),doc.object()["feladat"].toObject()["records"].toArray()[i].toArray()[3].toInt(),doc.object()["feladat"].toObject()["records"].toArray()[i].toArray()[4].toInt(),doc.object()["feladat"].toObject()["records"].toArray()[i].toArray()[5].toString());
            QSharedPointer<ComboboxItem> elem(item);
            QVariant var=QVariant::fromValue(elem);

            ui->comboBox->addItem("ID: "+QString::number(doc.object()["feladat"].toObject()["records"].toArray()[i].toArray()[0].toInt()) + ", fejezet: " + QString::number(doc.object()["feladat"].toObject()["records"].toArray()[i].toArray()[1].toDouble()) +
                    ", feladat: " + QString::number(doc.object()["feladat"].toObject()["records"].toArray()[i].toArray()[2].toDouble()) + ", |Pr|: " + QString::number(doc.object()["feladat"].toObject()["records"].toArray()[i].toArray()[3].toDouble()) +
                    ", |Korl|: " + QString::number(doc.object()["feladat"].toObject()["records"].toArray()[i].toArray()[4].toDouble()),var);


        }
    }
}

void Db_loader::on_hibavan(){

    QMessageBox::critical(this,"Hálózati hiba!","ErrorNo: " + QString::number(reply->error()) + " for url: " + ui->url_label->text()+ "<br>Request failed, " + reply->errorString());
    ui->comboBox->setEnabled(false);

}

void Db_loader::keszvan_elem()
{

    QJsonDocument doc=QJsonDocument::fromJson(this->reply2->readAll());
    if ( reply2->error() != QNetworkReply::NoError ) {
        qWarning() <<"ErrorNo: "<< reply2->error() << " for url: " << reply2->url().toString();

        on_hibavan();
        return;
    }
    if(!doc.isNull()){
        if(doc.object()["elem"].toObject()["records"].toArray().count()>0){
            this->exercise->clear();
            this->exercise->setColumnCount((ui->comboBox->currentData().value<QSharedPointer<ComboboxItem>>()->t)+2);
            this->exercise->setRowCount((ui->comboBox->currentData().value<QSharedPointer<ComboboxItem>>()->k)+1);
            for(int i=0;i<doc.object()["elem"].toObject()["records"].toArray().count();++i)
            {
                QJsonArray jsonArray=doc.object()["elem"].toObject()["records"].toArray()[i].toArray();
                int row=jsonArray[2].toInt();
                int col=jsonArray[3].toInt();
                QModelIndex index=this->exercise->index(row,col);
                if(col==(ui->comboBox->currentData().value<QSharedPointer<ComboboxItem>>()->t)){
                    QString value=jsonArray[4].toString();
                    this->exercise->setData(index,value);
                }
                else
                {
                    QString svalue=jsonArray[4].toString();
                    double value=svalue.toDouble();
                    this->exercise->setData(index,value);
                }
            }

        }
        else{
            return;
        }
    }

}

void Db_loader::on_buttonBox_accepted()
{
    if(this->ui->comboBox->currentIndex()!=0){

    emit elfogadva(exercise);
    }

}


