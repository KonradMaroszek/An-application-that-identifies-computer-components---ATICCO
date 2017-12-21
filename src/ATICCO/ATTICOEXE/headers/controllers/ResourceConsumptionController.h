#ifndef RESOURCECONSUMPTIONCONTROLLER_H
#define RESOURCECONSUMPTIONCONTROLLER_H

#include <QObject>
#include "views/ResourceConsumptionWidget.h"

namespace Ui {
class ResourceConsumptionController;
}

class ResourceConsumptionController : public QObject
{
    Q_OBJECT

public:
    explicit ResourceConsumptionController(ResourceConsumptionWidget* resourceConsumptionWidget);
    ~ResourceConsumptionController();

public slots:

private slots:
    void resetRestartClock();
    void refreshTime();

signals:
    void timeSinceRestartChanged(int);
    void timeSinceStartChanged(int);

    void currentResourceConsumptionChanged(int);
    void avarageResourceConsumptionChanged(int);
    void avarageResourceConsumptionSinceRestartChanged(int);

private:
    ResourceConsumptionWidget* resourceConsumptionWidget;

    int currentResourceConsumption;
    int averageResourceConsumption;
    int averageResourceConsumptionSinceRestart;

    QTimer timer;
    QTime timeSinceStart;
    QTime timeSinceRestart;
};


#endif // RESOURCECONSUMPTIONCONTROLLER_H
