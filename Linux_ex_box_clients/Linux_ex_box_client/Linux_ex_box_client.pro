#-------------------------------------------------
#
# Project created by QtCreator 2020-10-26T22:49:13
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Linux_ex_box_client
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp

HEADERS  += mywidget.h

FORMS    += mywidget.ui

CONFIG += c++11

INCLUDEPATH += /home/ts/opencv-3.4.12/x64_out/include \
               /home/ts/opencv-3.4.12/x64_out/include/opencv \
               /home/ts/opencv-3.4.12/x64_out/include/opencv2 \

LIBS += /home/ts/opencv-3.4.12/x64_out/lib/libopencv_world.so.3.4.12

