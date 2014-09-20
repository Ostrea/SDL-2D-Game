#ifndef GAME_H
#define GAME_H

#include "SDL/SDL.h"
#include <string>
#include "background.h"
#include "player.h"
#include <list>
#include <memory>

class Game {

public:
    Game();
    int execute();

private:
    bool running;
    SDL_Surface *screen;
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    // основные объекты
    std::shared_ptr<Background> background;
    std::shared_ptr<Player> player;

    std::list<std::shared_ptr<StaticGraphicalElement>> allElements;

    // основные функции
    bool init();
    void handleEvents(SDL_Event &event);
    void logic();
    void render();
    void cleanUp();
};
#endif // GAME_H