#ifndef DB_LOADER_H
#define DB_LOADER_H
#include <QDialog>
#include <QStandardItemModel>
#include <QtNetwork>
#include <QUrl>

namespace Ui {
class Db_loader;
}

/**
 * @brief 
 *
 */
class Db_loader : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief 
     *
     * @param exercise
     * @param baseurl
     * @param parent
     */
    explicit Db_loader(QStandardItemModel *exercise,  QString const &baseurl, QWidget *parent = nullptr);
    /**
     * @brief 
     *
     */
    ~Db_loader();
signals:
/**
 * @brief 
 *
 * @param exercise
 */
void elfogadva(QStandardItemModel *exercise);
private slots:


    /**
     * @brief 
     *
     * @param arg1
     */
    void on_comboBox_activated(const QString &arg1);
    /**
     * @brief 
     *
     */
    void keszvan();
    /**
     * @brief 
     *
     */
    void keszvan_elem();

    /**
     * @brief 
     *
     */
    void on_buttonBox_accepted();


private:

    /**
     * @brief 
     *
     */
    void on_hibavan();
    Ui::Db_loader *ui; /**< TODO: describe */
    QStandardItemModel* exercise; /**< TODO: describe */
    QNetworkAccessManager* network_manager; /**< TODO: describe */
    QString baseurl; /**< TODO: describe */
    QNetworkRequest req; /**< TODO: describe */
    QNetworkReply* reply; /**< TODO: describe */
    QNetworkReply* reply2{}; /**< TODO: describe */

};

#endif // DB_LOADER_H
