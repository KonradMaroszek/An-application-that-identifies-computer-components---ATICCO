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
    src/main.cpp \
    src/mainwindow.cpp \
    src/views/ResourceConsumptionWidget.cpp \
    src/controllers/ResourceConsumptionController.cpp \
    src/CpuInformationCollector.cpp

HEADERS += \
    headers\mainwindow.h \
    headers/mainwindow.h \
    headers/views/ResourceConsumptionWidget.h \
    headers/controllers/ResourceConsumptionController.h \
    headers/CpuInformationCollector.h

FORMS += \
    uiFiles\mainwindow.ui \
    uiFiles/ResourceConsumptionWidget.ui \
    uiFiles/mainComponentViewTemplate.ui

RESOURCES += \
    resources/resources.qrc
