#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "views/ResourceConsumptionWidget.h"
#include "views/MainComponentViewTemplate.h"
#include "controllers/ResourceConsumptionController.h"

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

    ResourceConsumptionWidget* b = new ResourceConsumptionWidget();  
    ui->RAMResourceConsumptionWIdget->layout()->addWidget(b);

    ResourceConsumptionWidget* c = new ResourceConsumptionWidget();
    ui->DiskResourceConsumptionWIdget->layout()->addWidget(c);

    ResourceConsumptionWidget* d = new ResourceConsumptionWidget();
    ui->NetworkResourceConsumptionWIdget->layout()->addWidget(d);

    MainComponentViewTemplate* network = new MainComponentViewTemplate();
    MainComponentViewTemplate* disk = new MainComponentViewTemplate();
    MainComponentViewTemplate* cpu = new MainComponentViewTemplate();
    MainComponentViewTemplate* ram = new MainComponentViewTemplate();

    ResourceConsumptionWidget* cpuMainConsumptionWidget = new ResourceConsumptionWidget();
    cpu->setResourceConsumptionWidget(cpuMainConsumptionWidget);
    cpuWidgets.append(cpuMainConsumptionWidget);

    ui->cpuMainVerticalLayout->addWidget(cpu);
    ui->ramMainVerticalLayout->addWidget(ram);
    ui->networkMainVerticalLayout->addWidget(network);
    ui->diskMainVerticalLayout->addWidget(disk);

    ResourceConsumptionController* resourceConsumptionCpuController = new ResourceConsumptionController(cpuWidgets);
    ResourceConsumptionController* resourceConsumptionRamController1 = new ResourceConsumptionController(ramWidgets);
    ResourceConsumptionController* resourceConsumptionDiskController2 = new ResourceConsumptionController(diskWidgets);
    ResourceConsumptionController* resourceConsumptionNetworkController3 = new ResourceConsumptionController(networkWidgets);
}

AticcoMainWIndow::~AticcoMainWIndow()
{
    delete ui;
}
