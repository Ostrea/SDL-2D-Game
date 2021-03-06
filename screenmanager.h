#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <memory>
#include <list>
#include <SDL/SDL_events.h>
#include <SDL/SDL_ttf.h>
#include <vector>

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

    TTF_Font *getTextFont() const {
        return textFont;
    }

    bool exitGame() const {
        return screens.size() == 1 || needToExit;
    }

    void setNeedToExit(bool needToExit) {
        this->needToExit = needToExit;
    }

    std::vector<Uint16> const &getName() const {
        return name;
    }

    void setName(std::vector<Uint16> const &name) {
        ScreenManager::name = name;
    }

    void closePreviousScreen();

private:
    std::list<std::shared_ptr<GameScreen>> screens;

    TTF_Font *menuFont;
    TTF_Font *gameFont;
    TTF_Font *textFont;

    bool needToExit = false;
    std::vector<Uint16> name;
};

#endif // SCREENMANAGER_H