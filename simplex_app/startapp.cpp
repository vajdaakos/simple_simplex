#include "startapp.h"
#include <QApplication>
#include <QDir>


/**
 * @brief Starts the applicaton
 * @details Practically this method starts the application <br><br>
 * This method
 * - creates the QApplication
 * - instansize a QDir, whitc is the abbsolute path of the application. Used to generate the plugins dir
 * - instansize a Simplex_method_calculator, which is the main class of the application
 *
 * @return Enters the main event loop and waits until exit() is called, then returns the value that was set to exit() (which is 0 if exit() is called via quit()). It is necessary to call this function to start event handling. The main event loop receives events from the window system and dispatches these to the application widgets.
 */
int StartApp::start_Application()
{
    int argc=0;
    char* argv[] {nullptr};
    QApplication qapp(argc, argv);
    root_dir= QDir(qApp->applicationDirPath());
    simplex_method_calculator=new Simplex_method_calculator();
    simplex_method_calculator->start(root_dir);
    return qapp.exec();
}
