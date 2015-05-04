#include "gamertoolkit.h"
#include "nvidiamodule.h"

GamerToolkit::GamerToolkit(QObject *parent) :
    QObject(parent),
    bamfClient(),
    modules(),
    gameConfigurations(),
    activeWindow(0)
{
    // Create modules
    modules.append(new NvidiaModule(this));

    // Create games
    gameConfigurations.append(new GameConfiguration("Team Fortress 2", "Team Fortress 2 - OpenGL", this));
    gameConfigurations.append(new GameConfiguration("Counter-Strike: Global Offensive", "Counter-Strike: Global Offensive - OpenGL", this));

    // Add modules to game configs
    foreach (GameConfiguration *game, gameConfigurations)
    {
        game->updateModules(modules);
    }

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

void GamerToolkit::deactivateModules()
{
    foreach (BaseModule *module, modules)
    {
        if (module->isActive())
        {
            module->deactivate();
            module->setActive(false);
        }
    }
}
