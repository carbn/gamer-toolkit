#ifndef CUSTOMCOMMANDMODULE_H
#define CUSTOMCOMMANDMODULE_H

#include <QObject>
#include "basemodule.h"

class CustomCommandModule : public BaseModule
{
    Q_OBJECT
public:
    explicit CustomCommandModule(QSettings *settings, QObject *parent);

public slots:
    virtual void activate();
    virtual void deactivate();

private:
    void run(QString const& command) const;

};

#endif // CUSTOMCOMMANDMODULE_H
