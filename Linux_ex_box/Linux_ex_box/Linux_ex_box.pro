#-------------------------------------------------
#
# Project created by QtCreator 2020-10-24T21:02:33
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Linux_ex_box
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


SOURCES += \
        main.cpp \
        mymainwindow.cpp

HEADERS += \
        mymainwindow.h

FORMS += \
        mymainwindow.ui

LIBS += /home/ts/opencv-3.4.12/x64_out/lib/libopencv_world.so.3.4.12 \
        /usr/local/lib/libavcodec.so.58.54.100 \
        /usr/local/lib/libavdevice.so.58.8.100 \
        /usr/local/lib/libavfilter.so.7.57.100 \
        /usr/local/lib/libavformat.so.58.29.100 \
        /usr/local/lib/libavutil.so.56.31.100 \
        /usr/local/lib/libswresample.so.3.5.100 \
        /usr/local/lib/libswscale.so.5.5.100

INCLUDEPATH += /home/ts/opencv-3.4.12/x64_out/include \
               /home/ts/opencv-3.4.12/x64_out/include/opencv \
               /home/ts/opencv-3.4.12/x64_out/include/opencv2 \



CONFIG += c++11
