#ifndef RESOURECONSUMPTIONCHARTWIDGET_H
#define RESOURECONSUMPTIONCHARTWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QLabel>

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

private slots:

signals:

private:
    Ui::ResourceConsumptionChartWidget *ui;
};

#endif // RESOURECONSUMPTIONCHARTWIDGET_H
