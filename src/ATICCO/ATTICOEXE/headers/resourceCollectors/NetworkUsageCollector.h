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
    void networkInBytesCollected(QString);
    void networkOutBytesCollected(QString);
};

#endif // NETWORKUSAGECOLLECTOR_H
