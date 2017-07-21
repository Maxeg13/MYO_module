#-------------------------------------------------
#
# Project created by QtCreator 2017-07-20T21:15:56
#
#-------------------------------------------------
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wtfMyo
TEMPLATE = app
#LIBS     += $$OUT_PWD/release/moc_datacollector1.o
LIBS     += $$OUT_PWD/release/datacollector.o
#LIBS += "C:\Users\123\Documents\build-wtfMyo-Desktop_Qt_5_7_1_MinGW_32bit-Release\release\datacollector.o"
LIBS     += -L$$PWD/myo/libmyo     -lmyo32
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    datacollector.h

FORMS    += mainwindow.ui
