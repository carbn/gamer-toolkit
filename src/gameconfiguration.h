#ifndef GAMECONFIGURATION_H
#define GAMECONFIGURATION_H

#include <QObject>

class GameConfiguration : public QObject
{
    Q_OBJECT
public:
    explicit GameConfiguration(QString gameName, QString windowName, QObject *parent = 0);

    QString getGameName() const;
    QString getWindowName() const;

signals:
    void setVibrance(int);
    void resetVibrance();

public slots:
    void activate();
    void deactivate();

private:
    QString gameName;
    QString windowName;

};

#endif // GAMECONFIGURATION_H
