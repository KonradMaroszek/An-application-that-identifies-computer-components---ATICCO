#include "views/RamMainView.h"

RamMainView::RamMainView(QWidget *parent) : MainComponentViewTemplate(parent)
{
    MainComponentViewTemplate::setTitleLabelLeft(tr("Number of memory chips:"));
    MainComponentViewTemplate::setFirstLabelLeft(tr("Capacity:"));
    MainComponentViewTemplate::setSecondLabelLeft(tr("Speed:"));
    MainComponentViewTemplate::setThirdLabelLeft(tr("Type:"));
    MainComponentViewTemplate::setFourthLabelLeft(tr("Data width:"));
    MainComponentViewTemplate::setFifthLabelLeft(tr("Total width:"));
    MainComponentViewTemplate::setSixthLabelLeft(tr("Manufactures:"));
    MainComponentViewTemplate::setSeventhLabelLeft(tr("Part numbers:"));
    MainComponentViewTemplate::setEigthLabelLeft(tr("Serial numbers:"));
}

RamMainView::~RamMainView()
{

}

void RamMainView::setResourceConsumptionWidget(ResourceConsumptionWidget *value)
{
    MainComponentViewTemplate::setResourceConsumptionWidget(value);
}

void RamMainView::setResourceConsumptionChartWidget(ResourceConsumptionChartWidget *value)
{
    MainComponentViewTemplate::setResourceConsumptionChartWidget(value);
}

void RamMainView::setNumberOfMemoryChips(const QString string)
{
    MainComponentViewTemplate::setTitleLabelRight(string);
}

void RamMainView::setCapacity(const QString string)
{
    MainComponentViewTemplate::setFirstLabelRight(string);
}

void RamMainView::setSpeed(const QString string)
{
    MainComponentViewTemplate::setSecondLabelRight(string);
}

void RamMainView::setType(const QString string)
{
    MainComponentViewTemplate::setThirdLabelRight(string);
}

void RamMainView::setDataWidth(const QString string)
{
    MainComponentViewTemplate::setFourthLabelRight(string);
}

void RamMainView::setTotalWidth(const QString string)
{
    MainComponentViewTemplate::setFifthLabelRight(string);
}

void RamMainView::setManufactuers(const QString string)
{
    MainComponentViewTemplate::setSixthLabelRight(string);
}

void RamMainView::setPartNumbers(const QString string)
{
    MainComponentViewTemplate::setSeventhLabelRight(string);
}

void RamMainView::setSerialNumbers(const QString string)
{
    MainComponentViewTemplate::setEigthLabelRight(string);
}
