#ifndef CPUMAINVIEW_H
#define CPUMAINVIEW_H

#include "views/MainComponentViewTemplate.h"

class CpuMainView : protected MainComponentViewTemplate
{
    Q_OBJECT

public:
    explicit CpuMainView(QWidget *parent = 0);
    ~CpuMainView();

    void setResourceConsumptionWidget(ResourceConsumptionWidget *value);
    void setResourceConsumptionChartWidget(ResourceConsumptionChartWidget *value);

public slots:
    void setName(const QString string);
    void setMaxClockSpeed(const QString string);
    void setCurrentClockSpeed(const QString string);
    void setNumberOfCores(const QString string);
    void setManufactuer(const QString string);
    void setAddressWidth(const QString string);
    void setDataWidth(const QString string);
    void setCurrentVoltage(const QString string);
    void setId(const QString string);
};

#endif // CPUMAINVIEW_H
