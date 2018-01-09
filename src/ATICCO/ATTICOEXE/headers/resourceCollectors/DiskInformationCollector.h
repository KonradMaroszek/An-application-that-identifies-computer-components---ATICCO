#ifndef DISKINFORMATIONCOLLECTOR_H
#define DISKINFORMATIONCOLLECTOR_H

#include "resourceCollectors/ResourceCollector.h"

class DiskInformationCollector : public ResourceCollector
{
    Q_OBJECT
public:
        DiskInformationCollector();
        virtual ~DiskInformationCollector();

private:
    virtual void run();

signals:
    void diskModeCollected(const QString string);
    void diskSizeCollected(const QString string);
    void diskFreeSpaceCollected(const QString string);
    void diskFreeSpaceInPercentageCollected(const QString string);
    void diskFileSystemCollectedCollected(const QString string);
    void diskAvarageResponseTimeCollected(const QString string);
    void diskIdCollected(const QString string);
};

#endif // DISKINFORMATIONCOLLECTOR_H
