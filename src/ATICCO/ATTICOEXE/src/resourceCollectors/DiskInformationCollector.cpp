#include "resourceCollectors/DiskInformationCollector.h"
#include "QRegularExpression"
#include <cmath>

DiskInformationCollector::DiskInformationCollector() :
    ResourceCollector()

{

}

DiskInformationCollector::~DiskInformationCollector()
{

}

void DiskInformationCollector::run()
{
    QStringList getDiskInformationCommand;
    getDiskInformationCommand << "diskdrive list / format:list";
    systemCommandResult = processUtils.runSystemCommand("wmic", getDiskInformationCommand, 15000);

    emit diskModeCollected(getValueFromCommandForKey("Model"));

    QStringList getLogicalDiskInformationCommand;
    getLogicalDiskInformationCommand << "logicaldisk list / format:list";
    systemCommandResult = processUtils.runSystemCommand("wmic", getLogicalDiskInformationCommand, 15000);

    QString size = getValueFromCommandForKey("Size");
    QString freeSpace = getValueFromCommandForKey("FreeSpace");

    size.replace(QRegularExpression("[^0-9]"), "");
    freeSpace.replace(QRegularExpression("[^0-9]"), "");

    qDebug(freeSpace.toLatin1());

    emit diskSizeCollected(size);
    emit diskFreeSpaceCollected(freeSpace);
    emit diskFileSystemCollectedCollected(getValueFromCommandForKey("FileSystem"));
    emit diskIdCollected(getValueFromCommandForKey("Name"));

    double diskFreeSpace = (freeSpace.toLongLong() / (double)(size.toLongLong())) * 100;
    diskFreeSpace = floor(diskFreeSpace*100)/100;

    emit diskFreeSpaceInPercentageCollected(QString::number(diskFreeSpace) + " %");
}
