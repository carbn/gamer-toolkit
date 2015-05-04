#include "basemodule.h"

BaseModule::BaseModule(QSettings *settings, QObject *parent) :
    QObject(parent),
    active(false),
    settings(settings)
{
}

BaseModule::~BaseModule()
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

bool BaseModule::isEnabled() const
{
    return getSettingsValue("enabled", false).toBool();
}

void BaseModule::setEnabled(bool enabled)
{
    setSettingsValue("enabled", enabled);
}

QVariant BaseModule::getSettingsValue(QString const& key, QVariant const& defaultValue) const
{
    return settings->value(getName() + "/" + key, defaultValue);
}

void BaseModule::setSettingsValue(QString const& key, QVariant const& value)
{
    return settings->setValue(getName() + "/" + key, value);
}
