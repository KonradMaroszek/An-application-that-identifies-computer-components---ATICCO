#include "controllers/ResourceConsumptionDiskController.h"
#include "resourceCollectors/DiskUsageCollector.h"

ResourceConsumptionDiskController::ResourceConsumptionDiskController(QList<ResourceConsumptionWidget *> resourceConsumptionWidgets) :
    ResourceConsumptionController(resourceConsumptionWidgets)
{   
    timerDiskResource.start(5000);
    connect(&timerDiskResource, SIGNAL(timeout()), this,  SLOT(refreshDiskResourceUsage()));
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

    connect(diskCollector, SIGNAL(diskReadBytesCollected(QString)), this, SIGNAL(diskReadSpeedCollected(QString)));
    connect(diskCollector, SIGNAL(diskWriteBytesCollected(QString)), this, SIGNAL(diskWriteSpeedCollected(QString)));

    diskCollector->start();
}
