#ifndef NVIDIAMODULE_H
#define NVIDIAMODULE_H

#include <QObject>
#include <QSettings>
#include "basemodule.h"
#include "nvidiasettings.h"

class NvidiaModule : public BaseModule
{
    Q_OBJECT
public:
    explicit NvidiaModule(QSettings *settings, QObject *parent);

    virtual QString getName() const;

public slots:
    virtual void activate();
    virtual void deactivate();

private:
    NvidiaSettings nvSettings;
    bool vibranceIsActive;
};

#endif // NVIDIAMODULE_H
