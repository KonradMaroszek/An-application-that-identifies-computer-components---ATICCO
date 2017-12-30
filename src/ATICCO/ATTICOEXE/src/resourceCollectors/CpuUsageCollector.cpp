#include "resourceCollectors/CpuUsageCollector.h"

CpuUsageCollector::CpuUsageCollector() :
    ResourceCollector()
{

}

CpuUsageCollector::~CpuUsageCollector()
{

}

void CpuUsageCollector::run()
{
    QStringList getCpuUsageCommand;
    getCpuUsageCommand << "cpu get loadpercentage / format:list";
    systemCommandResult = processUtils.runSystemCommand("wmic", getCpuUsageCommand, 1000);

    emit cpuUsageCollected(getValueFromCommandForKey("LoadPercentage").toInt());
    emit canDeleteMe(id);
}
