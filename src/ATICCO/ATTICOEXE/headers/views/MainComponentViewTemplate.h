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

protected:
    explicit MainComponentViewTemplate(QWidget *parent = 0);
    virtual ~MainComponentViewTemplate();

    void setResourceConsumptionWidget(ResourceConsumptionWidget *value);
    void setResourceConsumptionChartWidget(ResourceConsumptionChartWidget *value);

protected slots:
    void setTitleLabelLeft(const QString string);
    void setTitleLabelRight(const QString string);

    void setFirstLabelLeft(const QString string);
    void setFirstLabelRight(const QString string);

    void setSecondLabelLeft(const QString string);
    void setSecondLabelRight(const QString string);

    void setThirdLabelLeft(const QString string);
    void setThirdLabelRight(const QString string);

    void setFourthLabelLeft(const QString string);
    void setFourthLabelRight(const QString string);

    void setFifthLabelLeft(const QString string);
    void setFifthLabelRight(const QString string);

    void setSixthLabelLeft(const QString string);
    void setSixthLabelRight(const QString string);

    void setSeventhLabelLeft(const QString string);
    void setSeventhLabelRight(const QString string);

    void setEigthLabelLeft(const QString string);
    void setEigthLabelRight(const QString string);

private:
    Ui::MainComponentViewTemplate *ui;
    ResourceConsumptionWidget* resourceConsumptionWidget;
    ResourceConsumptionChartWidget* resourceConsumptionChartWidget;
};

#endif // MAINCOMPONENTVIEWTEMPLATE_H
