#ifndef WINDOWMONITOR_H
#define WINDOWMONITOR_H

#include <QObject>
#include "bamfclient.h"
#include "nvidiasettings.h"

class WindowMonitor : public QObject
{
    Q_OBJECT
public:
    explicit WindowMonitor(QString monitoredWindowName, QObject *parent = 0);
    virtual ~WindowMonitor();

private slots:
    void activeWindowChanged(QString windowName);

private:
    BamfClient bamfClient;
    NvidiaSettings nvSettings;

    QString monitoredWindowName;
    bool monitoredWindowIsActive;

};

#endif // WINDOWMONITOR_H
