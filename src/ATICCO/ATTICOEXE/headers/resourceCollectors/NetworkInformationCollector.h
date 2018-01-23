#ifndef NETWORKINFORMATIONCOLLECTOR_H
#define NETWORKINFORMATIONCOLLECTOR_H

#include "resourceCollectors/ResourceCollector.h"

class NetworkInformationCollector : public ResourceCollector
{
    Q_OBJECT
public:
        NetworkInformationCollector();
        virtual ~NetworkInformationCollector();

private:
    virtual void run();

signals:
    void networkNameCollected(const QString string);
    void networkCardNameCollected(const QString string);
    void networkSSIDCollected(const QString string);
    void networkDNSNameCollected(const QString string);
    void networkTypeOfConnectionCollected(const QString string);
    void networkIPv4Collected(const QString string);
    void networkIPv6Collected(const QString string);
};

#endif // NETWORKINFORMATIONCOLLECTOR_H
