#include "resourceCollectors/DiskUsageCollector.h"

DiskUsageCollector::DiskUsageCollector() :
    ResourceCollector()
{

}

DiskUsageCollector::~DiskUsageCollector()
{

}

void DiskUsageCollector::run()
{
    emit diskUsageCollected(id%100);
    emit canDeleteMe(id);
}
