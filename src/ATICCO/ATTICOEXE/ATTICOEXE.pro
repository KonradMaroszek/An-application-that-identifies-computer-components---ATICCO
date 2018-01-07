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
    src/views/MainComponentViewTemplate.cpp \
    src/views/ResourceConsumptionChartWidget.cpp \
    src/views/CpuMainView.cpp \
    src/views/RamMainView.cpp \
    src/views/DiskMainView.cpp \
    src/views/NetworkMainView.cpp \
    src/AxisSettings.cpp \
    src/Range.cpp \
    src/UsbInfo.cpp \
    src/views/widgetCreators/UsbWidgetCreator.cpp \
    src/controllers/ResourceConsumptionCpuController.cpp \
    src/controllers/ResourceConsumptionController.cpp \
    src/controllers/ResourceConsumptionCpuController.cpp \
    src/utils/ProcessUtils.cpp \
    src/views/widgetCreators/UsbWidgetCreator.cpp \
    src/views/CpuMainView.cpp \
    src/views/DiskMainView.cpp \
    src/views/mainComponentViewTemplate.cpp \
    src/views/NetworkMainView.cpp \
    src/views/RamMainView.cpp \
    src/views/ResourceConsumptionChartWidget.cpp \
    src/views/ResourceConsumptionWidget.cpp \
    src/AxisSettings.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/Range.cpp \
    src/UsbInfo.cpp \
    src/resourceCollectors/CpuUsageCollector.cpp \
    src/resourceCollectors/ResourceCollector.cpp \
    src/resourceCollectors/CpuUsageCollector.cpp \
    src/resourceCollectors/DiskUsageCollector.cpp \
    src/resourceCollectors/NetworkUsageCollector.cpp \
    src/resourceCollectors/RamUsageCollector.cpp \
    src/resourceCollectors/ResourceCollector.cpp \
    src/controllers/ResourceConsumptionController.cpp \
    src/controllers/ResourceConsumptionCpuController.cpp \
    src/controllers/ResourceConsumptionDiskController.cpp \
    src/controllers/ResourceConsumptionNetworkController.cpp \
    src/controllers/ResourceConsumptionRamController.cpp \
    src/resourceCollectors/CpuInformationCollector.cpp \
    src/resourceCollectors/RamInformationCollector.cpp

HEADERS += \
    headers/mainwindow.h \
    headers/views/ResourceConsumptionWidget.h \
    headers/controllers/ResourceConsumptionController.h \
    headers/views/MainComponentViewTemplate.h \
    headers/views/ResourceConsumptionChartWidget.h \
    headers/views/CpuMainView.h \
    headers/views/DiskMainView.h \
    headers/views/NetworkMainView.h \
    headers/views/RamMainView.h \
    headers/AxisSettings.h \
    headers/Range.h \
    headers/UsbInfo.h \
    headers/views/widgetCreators/WidgetCreator.h \
    headers/views/widgetCreators/UsbWidgetCreator.h \
    headers/controllers/ResourceConsumptionCpuController.h \
    headers/utils/ProcessUtils.h \
    headers/controllers/ResourceConsumptionController.h \
    headers/controllers/ResourceConsumptionCpuController.h \
    headers/resourceCollectors/CpuUsageCollector.h \
    headers/utils/ProcessUtils.h \
    headers/views/widgetCreators/UsbWidgetCreator.h \
    headers/views/widgetCreators/WidgetCreator.h \
    headers/views/CpuMainView.h \
    headers/views/DiskMainView.h \
    headers/views/MainComponentViewTemplate.h \
    headers/views/NetworkMainView.h \
    headers/views/RamMainView.h \
    headers/views/ResourceConsumptionChartWidget.h \
    headers/views/ResourceConsumptionWidget.h \
    headers/AxisSettings.h \
    headers/mainwindow.h \
    headers/Range.h \
    headers/UsbInfo.h \
    headers/resourceCollectors/ResourceCollector.h \
    headers/resourceCollectors/CpuUsageCollector.h \
    headers/resourceCollectors/DiskUsageCollector.h \
    headers/resourceCollectors/NetworkUsageCollector.h \
    headers/resourceCollectors/RamUsageCollector.h \
    headers/resourceCollectors/ResourceCollector.h \
    headers/controllers/ResourceConsumptionController.h \
    headers/controllers/ResourceConsumptionCpuController.h \
    headers/controllers/ResourceConsumptionDiskController.h \
    headers/controllers/ResourceConsumptionRamController.h \
    headers/controllers/ResourceConsumptionNetworkController.h \
    headers/resourceCollectors/CpuInformationCollector.h \
    headers/resourceCollectors/RamInformationCollector.h

FORMS += \
    uiFiles\mainwindow.ui \
    uiFiles/ResourceConsumptionWidget.ui \
    uiFiles/MainComponentViewTemplate.ui \
    uiFiles/ResourceConsumptionChartWidget.ui

RESOURCES += \
    resources/resources.qrc

LIBS += -lSetupapi
