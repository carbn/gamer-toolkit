#include "gamertoolkit.h"

GamerToolkit::GamerToolkit(QObject *parent) :
    QObject(parent),
    nvSettings(),
    bamfClient(),
    activeWindow(0)
{
    gameConfigurations.append(new GameConfiguration("Team Fortress 2", "Team Fortress 2 - OpenGL", this));
    gameConfigurations.append(new GameConfiguration("Counter-Strike: Global Offensive", "Counter-Strike: Global Offensive - OpenGL", this));

    // Connect signals
    connect(&bamfClient, SIGNAL(activeWindowChanged(QString)), this, SLOT(activeWindowChanged(QString)));

    foreach (GameConfiguration *game, gameConfigurations)
    {
        connect(game, SIGNAL(setVibrance(int)), &nvSettings, SLOT(setVibrance(int)));
        connect(game, SIGNAL(resetVibrance()), &nvSettings, SLOT(resetVibrance()));
    }
}

void GamerToolkit::activeWindowChanged(QString windowName)
{
    // Deactivate the currect config if active
    if (activeWindow)
    {
        activeWindow->deactivate();
        activeWindow = 0;
    }

    // Find a new configuration match
    foreach (GameConfiguration *game, gameConfigurations)
    {
        if (windowName == game->getWindowName())
        {
            activeWindow = game;
            activeWindow->activate();
            break;
        }
    }
}
