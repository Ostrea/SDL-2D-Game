#ifndef HIGHSCORESSCREEN_H
#define HIGHSCORESSCREEN_H

#include "gamescreen.h"

class HighScoresScreen : public GameScreen {

public:
    HighScoresScreen() {
        popup = true;
    }

    virtual void loadContent();

    virtual void unloadContent();

    virtual void handleInput(const SDL_Event &event);

    virtual void draw();
};

#endif // HIGHSCORESSCREEN_H
