#ifndef HIGHSCORESSCREEN_H
#define HIGHSCORESSCREEN_H

#include <vector>
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

private:
    const int NUMBER_OF_SCORES = 10;
    std::vector<std::pair<std::string, int>> highScores;
    std::vector<SDL_Surface*> highScoresSurfaces;
    SDL_Color textColor = {255, 255, 255};
};

#endif // HIGHSCORESSCREEN_H
