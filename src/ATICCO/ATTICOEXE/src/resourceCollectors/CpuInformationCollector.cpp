#include "resourceCollectors/CpuInformationCollector.h"

CpuInformationCollector::CpuInformationCollector()
{

}

CpuInformationCollector::~CpuInformationCollector()
{

}


void CpuInformationCollector::run()
{
    QStringList getCpuInformationCommand;
    getCpuInformationCommand << "cpu list / format:list";
    systemCommandResult = processUtils.runSystemCommand("wmic", getCpuInformationCommand, 15000);

    emit cpuNameCollected(getValueFromCommandForKey("Name"));
    emit cpuMaxClockSpeedCollected(getValueFromCommandForKey("MaxClockSpeed") + QString(" MHz"));
    emit cpuCurrentClockSpeedCollected(getValueFromCommandForKey("CurrentClockSpeed") + QString(" MHz"));
    emit cpuManufactuerCollected(getValueFromCommandForKey("Manufacturer"));
    emit cpuAddressWidthCollected(getValueFromCommandForKey("AddressWidth") + QString(" bits"));
    emit cpuDataWidthCollected(getValueFromCommandForKey("DataWidth")  + QString(" bits"));
    emit cpuCurrentVoltageCollected(getValueFromCommandForKey("CurrentVoltage")  + QString(" V"));
    emit cpuIdCollected(getValueFromCommandForKey("ProcessorId"));

    QStringList getCpuCoresCommand;
    getCpuCoresCommand << "cpu get NumberOfCores / format:list";
    systemCommandResult = processUtils.runSystemCommand("wmic", getCpuCoresCommand, 15000);

    emit cpuNumberOfCoresCollected(getValueFromCommandForKey("NumberOfCores"));
}
