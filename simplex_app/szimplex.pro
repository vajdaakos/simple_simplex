#-------------------------------------------------
#
# Project created by QtCreator 2018-03-30T08:15:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#QMAKE_LFLAGS += -no-pie
TARGET = szimplex
TEMPLATE = app
RC_ICONS = simplex.ico
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    simplex_method_calculator.cpp \
    pivoter.cpp \
    startapp.cpp \
    gui_plugin_loader.cpp \
    settings.cpp \
    pivot_selector_plugin_loader.cpp \
    result_report_plugin_loader.cpp \
    exercise_load_plugin_loader.cpp \
    picture_load_plugin_loader.cpp \
    nevjegy.cpp \
    delegate_for_numbers.cpp \
    non_numeric_delegate.cpp

HEADERS += \
        mainwindow.h \
    simplex_method_calculator.h \
    pivoter.h \
    startapp.h \
    mainwindow_gui_plugin_interface.h \
    gui_plugin_loader.h \
    settings.h \
    pivot_selector_plugin_interface.h \
    pivot_selector_plugin_loader.h \
    result_report_plugin_interface.h \
    result_report_plugin_loader.h \
    excercise_load_plugin_interface.h \
    exercise_load_plugin_loader.h \
    picture_load_plugin_interface.h \
    picture_load_plugin_loader.h \
    nevjegy.h \
    delegate_for_numbers.h \
    non_numeric_delegate.h

FORMS += \
        mainwindow.ui \
    settings.ui \
    nevjegy.ui

RESOURCES += \
    szimplex_resources.qrc
