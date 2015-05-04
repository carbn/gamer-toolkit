#-------------------------------------------------
#
# Project created by QtCreator 2015-04-28T18:07:56
#
#-------------------------------------------------

QT       += core gui dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gamer-toolkit
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
    mainwindow.cpp \
    nvidiasettings.cpp \
    bamfclient.cpp \
    gamertoolkit.cpp \
    gameconfiguration.cpp \
    basemodule.cpp \
    nvidiamodule.cpp \
    customcommandmodule.cpp

HEADERS  += mainwindow.h \
    nvidiasettings.h \
    bamfclient.h \
    nv-control-screen.h \
    gamertoolkit.h \
    gameconfiguration.h \
    basemodule.h \
    nvidiamodule.h \
    customcommandmodule.h

FORMS += mainwindow.ui

LIBS += -lXNVCtrl -lXext -lX11
