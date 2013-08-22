#-------------------------------------------------
#
# Project created by QtCreator 2013-08-22T13:27:08
#
#-------------------------------------------------

QT       += network multimedia

QT       -= gui

TARGET = qgooglespeech
TEMPLATE = lib

DEFINES += QGOOGLESPEECH_LIBRARY

SOURCES += \
    qgooglespeech.cpp

HEADERS +=\
    qgooglespeech_global.h \
    qgooglespeech.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
