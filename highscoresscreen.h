#ifndef HIGHSCORESSCREEN_H
#define HIGHSCORESSCREEN_H

#include <vector>
#include "gamescreen.h"

class HighScoresScreen : public GameScreen {

public:
    HighScoresScreen();

    HighScoresScreen(int currentScores) ;

    virtual void loadContent();

    virtual void unloadContent();

    virtual void handleInput(const SDL_Event &event);

    virtual void draw();

private:
    const int NUMBER_OF_SCORES = 10;
    std::vector<std::pair<std::vector<Uint16>, Uint16>> highScores;
    std::vector<SDL_Surface*> highScoresNameSurfaces;
    std::vector<SDL_Surface*> highScoresPointsSurfaces;
    SDL_Color textColor = {0, 0, 0};
    SDL_Surface *background;
    bool overwrite;
    Uint16 currentScores;

    void readHighScores();

    void writeHighScores();

    void updateHighScores();
};

#endif // HIGHSCORESSCREEN_H
