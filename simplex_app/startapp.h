#pragma once
#include "simplex_method_calculator.h"
#include <QObject>
/**
 * @brief Starter class of applicaton
 * @details A QApplication cannot be created in main(), because it has to inherite from QObject.
 *
 */
class StartApp :QObject
{
    Q_OBJECT
public:


    int start_Application();

private:

    Simplex_method_calculator *simplex_method_calculator; /**< A pointer to the main class of the application */
    QDir root_dir; /**< The directory from which the application was started */


};


