#
# QMake build configuration for assignment4 main application
#
#   Executable will be located at ./build/assignment4 after build

include(../assignment4.pri)

TEMPLATE = app
CONFIG += debug c++14
TARGET = assignment4
WARNINGS += -Wall

QT += widgets \
    multimedia

DESTDIR = $$myDEST_ROOT
LIBS += -L$$DESTDIR/as4 -las4

FORMS += \
    mainwindow.ui

RESOURCES += \
    resource.qrc

HEADERS += \
    autostopsoundeffect.h \
    clickablelabel.h \
    mainwindow.h \
    playsong.h \
    tracks.h \
    visualnote.h

SOURCES += \
    autostopsoundeffect.cpp \
    clickablelabel.cpp \
    main.cpp \
    mainwindow.cpp \
    playsong.cpp \
    tracks.cpp \
    visualnote.cpp
