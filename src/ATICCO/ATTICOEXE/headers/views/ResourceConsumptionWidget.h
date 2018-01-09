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
    void setCurrentResourceConsumption(const int value);
    void setAvarageResourceConsumption(const int value);
    void setAvarageResourceConsumptionSinceRestart(const int value);
    void setTimeSinceRestart(const int milisecondsSinceRestart);
    void setTimeSinceStart(const int milisecondsSinceStart);
    void hideCommandLinkButton();

private slots:
    void resetButtonClicked();

signals:
    void resetClicked();
    void moreDetailsClickedSignal();

private:
    Ui::ResourceConsumptionWidget *ui;
};

#endif // RESOURCECONSUMPTIONWIDGET_H
