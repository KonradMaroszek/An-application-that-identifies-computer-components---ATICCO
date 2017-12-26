#ifndef RESOURECONSUMPTIONCHARTWIDGET_H
#define RESOURECONSUMPTIONCHARTWIDGET_H

#include <QWidget>
#include <QtCharts>

#include "AxisSettings.h"

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
    void addValueWithMovingTheAxis(int value);
    
private:
    QLineSeries *createLineSeriesWithNewValue(int value);
    void updateLineSeriesOnChart(const QLineSeries *newSeries);
    void deleteSeries(QLineSeries *newSeries);

    void setFontOnAxis(QValueAxis *axis);
    void seColorOnAxis(QValueAxis *axis);
    void setLabelColorOnAxis(QValueAxis *axis);
    void setShadesOnAxis(QValueAxis *axis);

    QValueAxis * createAxis(const AxisSettings &axisSettings);
    QChart * createChart(QValueAxis *axisX, QValueAxis *axisY);
    QValueAxis * createXAxis();
    QValueAxis * createYAxis();
    QChartView * createChartView();
private:
    Ui::ResourceConsumptionChartWidget *ui;
    QLineSeries* series;
};

#endif // RESOURECONSUMPTIONCHARTWIDGET_H
