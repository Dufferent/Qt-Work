#-------------------------------------------------
#
# Project created by QtCreator 2020-03-06T04:30:46
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcp_server_v1-0
TEMPLATE = app


SOURCES += main.cpp\
        server_widget.cpp

HEADERS  += server_widget.h

FORMS    += server_widget.ui

CONFIG   += C++11
