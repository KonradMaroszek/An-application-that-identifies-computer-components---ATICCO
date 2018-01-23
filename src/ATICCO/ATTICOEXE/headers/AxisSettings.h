#ifndef AXISSETTINGS_H
#define AXISSETTINGS_H

#include <QString>

#include "Range.h"

class AxisSettings
{
public:
    AxisSettings(const QString & title, const Range & range, int tickCount, const QString & labelFormat);
    ~AxisSettings();

public:
    QString getTitle() const;
    void setTitle(const QString &value);

    QString getLabelFormat() const;
    void setLabelFormat(const QString &value);

    Range getRange() const;
    void setRange(const Range &value);

    int getTickCount() const;
    void setTickCount(int value);

private:
    QString title;
    QString labelFormat;
    Range range;
    int tickCount;
};

#endif // AXISSETTINGS_H
