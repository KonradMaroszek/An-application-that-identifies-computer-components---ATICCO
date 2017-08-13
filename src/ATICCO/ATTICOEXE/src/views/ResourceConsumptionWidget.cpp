#include <views/ResourceConsumptionWidget.h>
#include "ui_ResourceConsumptionWidget.h"

ResourceConsumptionWidget::ResourceConsumptionWidget(QWidget *parent) :
    QWidget(parent),
    currentResourceConsumption(0),
    averageResourceConsumption(0),
    averageResourceConsumptionSinceRestart(0),
    ui(new Ui::ResourceConsumptionWidget)
{
    ui->setupUi(this);

    timer.start(1000);
    timeSinceRestart.start();
    timeSinceStart.start();

    connect(&timer, SIGNAL(timeout()), this, SLOT(refreshTime()));
    connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(resetRestartClock()));
}

ResourceConsumptionWidget::~ResourceConsumptionWidget()
{
    delete ui;
}

void ResourceConsumptionWidget::setTitle(QString &title)
{
    ui->titleLabel->setText(title);
}

void ResourceConsumptionWidget::setCurrentResourceConsumption(int value)
{
    if (value > 100 || value < 0)
    {
        //throw invalidTimecocooc;
    }

    currentResourceConsumption = value;
}

void ResourceConsumptionWidget::setAvarageResourceConsumption(int value)
{
    if (value > 100 || value < 0)
    {
        //throw invalidTimecocooc;
    }

    averageResourceConsumption = value;
}

void ResourceConsumptionWidget::setAvarageResourceConsumptionSinceRestart(int value)
{
    if (value > 100 || value < 0)
    {
        //throw invalidTimecocooc;
    }

    averageResourceConsumptionSinceRestart = value;
}

void ResourceConsumptionWidget::resetRestartClock()
{
    timeSinceRestart.restart();
}

void ResourceConsumptionWidget::refreshTime()
{
    setTime(timeSinceStart.elapsed());
    setRestartTime(timeSinceRestart.elapsed());
}

void ResourceConsumptionWidget::setTextValues()
{
    ui->avarageResourceConsumptionFromRestartLabel->setText(QString::number(averageResourceConsumptionSinceRestart) + "%");
    ui->avarageResourceConsumptionLabel->setText(QString::number(averageResourceConsumption) + "%");
    ui->progressBar->setValue(currentResourceConsumption);
    ui->resourceConsumptionLabel->setText(QString::number(currentResourceConsumption) + "%");
}

void ResourceConsumptionWidget::setRestartTime(int milisecondsSinceRestart)
{
    QTime timeToDisplay = QTime::fromMSecsSinceStartOfDay(milisecondsSinceRestart);
    ui->timeOfMeasurmentFromRestartLabel->setText(timeToDisplay.toString());
}

void ResourceConsumptionWidget::setTime(int milisecondsSinceStart)
{
    QTime timeToDisplay = QTime::fromMSecsSinceStartOfDay(milisecondsSinceStart);
    ui->timeOfMeasurmentLabel->setText(timeToDisplay.toString());
}
