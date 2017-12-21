#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "views/ResourceConsumptionWidget.h"
#include "controllers/ResourceConsumptionController.h"

#include <QThread>

AticcoMainWIndow::AticcoMainWIndow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AticcoMainWIndow)
{
    ui->setupUi(this);

    ResourceConsumptionWidget* cpuConsumptionWidget = new ResourceConsumptionWidget();
    ResourceConsumptionController* resourceConsumptionController = new ResourceConsumptionController(cpuConsumptionWidget);
    cpuConsumptionWidget->setTitle(QString("CPU"));
    ui->CPUResourceConsumptionWIdget->layout()->addWidget(cpuConsumptionWidget);

    ResourceConsumptionWidget* b = new ResourceConsumptionWidget();
    ResourceConsumptionController* resourceConsumptionController1 = new ResourceConsumptionController(b);
    ui->RAMResourceConsumptionWIdget->layout()->addWidget(b);

    ResourceConsumptionWidget* c = new ResourceConsumptionWidget();
    ResourceConsumptionController* resourceConsumptionController2 = new ResourceConsumptionController(c);
    ui->DiskResourceConsumptionWIdget->layout()->addWidget(c);

    ResourceConsumptionWidget* d = new ResourceConsumptionWidget();
    ResourceConsumptionController* resourceConsumptionController3 = new ResourceConsumptionController(d);
    ui->NetworkResourceConsumptionWIdget->layout()->addWidget(d);

}

AticcoMainWIndow::~AticcoMainWIndow()
{
    delete ui;
}
