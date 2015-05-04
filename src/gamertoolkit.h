#ifndef GAMERTOOLKIT_H
#define GAMERTOOLKIT_H

#include <QObject>
#include <QList>
#include "bamfclient.h"

class GameConfiguration;

class GamerToolkit : public QObject
{
    Q_OBJECT
public:
    explicit GamerToolkit(QObject *parent = 0);

public slots:
    void activeWindowChanged(QString windowName);

private:
    BamfClient bamfClient;
    QList<GameConfiguration*> gameConfigurations;

    GameConfiguration* activeWindow;

};

#endif // GAMERTOOLKIT_H
