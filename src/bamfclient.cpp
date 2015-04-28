#include "bamfclient.h"
#include <QDebug>

BamfClient::BamfClient(QObject *parent) :
    QObject(parent),
    dbusConnection(QDBusConnection::sessionBus())
{
    dbusConnection.connect("", "", "org.ayatana.bamf.matcher", "ActiveWindowChanged", this, SLOT(activeWindowChanged(QString, QString)));
}

void BamfClient::activeWindowChanged(QString old, QString current)
{
    qDebug() << "activeWindowChanged(" << old << "," << current << ")";

    QString oldWindowName = getWindowName(old);
    QString currentWindowName = getWindowName(current);

    qDebug() << "window changed" << oldWindowName << "->" << currentWindowName;

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
