#-------------------------------------------------
#
# Project created by QtCreator 2016-07-18T21:38:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets
QT += network
QT += uiplugin
QT += quick

TARGET = XiamiQt5
TEMPLATE = app

CONFIG += precompile_header
CONFIG += c++14
PRECOMPILED_HEADER = pch.h

SOURCES += main.cpp\
        mainwindow.cpp \
    pch.cpp \
    functionlistmodel.cpp \
    functionlist.cpp \
    main_page.cpp \
    filedownloader.cpp \
    carousellistmodelobject.cpp \
    carousellistviewmodel.cpp

HEADERS  += mainwindow.h \
    pch.h \
    functionlistmodel.h \
    functionlist.h \
    main_page.h \
    filedownloader.h \
    carousellistmodelobject.h \
    carousellistviewmodel.h

FORMS    += mainwindow.ui \
    main_page.ui


INCLUDEPATH += $$PWD/../XiamiAPI/include
LIBS += -L"$$PWD/../XiamiAPI/lib" -lxiamiapi -lcurl
QMAKE_MAC_SDK = macosx10.12
RESOURCES += \
    resource.qrc
