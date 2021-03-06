#-------------------------------------------------
#
# Project created by QtCreator 2014-09-30T21:54:11
#
#-------------------------------------------------

QT       += core gui
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = FastMacro
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    commandline.cpp \
    addingdialog.cpp \
    macrosfactory.cpp \
    macros.cpp \
    command.cpp \
    controller.cpp \
    sender.cpp \
    currentmacrosesdialog.cpp \
    keypressfilter.cpp \
    macrosdatacontroller.cpp \
    macrosoutputholder.cpp \
    keysetconverter.cpp

HEADERS  += mainwindow.h \
    commandline.h \
    keypressfilter.h \
    addingdialog.h \
    macrosfactory.h \
    macros.h \
    command.h \
    controller.h \
    sender.h \
    currentmacrosesdialog.h \
    macrosdatacontroller.h \
    macrosoutputholder.h \
    keysetconverter.h

FORMS    += mainwindow.ui \
    addingdialog.ui \
    currentmacrosesdialog.ui

RESOURCES += \
    systray.qrc
