#-------------------------------------------------
#
# Project created by QtCreator 2018-03-31T15:41:40
#
#-------------------------------------------------

QT       += widgets

TARGET = fules
TEMPLATE = lib
CONFIG += plugin release no_plugin_name_prefix
DEFINES += FULES_LIBRARY
VERSION = 1.0.0

CONFIG(release, debug|release){
    win32: DESTDIR = ./release/lib
    win32: DLLDESTDIR = ../simplex_app/release/bin/plugins/gui_plugins
    unix: DESTDIR = ../simplex_app/release/bin/plugins/gui_plugins
    OBJECTS_DIR = ./release/obj
    MOC_DIR = ./release/moc
    RCC_DIR = ./release/rcc
    UI_DIR = ./release/ui
    plugi
}

CONFIG(debug, debug|release){
    win32: DESTDIR = ./debug/lib
    win32: DLLDESTDIR = ../simplex_app/debug/bin/plugins/gui_plugins
    unix: DESTDIR = ../simplex_app/debug/bin/plugins/exercise_load_plugins
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
    mainvindow_gui_plugin_for_fules.cpp \
    delegate_for_numbers_in_fules.cpp \
    non_numeric_delegate_in_fules.cpp

HEADERS += \
        #plugin_test.h \
        #plugin_test_global.h \
    mainwindow_gui_plugin_interface.h \
    mainvindow_gui_plugin_for_fules.h \
    delegate_for_numbers_in_fules.h \
    non_numeric_delegate_in_fules.h

unix {
    target.path = /usr/lib

}
win32 {
    target.path=../build-fules-Desktop_Qt_5_10_1_MSVC2015_32bit-Release
    INSTALLS += target
}
FORMS += \
    mainvindow_gui_plugin.ui

DISTFILES += \
    fules.json
