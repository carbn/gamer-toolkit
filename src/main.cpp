#include <QApplication>
#include "mainwindow.h"
#include "gamertoolkit.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GamerToolkit toolkit;

    MainWindow w;
    w.show();

    return a.exec();
}
