#ifndef MAINMENUSCREEN_H
#define MAINMENUSCREEN_H

#include "menuscreen.h"

class MainMenuScreen : public MenuScreen {

public:
    virtual void loadContent() override;

    virtual void unloadContent() override;

    virtual void draw() override;

private:
    SDL_Surface *surface;
};

#endif // MAINMENUSCREEN_H