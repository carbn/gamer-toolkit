#ifndef BAMFCLIENT_H
#define BAMFCLIENT_H

#include <QObject>
#include <QtDBus>

class BamfClient : public QObject
{
    Q_OBJECT
public:
    explicit BamfClient(QObject *parent = 0);

signals:
    void activeWindowChanged(QString windowName);

private slots:
    void activeWindowChanged(QString old, QString current);

private:
    QString getWindowName(QString objPath);

    QDBusConnection dbusConnection;
};

#endif // BAMFCLIENT_H
