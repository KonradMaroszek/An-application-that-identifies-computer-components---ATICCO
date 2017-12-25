#include "views/CpuMainView.h"

CpuMainView::CpuMainView(QWidget *parent) : MainComponentViewTemplate(parent)
{
    MainComponentViewTemplate::setTitleLabelLeft(tr("Processor name:"));
    MainComponentViewTemplate::setFirstLabelLeft(tr("Current clock speed:"));
    MainComponentViewTemplate::setSecondLabelLeft(tr("Max clock speed:"));
    MainComponentViewTemplate::setThirdLabelLeft(tr("Number of cores:"));
    MainComponentViewTemplate::setFourthLabelLeft(tr("Manufactuer:"));
    MainComponentViewTemplate::setFifthLabelLeft(tr("Address width:"));
    MainComponentViewTemplate::setSixthLabelLeft(tr("Data width:"));
    MainComponentViewTemplate::setSeventhLabelLeft(tr("Current voltage:"));
    MainComponentViewTemplate::setEigthLabelLeft(tr("Id:"));
}

CpuMainView::~CpuMainView()
{

}

void CpuMainView::setResourceConsumptionWidget(ResourceConsumptionWidget *value)
{
    MainComponentViewTemplate::setResourceConsumptionWidget(value);
}

void CpuMainView::setResourceConsumptionChartWidget(ResourceConsumptionChartWidget *value)
{
    MainComponentViewTemplate::setResourceConsumptionChartWidget(value);
}

void CpuMainView::setName(const QString string)
{
    MainComponentViewTemplate::setTitleLabelRight(string);
}

void CpuMainView::setMaxClockSpeed(const QString string)
{
    MainComponentViewTemplate::setFirstLabelRight(string);
}

void CpuMainView::setCurrentClockSpeed(const QString string)
{
    MainComponentViewTemplate::setSecondLabelRight(string);
}

void CpuMainView::setNumberOfCores(const QString string)
{
    MainComponentViewTemplate::setThirdLabelRight(string);
}

void CpuMainView::setManufactuer(const QString string)
{
    MainComponentViewTemplate::setFourthLabelRight(string);
}

void CpuMainView::setAddressWidth(const QString string)
{
    MainComponentViewTemplate::setFifthLabelRight(string);
}

void CpuMainView::setDataWidth(const QString string)
{
    MainComponentViewTemplate::setSixthLabelRight(string);
}

void CpuMainView::setCurrentVoltage(const QString string)
{
    MainComponentViewTemplate::setSeventhLabelRight(string);
}

void CpuMainView::setId(const QString string)
{
    MainComponentViewTemplate::setEigthLabelRight(string);
}
