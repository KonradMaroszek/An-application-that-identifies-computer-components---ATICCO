#include "controllers/ResourceConsumptionController.h"

ResourceConsumptionController::ResourceConsumptionController(QList<ResourceConsumptionWidget *> resourceConsumptionWidgets)
    : resourceConsumptionWidgets(resourceConsumptionWidgets),
      currentResourceConsumption(0),
      averageResourceConsumption(0),
      averageResourceConsumptionSinceRestart(0),
      resourceConsumption(0),
      resourceConsumptionSinceRestart(0),
      ticks(0),
      ticksSinceRestart(0)

{
    timer.start(1000);
    timeSinceRestart.start();
    timeSinceStart.start();

    connect(&timer, SIGNAL(timeout()), this, SLOT(refreshTime()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(refreshCurrentResourceConsumption()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(refreshAvarageResourceConsumption()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(refreshAvarageResourceConsumptionSinceRestart()));


    for (ResourceConsumptionWidget* resourceConsumptionWidget : resourceConsumptionWidgets)
    {
        connect(resourceConsumptionWidget, SIGNAL(resetClicked()), this, SLOT(resetRestartClock()));

        connect(this, SIGNAL(timeSinceRestartChanged(int)), resourceConsumptionWidget, SLOT(setTimeSinceRestart(int)));
        connect(this, SIGNAL(timeSinceStartChanged(int)), resourceConsumptionWidget, SLOT(setTimeSinceStart(int)));

        connect(this, SIGNAL(currentResourceConsumptionChanged(int)), resourceConsumptionWidget, SLOT(setCurrentResourceConsumption(int)));
        connect(this, SIGNAL(avarageResourceConsumptionChanged(int)), resourceConsumptionWidget, SLOT(setAvarageResourceConsumption(int)));
        connect(this, SIGNAL(avarageResourceConsumptionSinceRestartChanged(int)), resourceConsumptionWidget, SLOT(setAvarageResourceConsumptionSinceRestart(int)));
    }
}

ResourceConsumptionController::~ResourceConsumptionController()
{

}

void ResourceConsumptionController::resetRestartClock()
{
    ticksSinceRestart = 0;
    averageResourceConsumptionSinceRestart = 0;
    resourceConsumptionSinceRestart = 0;
    timeSinceRestart.restart();
    emit timeSinceRestartChanged(timeSinceRestart.elapsed());
}

void ResourceConsumptionController::refreshTime()
{
    ++ticks;
    ++ticksSinceRestart;
    emit timeSinceStartChanged(timeSinceStart.elapsed());
    emit timeSinceRestartChanged(timeSinceRestart.elapsed());
}

void ResourceConsumptionController::refreshCurrentResourceConsumption()
{
    currentResourceConsumption = rand() % 101;
    resourceConsumption += currentResourceConsumption;
    resourceConsumptionSinceRestart += currentResourceConsumption;
    emit currentResourceConsumptionChanged(currentResourceConsumption);
}

void ResourceConsumptionController::refreshAvarageResourceConsumption()
{
    averageResourceConsumption = (resourceConsumption + currentResourceConsumption) / ticks;
    emit avarageResourceConsumptionChanged(averageResourceConsumption%101);
}

void ResourceConsumptionController::refreshAvarageResourceConsumptionSinceRestart()
{
    averageResourceConsumptionSinceRestart = (resourceConsumptionSinceRestart + currentResourceConsumption) / ticksSinceRestart;
    emit avarageResourceConsumptionSinceRestartChanged(averageResourceConsumptionSinceRestart%101);
}
