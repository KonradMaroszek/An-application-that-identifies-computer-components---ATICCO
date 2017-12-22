#include "controllers/ResourceConsumptionController.h"

ResourceConsumptionController::ResourceConsumptionController(ResourceConsumptionWidget *resourceConsumptionWidget)
    : resourceConsumptionWidget(resourceConsumptionWidget)
{
    timer.start(1000);
    timeSinceRestart.start();
    timeSinceStart.start();

    connect(&timer, SIGNAL(timeout()), this, SLOT(refreshTime()));

    connect(resourceConsumptionWidget, SIGNAL(resetClicked()), this, SLOT(resetRestartClock()));

    connect(this, SIGNAL(timeSinceRestartChanged(int)), resourceConsumptionWidget, SLOT(setTimeSinceRestart(int)));
    connect(this, SIGNAL(timeSinceStartChanged(int)), resourceConsumptionWidget, SLOT(setTimeSinceStart(int)));

    connect(this, SIGNAL(currentResourceConsumptionChanged(int)), resourceConsumptionWidget, SLOT(setCurrentResourceConsumption(int)));
    connect(this, SIGNAL(avarageResourceConsumptionChanged(int)), resourceConsumptionWidget, SLOT(setAvarageResourceConsumption(int)));
    connect(this, SIGNAL(avarageResourceConsumptionSinceRestartChanged(int)), resourceConsumptionWidget, SLOT(setAvarageResourceConsumptionSinceRestart(int)));


    emit currentResourceConsumptionChanged(12);
    emit avarageResourceConsumptionChanged(53);
    emit avarageResourceConsumptionSinceRestartChanged(66);
}

ResourceConsumptionController::~ResourceConsumptionController()
{

}

void ResourceConsumptionController::resetRestartClock()
{
    timeSinceRestart.restart();
    emit timeSinceRestartChanged(timeSinceRestart.elapsed());
}

void ResourceConsumptionController::refreshTime()
{
    emit timeSinceStartChanged(timeSinceStart.elapsed());
    emit timeSinceRestartChanged(timeSinceRestart.elapsed());
}
