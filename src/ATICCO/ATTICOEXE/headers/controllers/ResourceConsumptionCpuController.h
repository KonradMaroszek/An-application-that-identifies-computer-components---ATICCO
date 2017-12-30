#ifndef RESOURCECONSUMPRIONCPU_H
#define RESOURCECONSUMPRIONCPU_H

#include "ResourceConsumptionController.h"
#include <QMap>
#include "resourceCollectors/CpuUsageCollector.h"

class ResourceConsumptionCpuController : ResourceConsumptionController
{
    Q_OBJECT
public:
    explicit ResourceConsumptionCpuController(QList<ResourceConsumptionWidget *> resourceConsumptionWidgets);
    virtual ~ResourceConsumptionCpuController();

private slots:
    void refreshCpuResourceUsage();
};

#endif // RESOURCECONSUMPRIONCPU_H
