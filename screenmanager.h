#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <memory>
#include <list>
#include <SDL/SDL_events.h>
#include <SDL/SDL_ttf.h>

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

    TTF_Font *getMenuFont() const {
        return menuFont;
    }

    TTF_Font *getGameFont() const {
        return gameFont;
    }

    bool exitGame() const {
        return screens.size() == 1;
    }

private:
    std::list<std::shared_ptr<GameScreen>> screens;
    std::list<std::shared_ptr<GameScreen>> screensToUpdate;
    TTF_Font *menuFont;
    TTF_Font *gameFont;
};

#endif // SCREENMANAGER_H