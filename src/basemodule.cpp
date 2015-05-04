#include "basemodule.h"

BaseModule::BaseModule(QObject *parent) :
    QObject(parent),
    active(false)
{
}

bool BaseModule::isActive() const
{
    return active;
}

void BaseModule::setActive(bool active)
{
    this->active = active;
}

bool BaseModule::isEnabled(QSettings &settings) const
{
    settings.beginGroup(getName());
    bool enabled = settings.value("enabled", false).toBool();
    settings.endGroup();

    return enabled;
}
