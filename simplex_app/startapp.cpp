#include "startapp.h"
#include <QApplication>
#include <QDir>
StartApp::StartApp()=default;
int StartApp::start_App(int argc, char* argv[])
{
    QApplication qapp(argc, argv);
    QDir plugins_dir(qApp->applicationDirPath());
    auto *simplex_method_calculator=new Simplex_method_calculator();
    simplex_method_calculator->start(argc, argv,plugins_dir);
    return qapp.exec();
}
