#ifndef ENTERNAMESCREEN_H
#define ENTERNAMESCREEN_H

#include "gamescreen.h"

class EnterNameScreen : public GameScreen {

public:
    EnterNameScreen();

    virtual void loadContent();

    virtual void unloadContent();

    virtual void handleInput(const SDL_Event &event);

    virtual void draw();

private:
    std::string text;
    SDL_Surface *textSurface;
    SDL_Color textColor = {255, 255, 255};
};

#endif // ENTERNAMESCREEN_H