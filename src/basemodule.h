#ifndef BASEMODULE_H
#define BASEMODULE_H

#include <QObject>
#include <QSettings>

class BaseModule : public QObject
{
    Q_OBJECT
public:
    explicit BaseModule(QObject *parent = 0);

    bool isActive() const;
    void setActive(bool active);

    virtual QString getName() const = 0;
    bool isEnabled(QSettings &settings) const;

public slots:
    virtual void activate(QSettings &settings) = 0;
    virtual void deactivate() = 0;

private:
    bool active;

};

#endif // BASEMODULE_H
