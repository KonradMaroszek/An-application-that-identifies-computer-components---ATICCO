#include "resourceCollectors/CpuUsageCollector.h"
#include "SystemInfo.h"

CpuUsageCollector::CpuUsageCollector() :
    ResourceCollector()
{

}

CpuUsageCollector::~CpuUsageCollector()
{

}

void CpuUsageCollector::run()
{ 
    emit cpuUsageCollected(SystemInfo::getProcessorLoad());
    emit canDeleteMe(id);
}
