#-------------------------------------------------
#
# Project created by QtCreator 2017-08-07T14:40:38
#
#-------------------------------------------------

QT       += core gui charts

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
    src/main.cpp \
    src/mainwindow.cpp \
    src/views/ResourceConsumptionWidget.cpp \
    src/controllers/ResourceConsumptionController.cpp \
    src/CpuInformationCollector.cpp \
    src/views/MainComponentViewTemplate.cpp \
    src/views/ResourceConsumptionChartWidget.cpp \
    src/views/CpuMainView.cpp \
    src/views/RamMainView.cpp \
    src/views/DiskMainView.cpp \
    src/views/NetworkMainView.cpp \
    src/AxisSettings.cpp \
    src/Range.cpp

HEADERS += \
    headers/mainwindow.h \
    headers/views/ResourceConsumptionWidget.h \
    headers/controllers/ResourceConsumptionController.h \
    headers/CpuInformationCollector.h \
    headers/views/MainComponentViewTemplate.h \
    headers/views/ResourceConsumptionChartWidget.h \
    headers/views/CpuMainView.h \
    headers/views/DiskMainView.h \
    headers/views/NetworkMainView.h \
    headers/views/RamMainView.h \
    headers/AxisSettings.h \
    headers/Range.h

FORMS += \
    uiFiles\mainwindow.ui \
    uiFiles/ResourceConsumptionWidget.ui \
    uiFiles/MainComponentViewTemplate.ui \
    uiFiles/ResourceConsumptionChartWidget.ui

RESOURCES += \
    resources/resources.qrc
