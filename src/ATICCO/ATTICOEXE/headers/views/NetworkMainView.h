#ifndef NETWORKMAINVIEW_H
#define NETWORKMAINVIEW_H

#include "views/MainComponentViewTemplate.h"

class NetworkMainView : protected MainComponentViewTemplate
{
    Q_OBJECT

public:
    explicit NetworkMainView(QWidget *parent = 0);
    ~NetworkMainView();

    void setResourceConsumptionWidget(ResourceConsumptionWidget *value);
    void setResourceConsumptionChartWidget(ResourceConsumptionChartWidget *value);

public slots:
    void setName(const QString string);
    void setCardName(const QString string);
    void setSSID(const QString string);
    void setDNSname(const QString string);
    void setTypeOfConnection(const QString string);
    void setIPv4Address(const QString string);
    void setIPv6Address(const QString string);
    void setUploadSpeed(const QString string);
    void setDownloadSpeed(const QString string);
};

#endif // NETWORKMAINVIEW_H
