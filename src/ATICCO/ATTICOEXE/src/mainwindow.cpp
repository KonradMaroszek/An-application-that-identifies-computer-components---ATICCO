#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "views/ResourceConsumptionWidget.h"
#include "views/CpuMainView.h"
#include "views/DiskMainView.h"
#include "views/RamMainView.h"
#include "views/NetworkMainView.h"

#include "controllers/ResourceConsumptionController.h"

#include "UsbInfo.h"

#include "views/widgetCreators/UsbWidgetCreator.h"

#include <QThread>

AticcoMainWIndow::AticcoMainWIndow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AticcoMainWIndow)
{
    ui->setupUi(this);

    QList<ResourceConsumptionWidget*> cpuWidgets;
    QList<ResourceConsumptionWidget*> ramWidgets;
    QList<ResourceConsumptionWidget*> diskWidgets;
    QList<ResourceConsumptionWidget*> networkWidgets;

    ResourceConsumptionWidget* cpuConsumptionWidget = new ResourceConsumptionWidget();
    cpuConsumptionWidget->setTitle(QString("CPU"));
    ui->CPUResourceConsumptionWIdget->layout()->addWidget(cpuConsumptionWidget);
    cpuWidgets.append(cpuConsumptionWidget);

    ResourceConsumptionWidget* networkConsumptionWidget = new ResourceConsumptionWidget();
    networkConsumptionWidget->setTitle(QString("Network"));
    ui->NetworkResourceConsumptionWIdget->layout()->addWidget(networkConsumptionWidget);
    networkWidgets.append(networkConsumptionWidget);


    ResourceConsumptionWidget* diskConsumptionWidget = new ResourceConsumptionWidget();
    diskConsumptionWidget->setTitle(QString("Disk"));
    ui->DiskResourceConsumptionWIdget->layout()->addWidget(diskConsumptionWidget);
    diskWidgets.append(diskConsumptionWidget);

    ResourceConsumptionWidget* ramConsumptionWidget = new ResourceConsumptionWidget();
    ramConsumptionWidget->setTitle(QString("RAM"));
    ui->RAMResourceConsumptionWIdget->layout()->addWidget(ramConsumptionWidget);
    ramWidgets.append(ramConsumptionWidget);

    DiskMainView* disk = new DiskMainView();
    disk->setModel("HTUMSMSM");
    disk->setSize("123212311");
    disk->setFreeSpace("7878782");
    disk->setFreeSpaceInPercentage("6,3%");
    disk->setFileSystemType("NFTS");
    disk->setReadSpeed("205 mb/s");
    disk->setWriteSpeed("203 mb/s");
    disk->setAverageResponseTime("2300 ms");
    disk->setId("KSJDHHAMHHJA");


    CpuMainView* cpu = new CpuMainView();
    cpu->setName("Intel(R) Core(TM) i7-3517U CPU @ 1.90GHz");
    cpu->setMaxClockSpeed("2401");
    cpu->setCurrentClockSpeed("1900");
    cpu->setNumberOfCores("4");
    cpu->setManufactuer("GenuineIntel");
    cpu->setAddressWidth("64");
    cpu->setDataWidth("64");
    cpu->setCurrentVoltage("8");
    cpu->setId("BFEBFBFF000306A9");

    RamMainView* ram = new RamMainView();
    ram->setNumberOfMemoryChips("2");
    ram->setCapacity("8.0 GB");
    ram->setSpeed("1600 MHz");
    ram->setType("DDR3");
    ram->setDataWidth("64");
    ram->setTotalWidth("64");
    ram->setManufactuers("Samsung | Samsung");
    ram->setPartNumbers("SADKUHA | 8987897-ASD");
    ram->setSerialNumbers("BFEBFB | FF000306A9");


    NetworkMainView* network = new NetworkMainView();
    network->setName("Intel(R) Centrino(R) Wirelesss-N 2230");
    network->setCardName("Wi-Fi");
    network->setSSID("FunBox-9C01");
    network->setDNSname("home");
    network->setTypeOfConnection("802.11g");
    network->setIPv4Address("192.168.1.17");
    network->setIPv6Address("fe80:6dew:sdaw:2222%4");
    network->setUploadSpeed("20 kb/s");
    network->setDownloadSpeed("105 kb/s");

    ResourceConsumptionWidget* cpuMainConsumptionWidget = new ResourceConsumptionWidget();
    cpu->setResourceConsumptionWidget(cpuMainConsumptionWidget);
    cpuMainConsumptionWidget->setTitle(QString("CPU"));
    cpuWidgets.append(cpuMainConsumptionWidget);

    ResourceConsumptionChartWidget* cpuMainConsumptionChartWidget = new ResourceConsumptionChartWidget();
    cpu->setResourceConsumptionChartWidget(cpuMainConsumptionChartWidget);

    ResourceConsumptionWidget* diskMainConsumptionWidget = new ResourceConsumptionWidget();
    disk->setResourceConsumptionWidget(diskMainConsumptionWidget);
    diskMainConsumptionWidget->setTitle(QString("Disk"));
    diskWidgets.append(diskMainConsumptionWidget);

    ResourceConsumptionChartWidget* diskMainConsumptionChartWidget = new ResourceConsumptionChartWidget();
    disk->setResourceConsumptionChartWidget(diskMainConsumptionChartWidget);

    ResourceConsumptionWidget* ramMainConsumptionWidget = new ResourceConsumptionWidget();
    ram->setResourceConsumptionWidget(ramMainConsumptionWidget);
    ramMainConsumptionWidget->setTitle(QString("RAM"));
    ramWidgets.append(ramMainConsumptionWidget);

    ResourceConsumptionChartWidget* ramMainConsumptionChartWidget = new ResourceConsumptionChartWidget();
    ram->setResourceConsumptionChartWidget(ramMainConsumptionChartWidget);

    ResourceConsumptionWidget* networkMainConsumptionWidget = new ResourceConsumptionWidget();
    network->setResourceConsumptionWidget(networkMainConsumptionWidget);
    networkMainConsumptionWidget->setTitle(QString("Network"));
    networkWidgets.append(networkMainConsumptionWidget);

    ResourceConsumptionChartWidget* networkMainConsumptionChartWidget = new ResourceConsumptionChartWidget();
    network->setResourceConsumptionChartWidget(networkMainConsumptionChartWidget);


    ui->cpuMainVerticalLayout->addWidget((QWidget*)cpu);
    ui->ramMainVerticalLayout->addWidget((QWidget*)ram);
    ui->networkMainVerticalLayout->addWidget((QWidget*)network);
    ui->diskMainVerticalLayout->addWidget((QWidget*)disk);

    ResourceConsumptionController* resourceConsumptionCpuController = new ResourceConsumptionController(cpuWidgets);
    connect(resourceConsumptionCpuController, SIGNAL(currentResourceConsumptionChanged(int)), cpuMainConsumptionChartWidget, SLOT(newResourceConsumptionValue(int)));

    ResourceConsumptionController* resourceConsumptionRamController = new ResourceConsumptionController(ramWidgets);
    connect(resourceConsumptionRamController, SIGNAL(currentResourceConsumptionChanged(int)), ramMainConsumptionChartWidget, SLOT(newResourceConsumptionValue(int)));


    ResourceConsumptionController* resourceConsumptionDiskController = new ResourceConsumptionController(diskWidgets);
    connect(resourceConsumptionDiskController, SIGNAL(currentResourceConsumptionChanged(int)), diskMainConsumptionChartWidget, SLOT(newResourceConsumptionValue(int)));


    ResourceConsumptionController* resourceConsumptionNetworkController = new ResourceConsumptionController(networkWidgets);
    connect(resourceConsumptionNetworkController, SIGNAL(currentResourceConsumptionChanged(int)), networkMainConsumptionChartWidget, SLOT(newResourceConsumptionValue(int)));


    connect(ui->refreshUsbViewButton, SIGNAL(clicked(bool)), this, SLOT(changeUsbWidget()));

    USBInfo asd;
    QList<QSharedPointer<USBInformation>> usbInformations = asd.getUSBInfo();

    UsbWidgetCreator usbWidgetCreator;
    usbWidgetCreator.setData(usbInformations);

    usbWidget = usbWidgetCreator.createWidget();

    ui->usbMainVerticalLayout->addWidget(usbWidget);
}

AticcoMainWIndow::~AticcoMainWIndow()
{
    delete ui;
}

void AticcoMainWIndow::changeUsbWidget()
{
    USBInfo asd;
    QList<QSharedPointer<USBInformation>> usbInformations = asd.getUSBInfo();

    UsbWidgetCreator usbWidgetCreator;
    usbWidgetCreator.setData(usbInformations);

    QWidget* newUsbWidget = usbWidgetCreator.createWidget();

    ui->usbMainVerticalLayout->replaceWidget(usbWidget, newUsbWidget);
    usbWidget->deleteLater();

    usbWidget = newUsbWidget;
}
