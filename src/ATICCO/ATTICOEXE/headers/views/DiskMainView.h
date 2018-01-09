#ifndef DISKMAINVIEW_H
#define DISKMAINVIEW_H

#include "views/MainComponentViewTemplate.h"

class DiskMainView : protected MainComponentViewTemplate
{
    Q_OBJECT

public:
    explicit DiskMainView(QWidget *parent = 0);
    virtual ~DiskMainView();

    void setResourceConsumptionWidget(ResourceConsumptionWidget *value);
    void setResourceConsumptionChartWidget(ResourceConsumptionChartWidget *value);

public slots:
    void setModel(const QString string);
    void setSize(const QString string);
    void setFreeSpace(const QString string);
    void setFreeSpaceInPercentage(const QString string);
    void setFileSystemType(const QString string);
    void setReadSpeed(const QString string);
    void setWriteSpeed(const QString string);
    void setReadWriteSpeed(const QString string);
    void setId(const QString string);
};

#endif // DISKMAINVIEW_H
