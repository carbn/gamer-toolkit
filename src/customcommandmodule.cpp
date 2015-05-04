#include "customcommandmodule.h"
#include <QDebug>
#include <QProcess>

CustomCommandModule::CustomCommandModule(QSettings *settings, QObject *parent) :
    BaseModule(settings, parent)
{
    qDebug() << "[CustomCommandModule] created";
}

void CustomCommandModule::activate()
{
    qDebug() << "[CustomCommandModule] activating";

    if (getSettingsValue("on_activation/enabled", false).toBool())
    {
        run(getSettingsValue("on_activation/command", "").toString());
    }
}

void CustomCommandModule::deactivate()
{
    qDebug() << "[CustomCommandModule] de-activating";

    if (getSettingsValue("on_deactivation/enabled", false).toBool())
    {
        run(getSettingsValue("on_deactivation/command", "").toString());
    }
}

void CustomCommandModule::run(QString const& command) const
{
    if (!command.isEmpty())
    {
        qDebug() << "[CustomCommandModule] executing:" << command;

        int ret = QProcess::execute("/bin/sh", QStringList() << "-c" << command);

        if (ret != 0)
        {
            qWarning() << "[CustomCommandModule] command failed with code" << ret;
        }
    }
}
