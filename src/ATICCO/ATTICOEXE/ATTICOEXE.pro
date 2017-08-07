#-------------------------------------------------
#
# Project created by QtCreator 2017-08-07T14:40:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Aticco
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

#Adding UAC manifest
#CONFIG(debug, debug|release) {
#    message("UAC manifest will not add to exe file")
#} else {
#    QMAKE_LFLAGS += "/MANIFESTUAC:\"level=\'requireAdministrator\' uiAccess=\'false\'\""
#    message("UAC manifest will add to exe file")
#}

INCLUDEPATH += \
        src\
        headers\
        uiFiles\
        resources

RC_FILE += resources\Aticco.rc

SOURCES += \
        src\main.cpp \
        src\mainwindow.cpp \
    release/moc_mainwindow.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
        headers\mainwindow.h \
    headers/mainwindow.h \
    release/moc_predefs.h \
    ui_mainwindow.h

FORMS += \
        uiFiles\mainwindow.ui

RESOURCES += \
    resources/resources.qrc
