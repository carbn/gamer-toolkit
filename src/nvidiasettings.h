#ifndef NVIDIASETTINGS_H
#define NVIDIASETTINGS_H

#include <QObject>

class NvidiaSettings : public QObject
{
    Q_OBJECT
public:
    explicit NvidiaSettings(QObject *parent = 0);

public slots:
    void setVibrance(int value);
    void resetVibrance();

private:
    typedef unsigned int NvAttribute;

    void assign(NvAttribute attribute, int value);

};

#endif // NVIDIASETTINGS_H
