#ifndef EXCERCISE_LOAD_PLUGIN_INTERFACE_H
#define EXCERCISE_LOAD_PLUGIN_INTERFACE_H
#include <QString>
#include <QWidget>
#include <QStandardItemModel>

class Exercise_Load_Plugin_Interface
{
public:

    virtual void post_exercise(QStandardItemModel*)=0;
    virtual QString Name() const = 0;
signals:
    virtual void do_post_exercise(QStandardItemModel*)=0;

private:

public slots:

};
Q_DECLARE_INTERFACE(Exercise_Load_Plugin_Interface,"com.imaddes.simplex.exercise_load_plugin_interface/1.0.0")
#endif // EXCERCISE_LOAD_PLUGIN_INTERFACE_H
