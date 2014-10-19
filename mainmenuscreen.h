#ifndef MAINMENUSCREEN_H
#define MAINMENUSCREEN_H

#include "gamescreen.h"

class MainMenuScreen : public GameScreen {

public:
    virtual void loadContent() override;

    virtual void unloadContent() override;

    virtual void handleInput(const SDL_Event &event) override;

    virtual void draw() override;

private:
    SDL_Surface *surface;
};

#endif // MAINMENUSCREEN_H