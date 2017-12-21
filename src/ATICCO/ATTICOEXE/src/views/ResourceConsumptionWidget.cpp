#include <views/ResourceConsumptionWidget.h>
#include "ui_ResourceConsumptionWidget.h"

ResourceConsumptionWidget::ResourceConsumptionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResourceConsumptionWidget)
{
    ui->setupUi(this);

    connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(resetButtonClicked()));
}

ResourceConsumptionWidget::~ResourceConsumptionWidget()
{
    delete ui;
}

void ResourceConsumptionWidget::setTitle(QString &title)
{
    ui->titleLabel->setText(title);
}

void ResourceConsumptionWidget::setCurrentResourceConsumption(const int value)
{
    ui->progressBar->setValue(value);
    ui->resourceConsumptionLabel->setText(QString::number(value) + "%");
}

void ResourceConsumptionWidget::setAvarageResourceConsumption(const int value)
{
    ui->avarageResourceConsumptionLabel->setText(QString::number(value) + "%");
}

void ResourceConsumptionWidget::setAvarageResourceConsumptionSinceRestart(const int value)
{
    ui->avarageResourceConsumptionFromRestartLabel->setText(QString::number(value) + "%");
}

void ResourceConsumptionWidget::setTimeSinceRestart(const int milisecondsSinceRestart)
{
    QTime timeToDisplay = QTime::fromMSecsSinceStartOfDay(milisecondsSinceRestart);
    ui->timeOfMeasurmentFromRestartLabel->setText(timeToDisplay.toString());
}

void ResourceConsumptionWidget::setTimeSinceStart(const int milisecondsSinceStart)
{
    QTime timeToDisplay = QTime::fromMSecsSinceStartOfDay(milisecondsSinceStart);
    ui->timeOfMeasurmentLabel->setText(timeToDisplay.toString());
}

void ResourceConsumptionWidget::resetButtonClicked()
{
    emit resetClicked();
}
