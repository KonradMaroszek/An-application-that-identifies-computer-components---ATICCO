#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <views/ResourceConsumptionWidget.h>

AticcoMainWIndow::AticcoMainWIndow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AticcoMainWIndow)
{
    ui->setupUi(this);

    ResourceConsumptionWidget* a = new ResourceConsumptionWidget();
    ui->CPUResourceConsumptionWIdget->layout()->addWidget(a);
    a->setTitle(QString("CPU"));

    ResourceConsumptionWidget* b = new ResourceConsumptionWidget();
    ui->RAMResourceConsumptionWIdget->layout()->addWidget(b);

    ResourceConsumptionWidget* c = new ResourceConsumptionWidget();
    ui->DiskResourceConsumptionWIdget->layout()->addWidget(c);

    ResourceConsumptionWidget* d = new ResourceConsumptionWidget();
    ui->NetworkResourceConsumptionWIdget->layout()->addWidget(d);

}

AticcoMainWIndow::~AticcoMainWIndow()
{
    delete ui;
}
