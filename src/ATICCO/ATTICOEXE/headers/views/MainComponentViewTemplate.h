#ifndef MAINCOMPONENTVIEWTEMPLATE_H
#define MAINCOMPONENTVIEWTEMPLATE_H

#include <QWidget>
#include "views/ResourceConsumptionWidget.h"

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

public slots:


private slots:


signals:


private:
    Ui::MainComponentViewTemplate *ui;
    ResourceConsumptionWidget* resourceConsumptionWidget;
};

#endif // MAINCOMPONENTVIEWTEMPLATE_H
