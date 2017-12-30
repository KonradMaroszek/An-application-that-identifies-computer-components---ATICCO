#ifndef CPUINFORMATIONCOLLECTOR_H
#define CPUINFORMATIONCOLLECTOR_H

#include "resourceCollectors/ResourceCollector.h"

class CpuInformationCollector : public ResourceCollector
{
    Q_OBJECT
public:
        CpuInformationCollector();
        virtual ~CpuInformationCollector();

private:
    virtual void run();

signals:
    void cpuNameCollected(const QString string);
    void cpuMaxClockSpeedCollected(const QString string);
    void cpuCurrentClockSpeedCollected(const QString string);
    void cpuNumberOfCoresCollected(const QString string);
    void cpuManufactuerCollected(const QString string);
    void cpuAddressWidthCollected(const QString string);
    void cpuDataWidthCollected(const QString string);
    void cpuCurrentVoltageCollected(const QString string);
    void cpuIdCollected(const QString string);
};


#endif // CPUINFORMATIONCOLLECTOR_H
