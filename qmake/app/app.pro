#
# QMake build configuration for assignment4 main application
#
#   Executable will be located at ./build/assignment4 after build

include(../assignment4.pri)

TEMPLATE = app
CONFIG += debug c++14
TARGET = assignment4
WARNINGS += -Wall

SOURCES += $$mySRC_DIR/main.cpp

QT += widgets

DESTDIR = $$myDEST_ROOT
LIBS += -L$$DESTDIR/as4 -las4
