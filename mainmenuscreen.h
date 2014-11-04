#ifndef MAINMENUSCREEN_H
#define MAINMENUSCREEN_H

#include "menuscreen.h"

class MainMenuScreen : public MenuScreen {

public:
    MainMenuScreen() {
        popup = true;
    }

    virtual void loadContent() override;

    virtual void unloadContent() override;

    virtual void draw() override;

private:
    SDL_Surface *nameSurface;
};

#endif // MAINMENUSCREEN_H