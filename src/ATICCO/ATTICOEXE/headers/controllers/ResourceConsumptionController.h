#ifndef RESOURCECONSUMPTIONCONTROLLER_H
#define RESOURCECONSUMPTIONCONTROLLER_H

#include <QObject>
#include <QMap>
#include "views/ResourceConsumptionWidget.h"

class ResourceConsumptionController : public QObject
{
    Q_OBJECT

public:
    explicit ResourceConsumptionController(QList<ResourceConsumptionWidget *> resourceConsumptionWidgets);
    virtual ~ResourceConsumptionController();

public slots:
    void deleteThread(int objectId);

protected slots:
    void setCurrentConsumption(int resourceConsumption);

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

protected:
    QTimer timer;
    QMap<int, QThread*> threadMap;

private:
    QList<ResourceConsumptionWidget*> resourceConsumptionWidgets;

    int ticks;
    int ticksSinceRestart;
    int currentResourceConsumption;
    int averageResourceConsumption;
    int averageResourceConsumptionSinceRestart;

    int resourceConsumption;
    int resourceConsumptionSinceRestart;

    QTime timeSinceStart;
    QTime timeSinceRestart;
};


#endif // RESOURCECONSUMPTIONCONTROLLER_H
