#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "views/ResourceConsumptionWidget.h"
#include "views/CpuMainView.h"
#include "views/DiskMainView.h"
#include "views/RamMainView.h"
#include "views/NetworkMainView.h"

#include "controllers/ResourceConsumptionController.h"
#include "controllers/ResourceConsumptionCpuController.h"
#include "controllers/ResourceConsumptionDiskController.h"
#include "controllers/ResourceConsumptionRamController.h"
#include "controllers/ResourceConsumptionNetworkController.h"

#include "resourceCollectors/CpuInformationCollector.h"
#include "resourceCollectors/RamInformationCollector.h"
#include "resourceCollectors/DiskInformationCollector.h"
#include "resourceCollectors/NetworkInformationCollector.h"

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
    connect(cpuConsumptionWidget, SIGNAL(moreDetailsClickedSignal()), this, SLOT(setCpuTabActive()));

    ResourceConsumptionWidget* networkConsumptionWidget = new ResourceConsumptionWidget();
    networkConsumptionWidget->setTitle(QString("Wi-Fi"));
    ui->NetworkResourceConsumptionWIdget->layout()->addWidget(networkConsumptionWidget);
    networkWidgets.append(networkConsumptionWidget);
    connect(networkConsumptionWidget, SIGNAL(moreDetailsClickedSignal()), this, SLOT(setNetworkTabActive()));


    ResourceConsumptionWidget* diskConsumptionWidget = new ResourceConsumptionWidget();
    diskConsumptionWidget->setTitle(QString("Disk"));
    ui->DiskResourceConsumptionWIdget->layout()->addWidget(diskConsumptionWidget);
    diskWidgets.append(diskConsumptionWidget);
    connect(diskConsumptionWidget, SIGNAL(moreDetailsClickedSignal()), this, SLOT(setDiskTabActive()));

    ResourceConsumptionWidget* ramConsumptionWidget = new ResourceConsumptionWidget();
    ramConsumptionWidget->setTitle(QString("RAM"));
    ui->RAMResourceConsumptionWIdget->layout()->addWidget(ramConsumptionWidget);
    ramWidgets.append(ramConsumptionWidget);
    connect(ramConsumptionWidget, SIGNAL(moreDetailsClickedSignal()), this, SLOT(setRamTabActive()));

    DiskMainView* disk = new DiskMainView();
    DiskInformationCollector* diskCollector = new DiskInformationCollector();

    connect(diskCollector, SIGNAL(diskModeCollected(QString)), (QObject*)disk, SLOT(setModel(QString)));
    connect(diskCollector, SIGNAL(diskSizeCollected(QString)), (QObject*)disk, SLOT(setSize(QString)));
    connect(diskCollector, SIGNAL(diskFreeSpaceCollected(QString)), (QObject*)disk, SLOT(setFreeSpace(QString)));
    connect(diskCollector, SIGNAL(diskFreeSpaceInPercentageCollected(QString)), (QObject*)disk, SLOT(setFreeSpaceInPercentage(QString)));
    connect(diskCollector, SIGNAL(diskFileSystemCollectedCollected(QString)), (QObject*)disk, SLOT(setFileSystemType(QString)));
    connect(diskCollector, SIGNAL(diskIdCollected(QString)), (QObject*)disk, SLOT(setId(QString)));

    //connect(cpuCollector, SIGNAL(canDeleteMe(int)), this, SLOT(deleteThread(int)));
    connect(diskCollector, SIGNAL(finished()), diskCollector, SLOT(deleteLater()));

    diskCollector->start();

    CpuMainView* cpu = new CpuMainView();
    CpuInformationCollector* cpuCollector = new CpuInformationCollector();

    connect(cpuCollector, SIGNAL(cpuNameCollected(QString)), (QObject*)cpu, SLOT(setName(QString)));
    connect(cpuCollector, SIGNAL(cpuAddressWidthCollected(QString)), (QObject*)cpu, SLOT(setAddressWidth(QString)));
    connect(cpuCollector, SIGNAL(cpuCurrentClockSpeedCollected(QString)), (QObject*)cpu, SLOT(setCurrentClockSpeed(QString)));
    connect(cpuCollector, SIGNAL(cpuCurrentVoltageCollected(QString)), (QObject*)cpu, SLOT(setCurrentVoltage(QString)));
    connect(cpuCollector, SIGNAL(cpuDataWidthCollected(QString)), (QObject*)cpu, SLOT(setDataWidth(QString)));
    connect(cpuCollector, SIGNAL(cpuIdCollected(QString)), (QObject*)cpu, SLOT(setId(QString)));
    connect(cpuCollector, SIGNAL(cpuManufactuerCollected(QString)), (QObject*)cpu, SLOT(setManufactuer(QString)));
    connect(cpuCollector, SIGNAL(cpuMaxClockSpeedCollected(QString)), (QObject*)cpu, SLOT(setMaxClockSpeed(QString)));
    connect(cpuCollector, SIGNAL(cpuNumberOfCoresCollected(QString)), (QObject*)cpu, SLOT(setNumberOfCores(QString)));

    //connect(cpuCollector, SIGNAL(canDeleteMe(int)), this, SLOT(deleteThread(int)));
    connect(cpuCollector, SIGNAL(finished()), cpuCollector, SLOT(deleteLater()));

    cpuCollector->start();


    RamMainView* ram = new RamMainView();
    RamInformationCollector* ramCollector = new RamInformationCollector();

    connect(ramCollector, SIGNAL(ramCapacityCollected(QString)), (QObject*)ram, SLOT(setCapacity(QString)));
    connect(ramCollector, SIGNAL(ramDataWidthCollected(QString)), (QObject*)ram, SLOT(setDataWidth(QString)));
    connect(ramCollector, SIGNAL(ramManufactuersCollected(QString)), (QObject*)ram, SLOT(setManufactuers(QString)));
    connect(ramCollector, SIGNAL(ramNumberOfMemoryChipsCollected(QString)), (QObject*)ram, SLOT(setNumberOfMemoryChips(QString)));
    connect(ramCollector, SIGNAL(ramPartNumbersCollected(QString)), (QObject*)ram, SLOT(setPartNumbers(QString)));
    connect(ramCollector, SIGNAL(ramSerialNumbersCollected(QString)), (QObject*)ram, SLOT(setSerialNumbers(QString)));
    connect(ramCollector, SIGNAL(ramSpeedCollected(QString)), (QObject*)ram, SLOT(setSpeed(QString)));
    connect(ramCollector, SIGNAL(ramTotalWidthCollected(QString)), (QObject*)ram, SLOT(setTotalWidth(QString)));
    connect(ramCollector, SIGNAL(ramTypeCollected(QString)), (QObject*)ram, SLOT(setType(QString)));

    //connect(ramCollector, SIGNAL(canDeleteMe(int)), this, SLOT(deleteThread(int)));
    connect(ramCollector, SIGNAL(finished()), ramCollector, SLOT(deleteLater()));

    ramCollector->start();

    NetworkMainView* network = new NetworkMainView();
    NetworkInformationCollector* networkCollector = new NetworkInformationCollector();

    connect(networkCollector, SIGNAL(networkNameCollected(QString)), (QObject*)network, SLOT(setName(QString)));
    connect(networkCollector, SIGNAL(networkCardNameCollected(QString)), (QObject*)network, SLOT(setCardName(QString)));
    connect(networkCollector, SIGNAL(networkSSIDCollected(QString)), (QObject*)network, SLOT(setSSID(QString)));
    connect(networkCollector, SIGNAL(networkDNSNameCollected(QString)), (QObject*)network, SLOT(setDNSname(QString)));
    connect(networkCollector, SIGNAL(networkTypeOfConnectionCollected(QString)), (QObject*)network, SLOT(setTypeOfConnection(QString)));
    connect(networkCollector, SIGNAL(networkIPv4Collected(QString)), (QObject*)network, SLOT(setIPv4Address(QString)));
    connect(networkCollector, SIGNAL(networkIPv6Collected(QString)), (QObject*)network, SLOT(setIPv6Address(QString)));

    //connect(ramCollector, SIGNAL(canDeleteMe(int)), this, SLOT(deleteThread(int)));
    connect(networkCollector, SIGNAL(finished()), networkCollector, SLOT(deleteLater()));

    networkCollector->start();

    ResourceConsumptionWidget* cpuMainConsumptionWidget = new ResourceConsumptionWidget();
    cpu->setResourceConsumptionWidget(cpuMainConsumptionWidget);
    cpuMainConsumptionWidget->setTitle(QString("CPU"));
    cpuMainConsumptionWidget->hideCommandLinkButton();
    cpuWidgets.append(cpuMainConsumptionWidget);

    ResourceConsumptionChartWidget* cpuMainConsumptionChartWidget = new ResourceConsumptionChartWidget();
    cpu->setResourceConsumptionChartWidget(cpuMainConsumptionChartWidget);

    ResourceConsumptionWidget* diskMainConsumptionWidget = new ResourceConsumptionWidget();
    disk->setResourceConsumptionWidget(diskMainConsumptionWidget);
    diskMainConsumptionWidget->setTitle(QString("Disk"));
    diskMainConsumptionWidget->hideCommandLinkButton();
    diskWidgets.append(diskMainConsumptionWidget);

    ResourceConsumptionChartWidget* diskMainConsumptionChartWidget = new ResourceConsumptionChartWidget();
    disk->setResourceConsumptionChartWidget(diskMainConsumptionChartWidget);

    ResourceConsumptionWidget* ramMainConsumptionWidget = new ResourceConsumptionWidget();
    ram->setResourceConsumptionWidget(ramMainConsumptionWidget);
    ramMainConsumptionWidget->setTitle(QString("RAM"));
    ramMainConsumptionWidget->hideCommandLinkButton();
    ramWidgets.append(ramMainConsumptionWidget);

    ResourceConsumptionChartWidget* ramMainConsumptionChartWidget = new ResourceConsumptionChartWidget();
    ram->setResourceConsumptionChartWidget(ramMainConsumptionChartWidget);

    ResourceConsumptionWidget* networkMainConsumptionWidget = new ResourceConsumptionWidget();
    network->setResourceConsumptionWidget(networkMainConsumptionWidget);
    networkMainConsumptionWidget->setTitle(QString("Wi-Fi"));
    networkMainConsumptionWidget->hideCommandLinkButton();
    networkWidgets.append(networkMainConsumptionWidget);


    ResourceConsumptionChartWidget* networkMainConsumptionChartWidget = new ResourceConsumptionChartWidget();
    network->setResourceConsumptionChartWidget(networkMainConsumptionChartWidget);


    ui->cpuMainVerticalLayout->addWidget((QWidget*)cpu);
    ui->ramMainVerticalLayout->addWidget((QWidget*)ram);
    ui->networkMainVerticalLayout->addWidget((QWidget*)network);
    ui->diskMainVerticalLayout->addWidget((QWidget*)disk);

    ResourceConsumptionCpuController* resourceConsumptionCpuController = new ResourceConsumptionCpuController(cpuWidgets);
    connect((QObject*)resourceConsumptionCpuController, SIGNAL(currentResourceConsumptionChanged(int)), cpuMainConsumptionChartWidget, SLOT(newResourceConsumptionValue(int)));

    ResourceConsumptionRamController* resourceConsumptionRamController = new ResourceConsumptionRamController(ramWidgets);
    connect((QObject*)resourceConsumptionRamController, SIGNAL(currentResourceConsumptionChanged(int)), ramMainConsumptionChartWidget, SLOT(newResourceConsumptionValue(int)));


    ResourceConsumptionDiskController* resourceConsumptionDiskController = new ResourceConsumptionDiskController(diskWidgets);
    connect((QObject*)resourceConsumptionDiskController, SIGNAL(currentResourceConsumptionChanged(int)), diskMainConsumptionChartWidget, SLOT(newResourceConsumptionValue(int)));
    connect((QObject*)resourceConsumptionDiskController, SIGNAL(diskReadSpeedCollected(QString)), (QObject*)disk, SLOT(setReadSpeed(QString)));
    connect((QObject*)resourceConsumptionDiskController, SIGNAL(diskWriteSpeedCollected(QString)), (QObject*)disk, SLOT(setWriteSpeed(QString)));
    connect((QObject*)resourceConsumptionDiskController, SIGNAL(diskReadWriteSpeedCollected(QString)), (QObject*)disk, SLOT(setReadWriteSpeed(QString)));

    ResourceConsumptionNetworkController* resourceConsumptionNetworkController = new ResourceConsumptionNetworkController(networkWidgets);
    connect((QObject*)resourceConsumptionNetworkController, SIGNAL(currentResourceConsumptionChanged(int)), networkMainConsumptionChartWidget, SLOT(newResourceConsumptionValue(int)));
    connect((QObject*)resourceConsumptionNetworkController, SIGNAL(networkDownloadSpeedCollected(QString)), (QObject*)network, SLOT(setDownloadSpeed(QString)));
    connect((QObject*)resourceConsumptionNetworkController, SIGNAL(networkUploadSpeedCollected(QString)), (QObject*)network, SLOT(setUploadSpeed(QString)));


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
    USBInfo usbInfo;
    QList<QSharedPointer<USBInformation>> usbInformations = usbInfo.getUSBInfo();

    UsbWidgetCreator usbWidgetCreator;
    usbWidgetCreator.setData(usbInformations);

    QWidget* newUsbWidget = usbWidgetCreator.createWidget();

    ui->usbMainVerticalLayout->replaceWidget(usbWidget, newUsbWidget);
    usbWidget->deleteLater();

    usbWidget = newUsbWidget;
}

void AticcoMainWIndow::setCpuTabActive()
{
    ui->tabWidget->setCurrentWidget(ui->cpuTab);
}

void AticcoMainWIndow::setRamTabActive()
{
    ui->tabWidget->setCurrentWidget(ui->ramTab);
}

void AticcoMainWIndow::setDiskTabActive()
{
    ui->tabWidget->setCurrentWidget(ui->diskTab);
}

void AticcoMainWIndow::setNetworkTabActive()
{
    ui->tabWidget->setCurrentWidget(ui->networkTab);
}
