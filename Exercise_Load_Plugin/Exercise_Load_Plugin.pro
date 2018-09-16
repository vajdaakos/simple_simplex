#-------------------------------------------------
#
# Project created by QtCreator 2018-04-26T20:45:25
#
#-------------------------------------------------

QT       += widgets network

TARGET = Exercise_Load_Plugin_default
TEMPLATE = lib

DEFINES += EXERCISE_LOAD_PLUGIN_LIBRARY
VERSION = 1.0.0
CONFIG(release, debug|release){
    DESTDIR = ./release/lib
    win32: DLLDESTDIR = ../simplex_app/release/bin/plugins/exercise_load_plugins
    OBJECTS_DIR = ./release/obj
    MOC_DIR = ./release/moc
    RCC_DIR = ./release/rcc
    UI_DIR = ./release/ui
}

CONFIG(debug, debug|release){
    DESTDIR = ./debug/lib
    win32: DLLDESTDIR = ../simplex_app/debug/bin/plugins/exercise_load_plugins
    OBJECTS_DIR = debug/obj
    MOC_DIR = debug/moc
    RCC_DIR = debug/rcc
    UI_DIR = debug/ui
}
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
        exercise_load_plugin.cpp \
    db_loader.cpp \
    comboboxitem.cpp

HEADERS += \
        exercise_load_plugin.h \
    excercise_load_plugin_interface.h \
    db_loader.h \
    comboboxitem.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    exercise_load_plugin_interface.json

FORMS += \
    db_loader.ui

RESOURCES += \
    exercise_load_plugin_resources.qrc
unix {
    target.path = /usr/lib
    INSTALLS += target
}

