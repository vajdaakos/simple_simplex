#pragma once
#include "simplex_method_calculator.h"
#include <QObject>
class StartApp :QObject
{
    Q_OBJECT
public:
    StartApp();
    int start_App(int argc, char *argv[]);


};


