#ifndef GAMETEMP_H
#define GAMETEMP_H

#include "SDL/SDL.h"
#include "contentmanager.h"
#include "screenmanager.h"

class Game {

public:
    Game();

    int run();

private:
    bool running;
    SDL_Surface *canvas;
    ScreenManager screenManager;

    // константы
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    // основные функции
    bool initialize();

    void handleEvents(SDL_Event const &event);

    void update();

    void draw();

    void cleanUp();
};

#endif // GAMETEMP_H