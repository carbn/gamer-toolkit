#include "nvidiamodule.h"
#include <QDebug>

NvidiaModule::NvidiaModule(QSettings *settings, QObject *parent) :
    BaseModule(settings, parent),
    nvSettings(),
    vibranceIsActive(false)
{
    qDebug() << "[NvidiaModule] created";
}

void NvidiaModule::activate()
{
    qDebug() << "[NvidiaModule] activating";

    if (getSettingsValue("vibrance/enabled", false).toBool())
    {
        nvSettings.setVibrance(getSettingsValue("vibrance/value", 0).toInt());
        vibranceIsActive = true;
    }
}

void NvidiaModule::deactivate()
{
    qDebug() << "[NvidiaModule] de-activating";

    if (vibranceIsActive)
    {
        nvSettings.setVibrance(0);
        vibranceIsActive = false;
    }
}

QString NvidiaModule::getName() const
{
    return "nvidia";
}
