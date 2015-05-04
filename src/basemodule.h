#ifndef BASEMODULE_H
#define BASEMODULE_H

#include <QObject>
#include <QVariant>

class QSettings;

class BaseModule : public QObject
{
    Q_OBJECT
public:
    explicit BaseModule(QSettings *settings, QObject *parent = 0);
    virtual ~BaseModule();

    bool isEnabled() const;
    void setEnabled(bool enabled);

    bool isActive() const;
    void setActive(bool active);

public slots:
    virtual void activate() = 0;
    virtual void deactivate() = 0;

protected:
    QVariant getSettingsValue(QString const& key, QVariant const& defaultValue = QVariant()) const;
    void setSettingsValue(QString const& key, QVariant const& value);

private:
    QString getSettingsPrefix() const;

    bool active;
    QSettings *settings;

};

#endif // BASEMODULE_H
