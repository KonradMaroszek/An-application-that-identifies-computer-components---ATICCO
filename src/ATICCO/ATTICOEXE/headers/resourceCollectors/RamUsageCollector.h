#ifndef RAMUSAGECOLLECTOR_H
#define RAMUSAGECOLLECTOR_H

#include "resourceCollectors/ResourceCollector.h"

class RamUsageCollector : public ResourceCollector
{
    Q_OBJECT
public:
        RamUsageCollector();
        virtual ~RamUsageCollector();

private:
    virtual void run();

signals:
    void ramUsageCollected(int);
};

#endif // RAMUSAGECOLLECTOR_H
