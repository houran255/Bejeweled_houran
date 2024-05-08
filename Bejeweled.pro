#-------------------------------------------------
#
# Project created by QtCreator 2022-07-10T15:51:29
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += multimediawidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bejeweled
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

CONFIG += c++11
CONFIG+=resources_big

SOURCES += \
        Start_Widget.cpp \
        gamewidget.cpp \
        gem.cpp \
        main.cpp \
        myform.cpp \
        myprobar.cpp \
        pbtn_start.cpp \
        record.cpp \
        selectlevel.cpp \
        settingpage.cpp \
        slidepixmap.cpp

HEADERS += \
        Start_Widget.h \
        gamewidget.h \
        gem.h \
        myform.h \
        myprobar.h \
        pbtn_start.h \
        record.h \
        selectlevel.h \
        settingpage.h \
        slidepixmap.h

FORMS += \
        gamewidget.ui \
        myform.ui \
        record.ui \
        selectlevel.ui \
        settingpage.ui \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    music/Wobble_And Waltz_No.mp3
