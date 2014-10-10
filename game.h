#ifndef GAME_H
#define GAME_H

#include <SDL/SDL.h>
#include "background.h"
#include "player.h"
#include "animal.h"
#include <list>
#include <memory>

class Game {

public:
    Game();
    int execute();

private:
    bool running;
    int currentNumberOfAnimals;

    SDL_Surface *canvas;

    // константы
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const int NUMBER_OF_ANIMALS = 12;

    // основные объекты
    std::shared_ptr<Background> background;
    std::shared_ptr<Player> player;

    std::list<std::shared_ptr<Animal>> animals;
    std::list<std::shared_ptr<Bullet>> bullets;
    std::list<std::shared_ptr<StaticGraphicalElement>> allElements;

    // основные функции
    bool init();
    void handleEvents(SDL_Event &event);
    void logic();
    void render();
    void cleanUp();
    void createAnimal();

    void removeDeadSprites();
    bool haveAnimalCollidedWithBullet(std::shared_ptr<Bullet> bullet);
    int numberOfCollisionsAnimalsBullets();
};
#endif // GAME_H