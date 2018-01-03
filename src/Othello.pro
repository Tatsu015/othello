#-------------------------------------------------
#
# Project created by QtCreator 2018-01-02T00:00:46
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXX = $$system(which ccache) g++

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Othello
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    model/tool \
    model \
    view/window \
    viewmodel/item \
    viewmodel/scene


SOURCES += \
    model/tool/Board.cpp \
    model/tool/Cell.cpp \
    model/Game.cpp \
    model/Turn.cpp \
    view/window/MainWindow.cpp \
    viewmodel/item/CellItem.cpp \
    viewmodel/item/StoneItem.cpp \
    viewmodel/scene/Scene.cpp \
    main.cpp

HEADERS += \
    model/tool/Board.h \
    model/tool/Cell.h \
    model/Game.h \
    model/Turn.h \
    view/window/MainWindow.h \
    viewmodel/item/CellItem.h \
    viewmodel/item/StoneItem.h \
    viewmodel/scene/Scene.h \
    Common.h

FORMS += \
    view/window/MainWindow.ui

