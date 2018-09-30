#ifndef EXERCISE_LOAD_PLUGIN_H
#define EXERCISE_LOAD_PLUGIN_H

#include "excercise_load_plugin_interface.h"
#include <QDialog>
#include <QNetworkProxy>
#include <QString>
class Exercise_Load_Plugin: public QDialog, public Exercise_Load_Plugin_Interface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.imaddes.simplex.exercise_load_plugin_fron_db/1.0.0" FILE "exercise_load_plugin_interface.json")
    Q_INTERFACES(Exercise_Load_Plugin_Interface)
public:
    explicit Exercise_Load_Plugin(QWidget *parent = nullptr);

    void post_exercise(QStandardItemModel* exercise) Q_DECL_OVERRIDE;

signals:
   void do_post_exercise(QStandardItemModel* )  Q_DECL_FINAL;

public slots:
    void do_elfogadva(QStandardItemModel* exercise);

private:
    QString Name() const override;

    QStandardItemModel* exercise();

};

#endif // EXERCISE_LOAD_PLUGIN_H
