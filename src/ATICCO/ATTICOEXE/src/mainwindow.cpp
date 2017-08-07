#include "mainwindow.h"
#include "ui_mainwindow.h"

AticcoMainWIndow::AticcoMainWIndow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AticcoMainWIndow)
{
    ui->setupUi(this);
}

AticcoMainWIndow::~AticcoMainWIndow()
{
    delete ui;
}
