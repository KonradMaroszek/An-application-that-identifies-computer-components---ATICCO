#ifndef RESOURCECONSUMPRIONNETWORK_H
#define RESOURCECONSUMPRIONNETWORK_H

#include "ResourceConsumptionController.h"

class ResourceConsumptionNetworkController : ResourceConsumptionController
{
    Q_OBJECT
public:
    explicit ResourceConsumptionNetworkController(QList<ResourceConsumptionWidget *> resourceConsumptionWidgets);
    virtual ~ResourceConsumptionNetworkController();

signals:
    void networkUploadSpeedCollected(QString);
    void networkDownloadSpeedCollected(QString);

private slots:
    void refreshNetworkResourceUsage();
};

#endif // RESOURCECONSUMPRIONNETWORK_H
