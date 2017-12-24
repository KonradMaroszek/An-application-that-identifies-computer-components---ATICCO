#ifndef MAINCOMPONENTVIEWTEMPLATE_H
#define MAINCOMPONENTVIEWTEMPLATE_H

#include <QWidget>
#include "views/ResourceConsumptionWidget.h"
#include "views/ResourceConsumptionChartWidget.h"

namespace Ui {
class MainComponentViewTemplate;
}

class MainComponentViewTemplate : public QWidget
{
    Q_OBJECT

public:
    explicit MainComponentViewTemplate(QWidget *parent = 0);
    ~MainComponentViewTemplate();

    void setResourceConsumptionWidget(ResourceConsumptionWidget *value);
    void setResourceConsumptionChartWidget(ResourceConsumptionChartWidget *value);

public slots:


private slots:


signals:


private:
    Ui::MainComponentViewTemplate *ui;
    ResourceConsumptionWidget* resourceConsumptionWidget;
    ResourceConsumptionChartWidget* resourceConsumptionChartWidget;
};

#endif // MAINCOMPONENTVIEWTEMPLATE_H
