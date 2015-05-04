#include "gamertoolkit.h"
#include "nvidiamodule.h"
#include "gameconfiguration.h"

GamerToolkit::GamerToolkit(QObject *parent) :
    QObject(parent),
    bamfClient(),
    gameConfigurations(),
    activeWindow(0)
{
    // Create games
    gameConfigurations.append(new GameConfiguration("Team Fortress 2", "Team Fortress 2 - OpenGL", this));
    gameConfigurations.append(new GameConfiguration("Counter-Strike: Global Offensive", "Counter-Strike: Global Offensive - OpenGL", this));

    // Connect signals
    connect(&bamfClient, SIGNAL(activeWindowChanged(QString)), this, SLOT(activeWindowChanged(QString)));
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
            if (game->isEnabled())
            {
                game->activate();
                activeWindow = game;
                break;
            }
        }
    }
}
