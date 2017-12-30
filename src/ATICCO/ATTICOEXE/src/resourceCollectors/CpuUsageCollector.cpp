#include "resourceCollectors/CpuUsageCollector.h"

CpuUsageCollector::CpuUsageCollector() :
    ResourceCollector()
{

}

CpuUsageCollector::~CpuUsageCollector()
{

}

void CpuUsageCollector::deleteParameterName()
{
    int index = systemCommandResult.indexOf("=");
    systemCommandResult.remove(0, index + 1);
}

QByteArray CpuUsageCollector::extractDigit()
{
    QByteArray digitArray;

    for (QChar character : systemCommandResult)
    {
        if(character.isDigit())
        {
            digitArray.append(character);
        }else
        {
            break;
        }
    }

    return digitArray;
}

void CpuUsageCollector::collectCpuUsageFromDigitArray(QByteArray digitArray)
{
    bool canConvertToInt = false;

    int result = digitArray.toInt(&canConvertToInt);

    if (canConvertToInt)
    {
        emit cpuUsageCollected(result);
    }
}

void CpuUsageCollector::run()
{
    QStringList getCpuUsageCommand;
    getCpuUsageCommand << "cpu get loadpercentage / format:list";
    systemCommandResult = processUtils.runSystemCommand("wmic", getCpuUsageCommand, 1000);

    deleteParameterName();

    QByteArray digitArray = extractDigit();

    collectCpuUsageFromDigitArray(digitArray);

    emit canDeleteMe(id);
}
