#-------------------------------------------------
#
# Project created by QtCreator 2016-11-14T20:38:32
#
#-------------------------------------------------

QT       += core gui
QT      += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DebugHelper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpserver.cpp \
    tcpsocket.cpp

HEADERS  += mainwindow.h \
    tcpserver.h \
    tcpsocket.h

FORMS    += mainwindow.ui

