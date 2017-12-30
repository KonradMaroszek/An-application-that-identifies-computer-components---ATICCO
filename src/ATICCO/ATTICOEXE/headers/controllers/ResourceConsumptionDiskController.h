#ifndef RESOURCECONSUMPRIONDISK_H
#define RESOURCECONSUMPRIONDISK_H

#include "ResourceConsumptionController.h"

class ResourceConsumptionDiskController : ResourceConsumptionController
{
    Q_OBJECT
public:
    explicit ResourceConsumptionDiskController(QList<ResourceConsumptionWidget *> resourceConsumptionWidgets);
    virtual ~ResourceConsumptionDiskController();

private slots:
    void refreshDiskResourceUsage();
};

#endif // RESOURCECONSUMPRIONDISK_H
