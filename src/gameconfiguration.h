#ifndef GAMECONFIGURATION_H
#define GAMECONFIGURATION_H

#include <QObject>
#include <QSettings>

class BaseModule;

class GameConfiguration : public QObject
{
    Q_OBJECT
public:
    explicit GameConfiguration(QString gameName, QString windowName, QObject *parent = 0);

    void activate();
    void deactivate();

    QString getGameName() const;
    QString getWindowName() const;

    bool isEnabled() const;
    void setEnabled(bool enabled);

private:
    void createModules();

    QString gameName;
    QString windowName;
    QSettings settings;
    QList<BaseModule*> modules;
};

#endif // GAMECONFIGURATION_H
