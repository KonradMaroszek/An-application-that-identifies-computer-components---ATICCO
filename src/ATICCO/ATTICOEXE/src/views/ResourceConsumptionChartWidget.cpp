#ifndef RESOURCECONSUMPTIONCHARTWIDGET_CPP
#define RESOURCECONSUMPTIONCHARTWIDGET_CPP

#include <views/ResourceConsumptionChartWidget.h>
#include "ui_ResourceConsumptionChartWidget.h"

using namespace QtCharts;

ResourceConsumptionChartWidget::ResourceConsumptionChartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResourceConsumptionChartWidget)
{
    ui->setupUi(this);

    series = new QLineSeries();

    QValueAxis *axisX = new QValueAxis();
    QValueAxis *axisY = new QValueAxis();

    axisX->setTitleText("Seconds");
    axisY->setTitleText("Percentages");

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);

    chart->setTitle("Resource consumption");

    // Customize axis label font
    QFont labelsFont;
    labelsFont.setPixelSize(12);
    axisX->setLabelsFont(labelsFont);
    axisY->setLabelsFont(labelsFont);

    // Customize axis colors
    QPen axisPen(QRgb(0xd18952));
    axisPen.setWidth(2);
    axisX->setLinePen(axisPen);
    axisY->setLinePen(axisPen);

    // Customize axis label colors
    QBrush axisBrush(Qt::black);
    axisX->setLabelsBrush(axisBrush);
    axisY->setLabelsBrush(axisBrush);

    // Customize grid lines and shades
    axisX->setGridLineVisible(true);
    axisY->setGridLineVisible(true);
    axisY->setShadesPen(Qt::NoPen);
    axisY->setShadesBrush(QBrush(QColor(0x99, 0xcc, 0xcc, 0x55)));
    axisY->setShadesVisible(true);

    axisX->setRange(0, 60);
    axisX->setTickCount(13);
    axisX->setLabelFormat("%2i");

    axisY->setRange(0, 100);
    axisY->setTickCount(11);
    axisY->setLabelFormat("%3i");

    chart->setMargins(QMargins(0,0,0,0));
    chart->setAxisX(axisX, series);
    chart->setAxisY(axisY, series);


    QGraphicsLayout* chartViewLayout= chart->layout();
    chartViewLayout->setContentsMargins(0,0,0,0);

    QChartView *chartView = new QChartView(chart);

    chartView->setRenderHint(QPainter::Antialiasing);

    ui->resourceConsumptionChartWidgetMainVerticalLayout->addWidget(chartView);
}

ResourceConsumptionChartWidget::~ResourceConsumptionChartWidget()
{
    delete ui;
}

void ResourceConsumptionChartWidget::newResourceConsumptionValue(int value)
{
    if (series->count() < 61) {
        series->append(60-series->count(), value);
    } else {
        QLineSeries tmp;

        tmp.append(60, value);

        for (int i = 0; i < 60; i++)
        {
            QPointF point = series->at(i);
            point.setX(point.x()-1);
            tmp.append(point);
        }

        series->clear();

        for (int i = 0; i<=60; i++) {
            series->append(tmp.at(i));
        }
    }
}

#endif // RESOURCECONSUMPTIONCHARTWIDGET_CPP
