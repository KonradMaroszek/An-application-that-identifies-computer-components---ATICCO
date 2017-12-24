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
    explicit ResourceConsumptionController(QList<ResourceConsumptionWidget *> resourceConsumptionWidgets);
    ~ResourceConsumptionController();

public slots:

private slots:
    void resetRestartClock();
    void refreshTime();
    void refreshCurrentResourceConsumption();
    void refreshAvarageResourceConsumption();
    void refreshAvarageResourceConsumptionSinceRestart();

signals:
    void timeSinceRestartChanged(int);
    void timeSinceStartChanged(int);

    void currentResourceConsumptionChanged(int);
    void avarageResourceConsumptionChanged(int);
    void avarageResourceConsumptionSinceRestartChanged(int);

private:
    QList<ResourceConsumptionWidget*> resourceConsumptionWidgets;

    int ticks;
    int ticksSinceRestart;
    int currentResourceConsumption;
    int averageResourceConsumption;
    int averageResourceConsumptionSinceRestart;

    int resourceConsumption;
    int resourceConsumptionSinceRestart;

    QTimer timer;
    QTime timeSinceStart;
    QTime timeSinceRestart;
};


#endif // RESOURCECONSUMPTIONCONTROLLER_H
