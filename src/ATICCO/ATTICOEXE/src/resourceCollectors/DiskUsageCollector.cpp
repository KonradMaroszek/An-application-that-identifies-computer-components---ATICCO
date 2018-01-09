#include "resourceCollectors/DiskUsageCollector.h"

#include <Windows.h>
#include <iostream>

DiskUsageCollector::DiskUsageCollector() :
    ResourceCollector()
{

}

DiskUsageCollector::~DiskUsageCollector()
{

}

void DiskUsageCollector::run()
{
    int diskUsage = 0;
    QString diskWriteBytes = 0;
    QString diskReadBytes = 0;
    QString diskReadWriteBytes = 0;

    int numberOfSambles = 3;

    while (diskUsage == 0 && numberOfSambles != 0)
    {
        QStringList getDiskUsageCommand;
        getDiskUsageCommand << "path Win32_PerfFormattedData_PerfDisk_LogicalDisk where (Name='C:') get / format:list";
        systemCommandResult = processUtils.runSystemCommand("wmic", getDiskUsageCommand, 1500);

        diskUsage = getValueFromCommandForKey("PercentDiskTime").toInt();
        diskWriteBytes = getValueFromCommandForKey("DiskReadBytesPersec");
        diskReadBytes = getValueFromCommandForKey("DiskWriteBytesPersec");
        diskReadWriteBytes = getValueFromCommandForKey("DiskBytesPersec");

        numberOfSambles--;
    }


    emit diskUsageCollected(diskUsage);
    emit diskWriteBytesCollected(diskWriteBytes + " bytes/s");
    emit diskReadBytesCollected(diskReadBytes + " bytes/s");
    emit diskReadWriteBytesCollected(diskReadWriteBytes + " bytes/s");

    emit canDeleteMe(id);
}
