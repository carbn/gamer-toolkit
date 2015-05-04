#include "bamfclient.h"
#include <QDebug>

BamfClient::BamfClient(QObject *parent) :
    QObject(parent),
    dbusConnection(QDBusConnection::sessionBus())
{
    if (!dbusConnection.isConnected()) {
        qFatal("cannot connect to the d-bus session bus (is the dbus daemon running?)");
    }

    dbusConnection.connect("", "", "org.ayatana.bamf.matcher", "ActiveWindowChanged", this, SLOT(activeWindowChanged(QString, QString)));
}

void BamfClient::activeWindowChanged(QString old, QString current)
{
    QString oldWindowName = getWindowName(old);
    QString currentWindowName = getWindowName(current);

    qDebug() << "[BamfClient] window changed:" << oldWindowName << "->" << currentWindowName;

    emit activeWindowChanged(currentWindowName);
}

QString BamfClient::getWindowName(QString objPath)
{
    if (objPath.isEmpty())
    {
        return QString();
    }

    QDBusMessage message = QDBusMessage::createMethodCall("org.ayatana.bamf", objPath, "org.ayatana.bamf.view", "Name");
    QDBusMessage response = dbusConnection.call(message);

    if (!response.arguments().isEmpty())
    {
        return response.arguments().at(0).toString();
    }
    else
    {
        return QString();
    }
}
