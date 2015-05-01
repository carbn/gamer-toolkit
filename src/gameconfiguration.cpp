#include "gameconfiguration.h"
#include <QDebug>

GameConfiguration::GameConfiguration(QString gameName, QString windowName, QObject *parent) :
    QObject(parent),
    gameName(gameName),
    windowName(windowName)
{
}

void GameConfiguration::activate()
{
    qDebug() << "activating" << gameName;

    emit setVibrance(1000);
}


void GameConfiguration::deactivate()
{
    qDebug() << "deactivating" << gameName;

    emit resetVibrance();
}

QString GameConfiguration::getGameName() const
{
    return gameName;
}

QString GameConfiguration::getWindowName() const
{
    return windowName;
}
