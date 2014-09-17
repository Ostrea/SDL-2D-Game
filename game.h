#ifndef GAME_H
#define GAME_H

#include "SDL/SDL.h"
#include <string>

class Game {
public:
    Game();
    int execute();
private:
    bool running;
    SDL_Surface *screen;
    SDL_Surface *background;
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    // основные функции
    bool init();
    void handleEvents(SDL_Event &event);
    void logic();
    void render();
    void cleanUp();
};
#endif // GAME_H