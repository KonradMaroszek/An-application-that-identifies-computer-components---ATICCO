#ifndef RESOURCECONSUMPRIONDISK_H
#define RESOURCECONSUMPRIONDISK_H

#include "ResourceConsumptionController.h"

class ResourceConsumptionDiskController : ResourceConsumptionController
{
    Q_OBJECT
public:
    explicit ResourceConsumptionDiskController(QList<ResourceConsumptionWidget *> resourceConsumptionWidgets);
    virtual ~ResourceConsumptionDiskController();

signals:
    void diskWriteSpeedCollected(QString);
    void diskReadSpeedCollected(QString);
    void diskReadWriteSpeedCollected(QString);

private slots:
    void refreshDiskResourceUsage();

private:
    QTimer timerDiskResource;

};

#endif // RESOURCECONSUMPRIONDISK_H
