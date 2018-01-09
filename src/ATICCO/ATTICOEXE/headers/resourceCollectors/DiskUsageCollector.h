#ifndef DISKUSAGECOLLECTOR_H
#define DISKUSAGECOLLECTOR_H

#include "resourceCollectors/ResourceCollector.h"

class DiskUsageCollector : public ResourceCollector
{
    Q_OBJECT
public:
        DiskUsageCollector();
        virtual ~DiskUsageCollector();

private:
    virtual void run();

signals:
    void diskUsageCollected(int);
    void diskWriteBytesCollected(QString);
    void diskReadBytesCollected(QString);
};

#endif // DISKUSAGECOLLECTOR_H
