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
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    // основные функции
    bool init();
    void handleEvents(SDL_Event &event);
    void logic();
    void render();
    void cleanUp();

    // вспомогательные функции
    SDL_Surface *loadImage(std::string fileName);
    void applySurface(int x, int y, SDL_Surface *source,
            SDL_Surface *destination, SDL_Rect *clip = nullptr);
};
#endif // GAME_H