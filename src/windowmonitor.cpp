#include "windowmonitor.h"

WindowMonitor::WindowMonitor(QString monitoredWindowName, QObject *parent) :
    QObject(parent),
    bamfClient(),
    nvSettings(),
    monitoredWindowName(monitoredWindowName),
    monitoredWindowIsActive(false)
{
    connect(&bamfClient, SIGNAL(activeWindowChanged(QString)), this, SLOT(activeWindowChanged(QString)));
}

WindowMonitor::~WindowMonitor()
{
    if (monitoredWindowIsActive)
    {
        nvSettings.resetVibrance();
    }
}

void WindowMonitor::activeWindowChanged(QString windowName)
{
    bool isTargetWindow = (windowName.indexOf(monitoredWindowName) != -1);

    if (isTargetWindow && !monitoredWindowIsActive)
    {
        qDebug() << "monitored window activated";
        monitoredWindowIsActive = true;

        nvSettings.setVibrance();
    }
    else if (!isTargetWindow && monitoredWindowIsActive)
    {
        qDebug() << "monitored window deactivated";
        monitoredWindowIsActive = false;

        nvSettings.resetVibrance();
    }
}
