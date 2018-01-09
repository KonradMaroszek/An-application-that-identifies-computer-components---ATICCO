#include "resourceCollectors/RamUsageCollector.h"
#include "SystemInfo.h"
RamUsageCollector::RamUsageCollector() :
    ResourceCollector()
{

}

RamUsageCollector::~RamUsageCollector()
{

}

void RamUsageCollector::run()
{
    emit ramUsageCollected(SystemInfo::getRAMLoad());
    emit canDeleteMe(id);
}
