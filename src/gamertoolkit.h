#ifndef GAMERTOOLKIT_H
#define GAMERTOOLKIT_H

#include <QObject>
#include "bamfclient.h"
#include "gameconfiguration.h"
#include "basemodule.h"

class GamerToolkit : public QObject
{
    Q_OBJECT
public:
    explicit GamerToolkit(QObject *parent = 0);

signals:

public slots:
    void activeWindowChanged(QString windowName);

private:
    void deactivateModules();

    BamfClient bamfClient;
    QList<BaseModule*> modules;
    QList<GameConfiguration*> gameConfigurations;

    GameConfiguration* activeWindow;

};

#endif // GAMERTOOLKIT_H
