#-------------------------------------------------
#
# Project created by QtCreator 2018-04-14T12:57:38
#
#-------------------------------------------------

QT       += widgets

TARGET = Result_Reporter_minimal
TEMPLATE = lib
CONFIG += plugin release no_plugin_name_prefix
DEFINES += RESULT_REPORTER_MINIMAL_LIBRARY
VERSION = 1.0.0
CONFIG(release, debug|release){
    win32:DESTDIR = ./release/lib
    win32: DLLDESTDIR = ../simplex_app/release/bin/plugins/result_reporter_plugins
    unix: DESTDIR = ../simplex_app/release/bin/plugins/result_reporter_plugins
    OBJECTS_DIR = ./release/obj
    MOC_DIR = ./release/moc
    RCC_DIR = ./release/rcc
    UI_DIR = ./release/ui
}

CONFIG(debug, debug|release){
    win32: DESTDIR = ./debug/lib
    win32: DLLDESTDIR = ../simplex_app/debug/bin/plugins/result_reporter_plugins
    unix: DESTDIR = ../simplex_app/debug/bin/plugins/result_reporter_plugins
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
    result_reporter_minimal.cpp \
    result_reporter_dialog.cpp

HEADERS += \
    result_reporter_minimal.h \
    result_report_plugin_interface.h \
    result_reporter_dialog.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    result_reporter_dialog.ui

DISTFILES += \
    plugin.json
