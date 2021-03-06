#ifndef WIDGETCREATOR_H
#define WIDGETCREATOR_H

#include <QWidget>

class WidgetCreator
{
public:
    WidgetCreator() {}
    virtual ~WidgetCreator() {}
    virtual QWidget* createWidget() = 0;
};

#endif // WIDGETCREATOR_H
