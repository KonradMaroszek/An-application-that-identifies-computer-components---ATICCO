#ifndef CPUUSAGECOLLECTOR_H
#define CPUUSAGECOLLECTOR_H

#include "resourceCollectors/ResourceCollector.h"

class CpuUsageCollector : public ResourceCollector
{
    Q_OBJECT
public:
        CpuUsageCollector();
        virtual ~CpuUsageCollector();

private:
    virtual void run();
    void deleteParameterName();
    QByteArray extractDigit();
    void collectCpuUsageFromDigitArray(QByteArray digitArray);

signals:
    void cpuUsageCollected(int);
};

#endif // CPUUSAGECOLLECTOR_H
