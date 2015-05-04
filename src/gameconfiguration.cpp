#include "gameconfiguration.h"
#include <QDebug>
#include "basemodule.h"
#include "customcommandmodule.h"
#include "nvidiamodule.h"

GameConfiguration::GameConfiguration(QString gameName, QString windowName, QObject *parent) :
    QObject(parent),
    gameName(gameName),
    windowName(windowName),
    settings(),
    modules()
{
    qDebug() << "[GameConfiguration] loading configuration for" << gameName;

    settings.beginGroup(gameName);

    createModules();
}

void GameConfiguration::activate()
{
    Q_ASSERT_X(isEnabled(), "activate", "trying to activate a disabled game configuration");

    qDebug() << "[GameConfiguration] activating" << gameName;

    foreach (BaseModule *module, modules)
    {
        module->activate();
    }
}

void GameConfiguration::deactivate()
{
    qDebug() << "[GameConfiguration] de-activating" << gameName;

    foreach (BaseModule *module, modules)
    {
        module->deactivate();
    }
}

QString GameConfiguration::getGameName() const
{
    return gameName;
}

QString GameConfiguration::getWindowName() const
{
    return windowName;
}

bool GameConfiguration::isEnabled() const
{
    return settings.value("enabled", false).toBool();
}

void GameConfiguration::setEnabled(bool enabled)
{
    settings.setValue("enabled", enabled);
}

void GameConfiguration::createModules()
{
    qDebug() << "[GameConfiguration] creating modules";

    modules.append(new CustomCommandModule(&settings, this));
    modules.append(new NvidiaModule(&settings, this));
}
