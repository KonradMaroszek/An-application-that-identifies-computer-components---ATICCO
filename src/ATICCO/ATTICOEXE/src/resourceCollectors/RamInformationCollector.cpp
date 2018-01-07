#include "resourceCollectors/RamInformationCollector.h"

RamInformationCollector::RamInformationCollector()
{

}

RamInformationCollector::~RamInformationCollector()
{

}

QList<QByteArray> RamInformationCollector::createChipInformationList()
{
    QList<QByteArray> chipInformationList;

    QString result = systemCommandResult;

    int indexOfCurrentChip = 0;
    int indexOfNextChip = 0;

    while (indexOfCurrentChip != -1 && indexOfNextChip != -1) {
        indexOfCurrentChip = result.indexOf("BankLabel=");
        indexOfNextChip = result.indexOf("BankLabel=", indexOfCurrentChip + sizeof("BankLabel="));

        if (indexOfNextChip != -1)
        {
            chipInformationList.append(result.mid(indexOfCurrentChip, indexOfNextChip - indexOfCurrentChip).toLatin1());
            result = result.mid( indexOfNextChip, result.size() - indexOfNextChip);
        } else
        {
            chipInformationList.append(result.mid(indexOfCurrentChip, result.size() - indexOfCurrentChip).toLatin1());
        }
    }

    return chipInformationList;
}

void RamInformationCollector::run()
{
    QStringList getCpuInformationCommand;
    getCpuInformationCommand << "memorychip list / format:list";
    systemCommandResult = processUtils.runSystemCommand("wmic", getCpuInformationCommand, 15000);

    QList<QByteArray> chipInformationList = createChipInformationList();

    QString capacity = "|";
    QString type = "|";
    QString dataWidth = "|";
    QString totalWidth = "|";
    QString manufactuers = "|";
    QString partNumbers = "|";
    QString serialNumbers = "|";
    QString speed = "|";

    for (QByteArray curretnChip : chipInformationList)
    {
        capacity += getValueFromCommandForKey("Capacity", curretnChip) + " bytes" + " |";
        type += getValueFromCommandForKey("MemoryType", curretnChip) + " |";
        dataWidth += getValueFromCommandForKey("DataWidth", curretnChip) + "bytes" + " |";
        totalWidth += getValueFromCommandForKey("TotalWidth", curretnChip) + "bytes" + " |";
        manufactuers += getValueFromCommandForKey("Manufacturer", curretnChip)  + " |";
        partNumbers += getValueFromCommandForKey("PartNumber", curretnChip)  + " |";
        serialNumbers += getValueFromCommandForKey("SerialNumber", curretnChip)  + " |";
        speed += getValueFromCommandForKey("Speed", curretnChip)  + "mHz |";
    }


    emit ramNumberOfMemoryChipsCollected(QString::number(chipInformationList.size()));
    emit ramCapacityCollected(capacity);
    emit ramSpeedCollected(speed);
    emit ramTypeCollected(type);
    emit ramDataWidthCollected(dataWidth);
    emit ramTotalWidthCollected(totalWidth);
    emit ramManufactuersCollected(manufactuers);
    emit ramSerialNumbersCollected(serialNumbers);
    emit ramPartNumbersCollected(partNumbers);
}
