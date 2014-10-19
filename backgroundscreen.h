#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "gamescreen.h"

class BackgroundScreen : public GameScreen {

public:
    virtual void loadContent() override;

    virtual void unloadContent() override;

    virtual void handleInput(const SDL_Event &event) override;

    virtual void draw() override;

private:
    SDL_Surface *surface;
};

#endif // BACKGROUND_H