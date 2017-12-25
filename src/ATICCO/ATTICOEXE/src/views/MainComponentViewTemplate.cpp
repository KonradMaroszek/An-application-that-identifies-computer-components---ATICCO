#include <views/MainComponentViewTemplate.h>
#include "ui_MainComponentViewTemplate.h"

#include "views/ResourceConsumptionChartWidget.h"

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

void MainComponentViewTemplate::setResourceConsumptionChartWidget(ResourceConsumptionChartWidget *value)
{
    resourceConsumptionChartWidget = value;
    ui->bottomWidget->layout()->addWidget(value);
}

void MainComponentViewTemplate::setTitleLabelLeft(const QString string)
{
    ui->titleLabelLeft->setText(string);
}

void MainComponentViewTemplate::setTitleLabelRight(const QString string)
{
    ui->titleLabelRight->setText(string);
}

void MainComponentViewTemplate::setFirstLabelLeft(const QString string)
{
    ui->firstLeftLabel->setText(string);
}

void MainComponentViewTemplate::setFirstLabelRight(const QString string)
{
    ui->firstRightLabel->setText(string);
}

void MainComponentViewTemplate::setSecondLabelLeft(const QString string)
{
    ui->secondLeftLabel->setText(string);
}

void MainComponentViewTemplate::setSecondLabelRight(const QString string)
{
    ui->secondRightLabel->setText(string);
}

void MainComponentViewTemplate::setThirdLabelLeft(const QString string)
{
    ui->thirdLeftLabel->setText(string);
}

void MainComponentViewTemplate::setThirdLabelRight(const QString string)
{
    ui->thirdRightLabel->setText(string);
}

void MainComponentViewTemplate::setFourthLabelLeft(const QString string)
{
    ui->fourthLeftLabel->setText(string);
}

void MainComponentViewTemplate::setFourthLabelRight(const QString string)
{
    ui->fourthRightLabel->setText(string);
}

void MainComponentViewTemplate::setFifthLabelLeft(const QString string)
{
    ui->fifthLeftLabel->setText(string);
}

void MainComponentViewTemplate::setFifthLabelRight(const QString string)
{
    ui->fifthRightLabel->setText(string);
}

void MainComponentViewTemplate::setSixthLabelLeft(const QString string)
{
    ui->sixthLeftLabel->setText(string);
}

void MainComponentViewTemplate::setSixthLabelRight(const QString string)
{
    ui->sixthRightLabel->setText(string);
}

void MainComponentViewTemplate::setSeventhLabelLeft(const QString string)
{
    ui->seventhLeftLayout->setText(string);
}

void MainComponentViewTemplate::setSeventhLabelRight(const QString string)
{
    ui->seventhRightLayout->setText(string);
}

void MainComponentViewTemplate::setEigthLabelLeft(const QString string)
{
    ui->eighthLeftLabel->setText(string);
}

void MainComponentViewTemplate::setEigthLabelRight(const QString string)
{
    ui->eighthRightLabel->setText(string);
}
