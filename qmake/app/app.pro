#
# QMake build configuration for assignment4 main application
#
#   Executable will be located at ./build/assignment4 after build

include(../assignment4.pri)

TEMPLATE = app
CONFIG += debug c++14
TARGET = assignment4
WARNINGS += -Wall

#SOURCES += $$mySRC_DIR/main.cpp \
#    $$mySRC_DIR/widgets/mainwindow.cpp \

#HEADERS += \
#    $$myINCLUDE_DIR/widgets/mainwindow.h \

QT += widgets

DESTDIR = $$myDEST_ROOT
LIBS += -L$$DESTDIR/as4 -las4

FORMS += \
    mainwindow.ui

RESOURCES += \
    resource.qrc

HEADERS += \
    mainwindow.h

SOURCES += \
    main.cpp \
    mainwindow.cpp
