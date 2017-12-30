#ifndef RESOURCECONSUMPRIONRAM_H
#define RESOURCECONSUMPRIONRAM_H

#include "ResourceConsumptionController.h"

class ResourceConsumptionRamController : ResourceConsumptionController
{
    Q_OBJECT
public:
    explicit ResourceConsumptionRamController(QList<ResourceConsumptionWidget *> resourceConsumptionWidgets);
    virtual ~ResourceConsumptionRamController();

private slots:
    void refreshRamResourceUsage();
};

#endif // RESOURCECONSUMPRIONRAM_H
