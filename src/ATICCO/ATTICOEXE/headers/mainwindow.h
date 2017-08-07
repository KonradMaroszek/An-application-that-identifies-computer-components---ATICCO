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

private:
    Ui::AticcoMainWIndow *ui;
};

#endif // MAINWINDOW_H
