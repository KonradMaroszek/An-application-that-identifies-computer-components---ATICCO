#include "views/NetworkMainView.h"

NetworkMainView::NetworkMainView(QWidget *parent) : MainComponentViewTemplate(parent)
{
    MainComponentViewTemplate::setTitleLabelLeft(tr("Name:"));
    MainComponentViewTemplate::setFirstLabelLeft(tr("Card name:"));
    MainComponentViewTemplate::setSecondLabelLeft(tr("SSID:"));
    MainComponentViewTemplate::setThirdLabelLeft(tr("DNS Name:"));
    MainComponentViewTemplate::setFourthLabelLeft(tr("Type of connection:"));
    MainComponentViewTemplate::setFifthLabelLeft(tr("Address IPv4:"));
    MainComponentViewTemplate::setSixthLabelLeft(tr("Address IPv6:"));
    MainComponentViewTemplate::setSeventhLabelLeft(tr("Upload speed:"));
    MainComponentViewTemplate::setEigthLabelLeft(tr("Download speed:"));
}

NetworkMainView::~NetworkMainView()
{

}

void NetworkMainView::setResourceConsumptionWidget(ResourceConsumptionWidget *value)
{
    MainComponentViewTemplate::setResourceConsumptionWidget(value);
}

void NetworkMainView::setResourceConsumptionChartWidget(ResourceConsumptionChartWidget *value)
{
    MainComponentViewTemplate::setResourceConsumptionChartWidget(value);
}

void NetworkMainView::setName(const QString string)
{
    MainComponentViewTemplate::setTitleLabelRight(string);
}

void NetworkMainView::setCardName(const QString string)
{
    MainComponentViewTemplate::setFirstLabelRight(string);
}

void NetworkMainView::setSSID(const QString string)
{
    MainComponentViewTemplate::setSecondLabelRight(string);
}

void NetworkMainView::setDNSname(const QString string)
{
    MainComponentViewTemplate::setThirdLabelRight(string);
}

void NetworkMainView::setTypeOfConnection(const QString string)
{
    MainComponentViewTemplate::setFourthLabelRight(string);
}

void NetworkMainView::setIPv4Address(const QString string)
{
    MainComponentViewTemplate::setFifthLabelRight(string);
}

void NetworkMainView::setIPv6Address(const QString string)
{
    MainComponentViewTemplate::setSixthLabelRight(string);
}

void NetworkMainView::setUploadSpeed(const QString string)
{
    MainComponentViewTemplate::setSeventhLabelRight(string);
}

void NetworkMainView::setDownloadSpeed(const QString string)
{
    MainComponentViewTemplate::setEigthLabelRight(string);
}
