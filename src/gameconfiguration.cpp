#include "gameconfiguration.h"
#include <QDebug>
#include "basemodule.h"

GameConfiguration::GameConfiguration(QString gameName, QString windowName, QObject *parent) :
    QObject(parent),
    gameName(gameName),
    windowName(windowName),
    modules(),
    settings()
{
    settings.beginGroup(gameName);

    qDebug() << "[GameConfiguration] loading configuration for" << gameName << ", enabled:" << isEnabled();
}

bool GameConfiguration::isEnabled() const
{
    return settings.value("enabled", false).toBool();
}

void GameConfiguration::setEnabled(bool enabled)
{
    settings.setValue("enabled", enabled);
}

void GameConfiguration::updateModules(QList<BaseModule*> allModules)
{
    foreach (BaseModule *module, allModules)
    {
        if (module->isEnabled(settings))
        {
            qDebug() << "[GameConfiguration] adding enabled module" << module;
            addModule(module);
        }
        else
        {
            removeModule(module);
        }
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

void GameConfiguration::addModule(BaseModule *module)
{
    if (!modules.contains(module))
    {
        modules.append(module);
    }
}

void GameConfiguration::removeModule(BaseModule *module)
{
    modules.removeAll(module);
}

void GameConfiguration::activate()
{
    Q_ASSERT_X(isEnabled(), "activate", "trying to activate a disabled game configuration");

    qDebug() << "[GameConfiguration] activating" << gameName;

    foreach (BaseModule *module, modules)
    {
        qDebug() << "[GameConfiguration] activating module:" << module;
        module->activate(settings);
    }
}


void GameConfiguration::deactivate()
{
    qDebug() << "[GameConfiguration] deactivating" << gameName;

    foreach (BaseModule *module, modules)
    {
        module->deactivate();
    }
}
