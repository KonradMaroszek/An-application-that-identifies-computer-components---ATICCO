#ifndef NETWORKUSAGECOLLECTOR_H
#define NETWORKUSAGECOLLECTOR_H

#include "resourceCollectors/ResourceCollector.h"

class NetworkUsageCollector : public ResourceCollector
{
    Q_OBJECT
public:
        NetworkUsageCollector();
        virtual ~NetworkUsageCollector();

private:
    virtual void run();

signals:
    void networkUsageCollected(int);
};

#endif // NETWORKUSAGECOLLECTOR_H
