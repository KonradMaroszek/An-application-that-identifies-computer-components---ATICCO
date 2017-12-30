#include "controllers/ResourceConsumptionCpuController.h"

#include "utils/ResultWatcher.h"
#include "resourceCollectors/CpuUsageCollector.h"

#include <QFuture>

ResourceConsumptionCpuController::ResourceConsumptionCpuController(QList<ResourceConsumptionWidget *> resourceConsumptionWidgets) :
    ResourceConsumptionController(resourceConsumptionWidgets)
{
    connect(&timer, SIGNAL(timeout()), this,  SLOT(refreshCpuResourceUsage()));
}

ResourceConsumptionCpuController::~ResourceConsumptionCpuController()
{

}


void ResourceConsumptionCpuController::refreshCpuResourceUsage()
{
    CpuUsageCollector* cpuCollector = new CpuUsageCollector();
    threadMap.insert(cpuCollector->getId(), cpuCollector);

    connect(cpuCollector, SIGNAL(cpuUsageCollected(int)), this, SLOT(setCurrentConsumption(int)));
    connect(cpuCollector, SIGNAL(canDeleteMe(int)), this, SLOT(deleteThread(int)));
    connect(cpuCollector, SIGNAL(finished()), cpuCollector, SLOT(deleteLater()));

    cpuCollector->start();
}
