#ifndef RESOURCECONSUMPTIONWIDGET_H
#define RESOURCECONSUMPTIONWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QLabel>

namespace Ui {
class ResourceConsumptionWidget;
}

class ResourceConsumptionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ResourceConsumptionWidget(QWidget *parent = 0);
    ~ResourceConsumptionWidget();

public slots:
    void setTitle(QString & title);
    void setCurrentResourceConsumption(int value);
    void setAvarageResourceConsumption(int value);
    void setAvarageResourceConsumptionSinceRestart(int value);

private slots:
    void resetRestartClock();
    void refreshTime();
    void setTextValues();
    void setRestartTime(int milisecondsSinceRestart);
    void setTime(int milisecondsSinceStart);

signals:
    void resetClicked();
    void moreDetailsSignal();

private:
    Ui::ResourceConsumptionWidget *ui;
    QTimer timer;
    QTime timeSinceStart;
    QTime timeSinceRestart;

    int currentResourceConsumption;
    int averageResourceConsumption;
    int averageResourceConsumptionSinceRestart;
};

#endif // RESOURCECONSUMPTIONWIDGET_H
