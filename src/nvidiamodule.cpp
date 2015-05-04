#include "nvidiamodule.h"

NvidiaModule::NvidiaModule(QObject *parent) :
    BaseModule(parent),
    nvSettings(),
    vibranceIsActive(false)
{
}

void NvidiaModule::activate(QSettings &settings)
{
    settings.beginGroup(getName());
    settings.beginGroup("vibrance");

    if (settings.value("enabled", false).toBool())
    {
        nvSettings.setVibrance(settings.value("value", 0).toInt());
        vibranceIsActive = true;
    }

    settings.endGroup();
    settings.endGroup();
}

void NvidiaModule::deactivate()
{
    if (vibranceIsActive)
    {
        nvSettings.setVibrance(0);
    }
}

QString NvidiaModule::getName() const
{
    return "nvidia";
}
