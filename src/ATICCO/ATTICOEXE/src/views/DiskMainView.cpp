#include "views/DiskMainView.h"

DiskMainView::DiskMainView(QWidget *parent) : MainComponentViewTemplate(parent)
{
    MainComponentViewTemplate::setTitleLabelLeft(tr("Disk model:"));
    MainComponentViewTemplate::setFirstLabelLeft(tr("Size in bytes:"));
    MainComponentViewTemplate::setSecondLabelLeft(tr("Free space in bytes:"));
    MainComponentViewTemplate::setThirdLabelLeft(tr("Free space (%):"));
    MainComponentViewTemplate::setFourthLabelLeft(tr("File system type:"));
    MainComponentViewTemplate::setFifthLabelLeft(tr("Read speed:"));
    MainComponentViewTemplate::setSixthLabelLeft(tr("Write speed:"));
    MainComponentViewTemplate::setSeventhLabelLeft(tr("Avarage response time:"));
    MainComponentViewTemplate::setEigthLabelLeft(tr("Id:"));
}

DiskMainView::~DiskMainView()
{

}

void DiskMainView::setResourceConsumptionWidget(ResourceConsumptionWidget *value)
{
    MainComponentViewTemplate::setResourceConsumptionWidget(value);
}

void DiskMainView::setResourceConsumptionChartWidget(ResourceConsumptionChartWidget *value)
{
    MainComponentViewTemplate::setResourceConsumptionChartWidget(value);
}

void DiskMainView::setModel(const QString string)
{
    MainComponentViewTemplate::setTitleLabelRight(string);
}

void DiskMainView::setSize(const QString string)
{
    MainComponentViewTemplate::setFirstLabelRight(string);
}

void DiskMainView::setFreeSpace(const QString string)
{
    MainComponentViewTemplate::setSecondLabelRight(string);
}

void DiskMainView::setFreeSpaceInPercentage(const QString string)
{
    MainComponentViewTemplate::setThirdLabelRight(string);
}

void DiskMainView::setFileSystemType(const QString string)
{
    MainComponentViewTemplate::setFourthLabelRight(string);
}

void DiskMainView::setReadSpeed(const QString string)
{
    MainComponentViewTemplate::setFifthLabelRight(string);
}

void DiskMainView::setWriteSpeed(const QString string)
{
    MainComponentViewTemplate::setSixthLabelRight(string);
}

void DiskMainView::setAverageResponseTime(const QString string)
{
    MainComponentViewTemplate::setSeventhLabelRight(string);
}

void DiskMainView::setId(const QString string)
{
    MainComponentViewTemplate::setEigthLabelRight(string);
}
