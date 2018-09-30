#pragma once
#include "result_report_plugin_interface.h"
#include <QDialog>





class Result_Reporter_Minimal : public QDialog, public Result_Report_Plugin_Interface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.imaddes.Default_Result_Reporter_plugin/1.0.0" FILE "plugin.json")
    Q_INTERFACES(Result_Report_Plugin_Interface)

public:
    explicit Result_Reporter_Minimal(QWidget *parent = nullptr);
    QString Name() const override;

    void show_result_report(QStandardItemModel* indulo, QStandardItemModel* result, int lsz, QString pivot_modszer, QString vari_name, QWidget *parent = nullptr) Q_DECL_OVERRIDE;

public slots:

private:

    void copy_model_from_to(QStandardItemModel *from, QStandardItemModel *to);
    QStandardItemModel* indulo;
    QStandardItemModel* result;
};
