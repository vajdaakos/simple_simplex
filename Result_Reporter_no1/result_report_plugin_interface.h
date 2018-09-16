#ifndef RESULT_REPORT_PLUGIN_INTERFACE_H
#define RESULT_REPORT_PLUGIN_INTERFACE_H
#include <QString>
#include <QDialog>
#include <QStandardItemModel>
class Result_Report_Plugin_Interface
{
public:
    virtual QString Name() const = 0;

    virtual void show_result_report(QStandardItemModel *indulo, QStandardItemModel *result, int lsz, QString pivot_modszer, QString vari_name,QWidget *parent)=0;
signals:
    //virtual void post_pivot_element(QModelIndex)=0;


public slots:

};
Q_DECLARE_INTERFACE(Result_Report_Plugin_Interface,"com.imaddes.simplex.result_report_plugin_interface/1.0.0")
#endif // RESULT_REPORT_PLUGIN_INTERFACE_H
