#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <memory>
#include <list>
#include <SDL/SDL_events.h>

class GameScreen;

class ScreenManager {

public:
    void loadContent();

    void unloadContent();

    void handleEvents(const SDL_Event &event);

    void update();

    void draw();

    void addScreen(std::shared_ptr<GameScreen> screen);

    void removeScreen(std::shared_ptr<GameScreen> screen);

private:
    std::list<std::shared_ptr<GameScreen>> screens;
    std::list<std::shared_ptr<GameScreen>> screensToUpdate;
};

#endif // SCREENMANAGER_H