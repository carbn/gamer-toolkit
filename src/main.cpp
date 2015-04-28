#include <QApplication>
#include <QtDBus/QtDBus>
#include "windowmonitor.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!QDBusConnection::sessionBus().isConnected()) {
        fprintf(stderr, "Cannot connect to the D-Bus session bus.\n"
                "To start it, run:\n"
                "\teval `dbus-launch --auto-syntax`\n");
        return 1;
    }

    WindowMonitor monitor("System Settings");

    MainWindow w;
    w.show();

    return a.exec();
}
