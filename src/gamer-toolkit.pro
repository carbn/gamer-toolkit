#-------------------------------------------------
#
# Project created by QtCreator 2015-04-28T18:07:56
#
#-------------------------------------------------

QT       += core gui dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gamer-toolkit
TEMPLATE = app

SOURCES += main.cpp\
    mainwindow.cpp \
    nvidiasettings.cpp \
    bamfclient.cpp \
    windowmonitor.cpp

HEADERS  += mainwindow.h \
    nvidiasettings.h \
    bamfclient.h \
    windowmonitor.h \
    nv-control-screen.h

FORMS += mainwindow.ui

LIBS += -lXNVCtrl -lXext -lX11
