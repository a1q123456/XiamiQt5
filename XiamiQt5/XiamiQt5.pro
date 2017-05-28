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
QT += multimedia

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
    carousellistviewmodel.cpp \
    songinfo.cpp \
    playlist_page.cpp \
    playlisttablemodel.cpp \
    playhistorytablemodel.cpp \
    play_history_page.cpp

HEADERS  += mainwindow.h \
    pch.h \
    functionlistmodel.h \
    functionlist.h \
    main_page.h \
    filedownloader.h \
    carousellistmodelobject.h \
    carousellistviewmodel.h \
    songinfo.h \
    playlist_page.h \
    playlisttablemodel.h \
    playhistorytablemodel.h \
    play_history_page.h

FORMS    += mainwindow.ui \
    main_page.ui \
    playlist_page.ui \
    play_history_page.ui

mac {
    QMAKE_MAC_SDK = macosx10.11
    OTHER_FILES += Info.plist
    QMAKE_INFO_PLIST +=  Info.plist
    QMAKE_POST_LINK += sed -i -e "s/@VERSION@/$$VERSION/g" "./$${TARGET}.app/Contents/Info.plist";
    INSTALLS += plist
}

INCLUDEPATH += $$PWD/../XiamiAPI/include
INCLUDEPATH += $$PWD/../boost
LIBS += -L"$$PWD/../XiamiAPI/lib" -lxiamiapi -lcurl
RESOURCES += \
    resource.qrc
