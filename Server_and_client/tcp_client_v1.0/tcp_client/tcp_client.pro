#-------------------------------------------------
#
# Project created by QtCreator 2020-03-07T05:25:48
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcp_client
TEMPLATE = app


SOURCES += main.cpp\
        client_widget.cpp

HEADERS  += client_widget.h

FORMS    += client_widget.ui

CONFIG   += C++11
