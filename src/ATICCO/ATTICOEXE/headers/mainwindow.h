#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class AticcoMainWIndow;
}

class AticcoMainWIndow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AticcoMainWIndow(QWidget *parent = 0);
    ~AticcoMainWIndow();

private slots:
    void changeUsbWidget();
    void setCpuTabActive();
    void setRamTabActive();
    void setDiskTabActive();
    void setNetworkTabActive();

private:
    Ui::AticcoMainWIndow *ui;

    QWidget* usbWidget;
};

#endif // MAINWINDOW_H
