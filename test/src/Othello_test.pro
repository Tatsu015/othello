#-------------------------------------------------
#
# Project created by QtCreator 2018-01-02T00:00:46
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXX = $$system(which ccache) g++

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
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

# google test setting
INCLUDEPATH += /usr/include
DEPENDPATH += /usr/include

LIBS += -L/usr/lib/ -lgtest
LIBS += -L/usr/lib/ -lgtest_main

# production code
INCLUDEPATH += \
    ../../src \
    ../../src/model/tool \
    ../../src/model \
    ../../src/view/window \
    ../../src/viewmodel/item \
    ../../src/viewmodel/scene

SOURCES += \
    ../../src/model/tool/Board.cpp \
    ../../src/model/tool/Cell.cpp \
    ../../src/model/Game.cpp \
    ../../src/model/Turn.cpp \
    ../../src/viewmodel/item/CellItem.cpp \
    ../../src/viewmodel/item/StoneItem.cpp \
    ../../src/viewmodel/scene/Scene.cpp \

HEADERS += \
    ../../src/model/tool/Board.h \
    ../../src/model/tool/Cell.h \
    ../../src/model/Game.h \
    ../../src/model/Turn.h \
    ../../src/viewmodel/item/CellItem.h \
    ../../src/viewmodel/item/StoneItem.h \
    ../../src/viewmodel/scene/Scene.h \
    ../../src/Common.h

# test code
SOURCES += \
    model/tool/Board_test.cpp \
    main.cpp \


