#ifndef RESOURCECONSUMPTIONCHARTWIDGET_CPP
#define RESOURCECONSUMPTIONCHARTWIDGET_CPP

#include "views/ResourceConsumptionChartWidget.h"
#include "ui_ResourceConsumptionChartWidget.h"

#include "AxisSettings.h"
#include "Range.h"

#define LINE_SERIES_SIZE 60

using namespace QtCharts;

void ResourceConsumptionChartWidget::setFontOnAxis(QValueAxis *axis)
{
    QFont labelsFont;
    labelsFont.setPixelSize(12);
    axis->setLabelsFont(labelsFont);
}

void ResourceConsumptionChartWidget::seColorOnAxis(QValueAxis *axis)
{
    QPen axisPen(QRgb(0xd18952));
    axisPen.setWidth(2);
    axis->setLinePen(axisPen);
}

void ResourceConsumptionChartWidget::setLabelColorOnAxis(QValueAxis *axis)
{
    QBrush axisBrush(Qt::black);
    axis->setLabelsBrush(axisBrush);
}

void ResourceConsumptionChartWidget::setShadesOnAxis(QValueAxis *axis)
{
    axis->setShadesPen(Qt::NoPen);
    axis->setShadesBrush(QBrush(QColor(0x99, 0xcc, 0xcc, 0x55)));
    axis->setShadesVisible(true);
}

QValueAxis * ResourceConsumptionChartWidget::createAxis(const AxisSettings & axisSettings)
{
    QValueAxis *axis = new QValueAxis();

    axis->setTitleText(axisSettings.getTitle());
    axis->setGridLineVisible(true);

    setFontOnAxis(axis);
    seColorOnAxis(axis);
    setLabelColorOnAxis(axis);
    setShadesOnAxis(axis);

    axis->setRange(axisSettings.getRange().getRangeStart(), axisSettings.getRange().getRangeStop());
    axis->setTickCount(axisSettings.getTickCount());
    axis->setLabelFormat(axisSettings.getLabelFormat());

    return axis;
}

QChart * ResourceConsumptionChartWidget::createChart(QValueAxis *axisX, QValueAxis *axisY)
{
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle(tr("Resource consumption"));

    chart->setMargins(QMargins(0,0,0,0));
    chart->setAxisX(axisX, series);
    chart->setAxisY(axisY, series);

    return chart;
}

QValueAxis * ResourceConsumptionChartWidget::createXAxis()
{
    Range axisXRange = Range(0, 60);
    AxisSettings axisXSettings(tr("Seconds"), axisXRange, 13, "%2i");
    QValueAxis *axisX = createAxis(axisXSettings);

    return axisX;
}

QValueAxis * ResourceConsumptionChartWidget::createYAxis()
{
    Range axisYRange = Range(0, 100);
    AxisSettings axisYSettings(tr("Percentages"), axisYRange, 11, "%3i");
    QValueAxis *axisY = createAxis(axisYSettings);

    return axisY;
}

QChartView * ResourceConsumptionChartWidget::createChartView()
{
    QValueAxis *axisX = createXAxis();
    QValueAxis *axisY = createYAxis();

    QChart *chart = createChart(axisX, axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}

ResourceConsumptionChartWidget::ResourceConsumptionChartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResourceConsumptionChartWidget)
{
    ui->setupUi(this);

    series = new QLineSeries();

    QChartView *chartView = createChartView();

    ui->resourceConsumptionChartWidgetMainVerticalLayout->addWidget(chartView);
}

ResourceConsumptionChartWidget::~ResourceConsumptionChartWidget()
{
    delete ui;
}

QLineSeries * ResourceConsumptionChartWidget::createLineSeriesWithNewValue(int value)
{
    QLineSeries* newSeries = new QLineSeries();

    newSeries->append(LINE_SERIES_SIZE, value);

    for (int i = 0; i < LINE_SERIES_SIZE; i++)
    {
        QPointF point = series->at(i);
        point.setX(point.x()-1);
        newSeries->append(point);
    }

    return newSeries;
}

void ResourceConsumptionChartWidget::updateLineSeriesOnChart(const QLineSeries* newSeries)
{
    series->clear();

    for (int i = 0; i<=LINE_SERIES_SIZE; i++)
    {
        series->append(newSeries->at(i));
    }
}

void ResourceConsumptionChartWidget::deleteSeries(QLineSeries* newSeries)
{
    newSeries->deleteLater();
}

void ResourceConsumptionChartWidget::addValueWithMovingTheAxis(int value)
{
    QLineSeries* newSeries = createLineSeriesWithNewValue(value);
    updateLineSeriesOnChart(newSeries);
    deleteSeries(newSeries);
}

void ResourceConsumptionChartWidget::newResourceConsumptionValue(int value)
{
    if (series->count() <= LINE_SERIES_SIZE)
    {
        series->append(LINE_SERIES_SIZE-series->count(), value);
    } else
    {
        addValueWithMovingTheAxis(value);
    }
}

#endif // RESOURCECONSUMPTIONCHARTWIDGET_CPP
