#ifndef HELPSCREEN_H
#define HELPSCREEN_H

#include "gamescreen.h"

class HelpScreen : public GameScreen {

public:
    HelpScreen() {
        popup = true;
    }

    virtual void loadContent() override;

    virtual void unloadContent() override;

    virtual void handleInput(const SDL_Event &event) override;

    virtual void draw() override;

private:
    std::vector<SDL_Surface*> text;
    SDL_Surface *background;
};

#endif // HELPSCREEN_H