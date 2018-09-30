#-------------------------------------------------
#
# Project created by QtCreator 2018-05-05T22:50:47
#
#-------------------------------------------------

QT       += widgets

QT       -= gui
CONFIG += plugin release no_plugin_name_prefix
TARGET = picture_loader_default
TEMPLATE = lib
CONFIG(release, debug|release){
    win32: DESTDIR = ./release/lib
    win32: DLLDESTDIR = ../simplex_app/release/bin/plugins/picture_load_plugins
    unix: DESTDIR = ../simplex_app/release/bin/plugins/picture_load_plugins
    OBJECTS_DIR = ./release/obj
    MOC_DIR = ./release/moc
    RCC_DIR = ./release/rcc
    UI_DIR = ./release/ui
}

CONFIG(debug, debug|release){
    win32: DESTDIR = ./debug/lib
    win32: DLLDESTDIR = ../simplex_app/debug/bin/plugins/picture_load_plugins
    unix: DESTDIR = ../simplex_app/debug/bin/plugins/picture_load_plugins
    OBJECTS_DIR = debug/obj
    MOC_DIR = debug/moc
    RCC_DIR = debug/rcc
    UI_DIR = debug/ui
}
DEFINES += PICTURE_LOADER_LIBRARY

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
        picture_loader.cpp \
    picture_loader_dialog.cpp

HEADERS += \
        picture_loader.h \
    picture_load_plugin_interface.h \
    picture_loader_dialog.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    picture_loader.json

FORMS += \
    picture_loader_dialog.ui

RESOURCES += \
    img.qrc
