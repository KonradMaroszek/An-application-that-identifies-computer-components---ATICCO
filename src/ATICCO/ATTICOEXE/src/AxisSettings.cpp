#include "AxisSettings.h"

AxisSettings::AxisSettings(const QString &title, const Range &range, int tickCount, const QString &labelFormat) :
    title(title),
    range(range),
    tickCount(tickCount),
    labelFormat(labelFormat)
{

}

AxisSettings::~AxisSettings()
{

}

QString AxisSettings::getTitle() const
{
    return title;
}

void AxisSettings::setTitle(const QString &value)
{
    title = value;
}

QString AxisSettings::getLabelFormat() const
{
    return labelFormat;
}

void AxisSettings::setLabelFormat(const QString &value)
{
    labelFormat = value;
}

Range AxisSettings::getRange() const
{
    return range;
}

void AxisSettings::setRange(const Range &value)
{
    range = value;
}

int AxisSettings::getTickCount() const
{
    return tickCount;
}

void AxisSettings::setTickCount(int value)
{
    tickCount = value;
}
