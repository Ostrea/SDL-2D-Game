#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "SDL/SDL.h"
#include "screenmanager.h"
#include "constants.h"

class ScreenManager;

class GameScreen {

public:
    GameScreen();

    virtual void loadContent() = 0;

    virtual void unloadContent() = 0;

    virtual void handleInput(const SDL_Event &event) = 0;

    virtual void update(bool otherScreenHasFocus, bool coveredByOtherScreen);

    virtual void draw() = 0;

    void setScreenManager(ScreenManager *screenManager) {
        this->screenManager = screenManager;
    }

    virtual ~GameScreen() {}

    ScreenState getState() const {
        return state;
    }

    bool isPopup() const {
        return popup;
    }

    bool operator==(const GameScreen& b);

protected:
    bool otherScreenHasFocus;
    bool exited;
    bool popup;
    ScreenManager *screenManager;
    ScreenState state;
};

#endif // GAMESCREEN_H