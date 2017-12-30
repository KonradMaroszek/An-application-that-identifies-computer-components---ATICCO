#include "resourceCollectors/NetworkUsageCollector.h"

NetworkUsageCollector::NetworkUsageCollector() :
    ResourceCollector()
{

}

NetworkUsageCollector::~NetworkUsageCollector()
{

}

void NetworkUsageCollector::run()
{
    emit networkUsageCollected(id%100);
    emit canDeleteMe(id);
}
