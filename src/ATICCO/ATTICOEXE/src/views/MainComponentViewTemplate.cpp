#include <views/MainComponentViewTemplate.h>
#include "ui_MainComponentViewTemplate.h"

MainComponentViewTemplate::MainComponentViewTemplate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainComponentViewTemplate)
{
    ui->setupUi(this);
}

MainComponentViewTemplate::~MainComponentViewTemplate()
{
    delete ui;
}

void MainComponentViewTemplate::setResourceConsumptionWidget(ResourceConsumptionWidget *value)
{
    resourceConsumptionWidget = value;
    ui->leftTopWidget->layout()->addWidget(value);
}
