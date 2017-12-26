#ifndef RAMMAINVIEW_H
#define RAMMAINVIEW_H

#include "views/MainComponentViewTemplate.h"

class RamMainView : protected MainComponentViewTemplate
{
    Q_OBJECT

public:
    explicit RamMainView(QWidget *parent = 0);
    virtual ~RamMainView();

    void setResourceConsumptionWidget(ResourceConsumptionWidget *value);
    void setResourceConsumptionChartWidget(ResourceConsumptionChartWidget *value);

public slots:
    void setNumberOfMemoryChips(const QString string);
    void setCapacity(const QString string);
    void setSpeed(const QString string);
    void setType(const QString string);
    void setDataWidth(const QString string);
    void setTotalWidth(const QString string);
    void setManufactuers(const QString string);
    void setPartNumbers(const QString string);
    void setSerialNumbers(const QString string);
};

#endif // RAMMAINVIEW_H
