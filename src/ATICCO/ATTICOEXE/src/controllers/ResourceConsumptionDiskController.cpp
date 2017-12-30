#include "controllers/ResourceConsumptionDiskController.h"
#include "resourceCollectors/DiskUsageCollector.h"

ResourceConsumptionDiskController::ResourceConsumptionDiskController(QList<ResourceConsumptionWidget *> resourceConsumptionWidgets) :
    ResourceConsumptionController(resourceConsumptionWidgets)
{
    connect(&timer, SIGNAL(timeout()), this,  SLOT(refreshDiskResourceUsage()));
}

ResourceConsumptionDiskController::~ResourceConsumptionDiskController()
{

}


void ResourceConsumptionDiskController::refreshDiskResourceUsage()
{
    DiskUsageCollector* diskCollector = new DiskUsageCollector();
    threadMap.insert(diskCollector->getId(), diskCollector);

    connect(diskCollector, SIGNAL(diskUsageCollected(int)), this, SLOT(setCurrentConsumption(int)));
    connect(diskCollector, SIGNAL(canDeleteMe(int)), this, SLOT(deleteThread(int)));
    connect(diskCollector, SIGNAL(finished()), diskCollector, SLOT(deleteLater()));

    diskCollector->start();
}
