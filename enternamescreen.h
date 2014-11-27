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
    unsigned long currentLength = 0ul;
    std::string text;
    SDL_Surface *textSurface;
    SDL_Surface *promptSurface;
    SDL_Color textColor = {255, 255, 255};
    SDL_Color nameColor = {0x9A, 0xCD, 0x32};
};

#endif // ENTERNAMESCREEN_H