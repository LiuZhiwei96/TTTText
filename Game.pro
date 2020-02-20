#-------------------------------------------------
#
# Project created by QtCreator 2019-08-05T14:35:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mypushbutton.cpp \
    chooselevelwindow.cpp \
    gamesense.cpp \
    dataconfig.cpp \
    gamebutton.cpp

HEADERS  += mainwindow.h \
    mypushbutton.h \
    chooselevelwindow.h \
    gamesense.h \
    dataconfig.h \
    gamebutton.h

FORMS    += mainwindow.ui \
    chooselevelwindow.ui \
    gamesense.ui

RESOURCES += \
    res.qrc
