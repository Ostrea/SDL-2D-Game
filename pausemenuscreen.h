#ifndef PAUSEMENUSCREEN_H
#define PAUSEMENUSCREEN_H

#include "menuscreen.h"

class PauseMenuScreen : public MenuScreen {

public:
    PauseMenuScreen(Timer &gameTimer) : gameTimer(gameTimer) {
    }

    virtual void loadContent() override;

    virtual void unloadContent() override;

    virtual void draw() override;

private:
    Timer &gameTimer;
};

#endif // PAUSEMENUSCREEN_H