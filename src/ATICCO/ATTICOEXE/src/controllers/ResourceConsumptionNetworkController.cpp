#include "controllers/ResourceConsumptionNetworkController.h"
#include "resourceCollectors/NetworkUsageCollector.h"

ResourceConsumptionNetworkController::ResourceConsumptionNetworkController(QList<ResourceConsumptionWidget *> resourceConsumptionWidgets) :
    ResourceConsumptionController(resourceConsumptionWidgets)
{
    refreshNetworkResourceUsage();
}

ResourceConsumptionNetworkController::~ResourceConsumptionNetworkController()
{

}


void ResourceConsumptionNetworkController::refreshNetworkResourceUsage()
{
    NetworkUsageCollector* networkCollector = new NetworkUsageCollector();
    threadMap.insert(networkCollector->getId(), networkCollector);

    connect(networkCollector, SIGNAL(networkUsageCollected(int)), this, SLOT(setCurrentConsumption(int)));
    connect(networkCollector, SIGNAL(networkInBytesCollected(QString)), this, SIGNAL(networkDownloadSpeedCollected(QString)));
    connect(networkCollector, SIGNAL(networkOutBytesCollected(QString)), this, SIGNAL(networkUploadSpeedCollected(QString)));
    connect(networkCollector, SIGNAL(canDeleteMe(int)), this, SLOT(deleteThread(int)));
    connect(networkCollector, SIGNAL(finished()), networkCollector, SLOT(deleteLater()));

    networkCollector->start();
}
