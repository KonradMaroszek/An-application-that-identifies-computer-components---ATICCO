#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    AticcoMainWIndow mainWindow;
    mainWindow.show();

    return application.exec();
}
