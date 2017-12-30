#include "resourceCollectors/RamUsageCollector.h"

RamUsageCollector::RamUsageCollector() :
    ResourceCollector()
{

}

RamUsageCollector::~RamUsageCollector()
{

}

void RamUsageCollector::run()
{
    emit ramUsageCollected(id%100);
    emit canDeleteMe(id);
}
