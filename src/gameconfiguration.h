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

    QString getGameName() const;
    QString getWindowName() const;

    bool isEnabled() const;
    void setEnabled(bool enabled);

    void updateModules(QList<BaseModule*> allModules);

public slots:
    void addModule(BaseModule *module);
    void removeModule(BaseModule *module);

    void activate();
    void deactivate();

private:
    QString gameName;
    QString windowName;
    QList<BaseModule*> modules;
    QSettings settings;

};

#endif // GAMECONFIGURATION_H
