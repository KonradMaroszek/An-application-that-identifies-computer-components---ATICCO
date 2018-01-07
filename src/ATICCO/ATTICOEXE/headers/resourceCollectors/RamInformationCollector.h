#ifndef RAMINFORMATIONCOLLECTOR_H
#define RAMINFORMATIONCOLLECTOR_H

#include "resourceCollectors/ResourceCollector.h"

class RamInformationCollector : public ResourceCollector
{
    Q_OBJECT
public:
        RamInformationCollector();
        virtual ~RamInformationCollector();

private:
    virtual void run();

signals:
    void ramNumberOfMemoryChipsCollected(const QString string);
    void ramCapacityCollected(const QString string);
    void ramSpeedCollected(const QString string);
    void ramTypeCollected(const QString string);
    void ramDataWidthCollected(const QString string);
    void ramTotalWidthCollected(const QString string);
    void ramManufactuersCollected(const QString string);
    void ramPartNumbersCollected(const QString string);
    void ramSerialNumbersCollected(const QString string);
};

#endif // RAMINFORMATIONCOLLECTOR_H
