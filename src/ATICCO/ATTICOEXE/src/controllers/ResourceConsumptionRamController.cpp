#include "controllers/ResourceConsumptionRamController.h"
#include "resourceCollectors/RamUsageCollector.h"

ResourceConsumptionRamController::ResourceConsumptionRamController(QList<ResourceConsumptionWidget *> resourceConsumptionWidgets) :
    ResourceConsumptionController(resourceConsumptionWidgets)
{
    connect(&timer, SIGNAL(timeout()), this,  SLOT(refreshRamResourceUsage()));
}

ResourceConsumptionRamController::~ResourceConsumptionRamController()
{

}


void ResourceConsumptionRamController::refreshRamResourceUsage()
{
    RamUsageCollector* ramCollector = new RamUsageCollector();
    threadMap.insert(ramCollector->getId(), ramCollector);

    connect(ramCollector, SIGNAL(ramUsageCollected(int)), this, SLOT(setCurrentConsumption(int)));
    connect(ramCollector, SIGNAL(canDeleteMe(int)), this, SLOT(deleteThread(int)));
    connect(ramCollector, SIGNAL(finished()), ramCollector, SLOT(deleteLater()));

    ramCollector->start();
}
