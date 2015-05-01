#ifndef GAMERTOOLKIT_H
#define GAMERTOOLKIT_H

#include <QObject>
#include "bamfclient.h"
#include "nvidiasettings.h"
#include "gameconfiguration.h"

class GamerToolkit : public QObject
{
    Q_OBJECT
public:
    explicit GamerToolkit(QObject *parent = 0);

signals:

public slots:
    void activeWindowChanged(QString windowName);

private:
    NvidiaSettings nvSettings;
    BamfClient bamfClient;
    QList<GameConfiguration*> gameConfigurations;

    GameConfiguration* activeWindow;

};

#endif // GAMERTOOLKIT_H
