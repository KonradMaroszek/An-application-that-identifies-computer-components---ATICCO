#ifndef RESOURECONSUMPTIONCHARTWIDGET_H
#define RESOURECONSUMPTIONCHARTWIDGET_H

#include <QWidget>
#include <QtCharts>

namespace Ui {
class ResourceConsumptionChartWidget;
}

class ResourceConsumptionChartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ResourceConsumptionChartWidget(QWidget *parent = 0);
    ~ResourceConsumptionChartWidget();

public slots:
    void newResourceConsumptionValue(int value);

private slots:

signals:

private:
    Ui::ResourceConsumptionChartWidget *ui;

    QLineSeries* series;
};

#endif // RESOURECONSUMPTIONCHARTWIDGET_H
