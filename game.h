#ifndef GAME_H
#define GAME_H

#include "SDL/SDL.h"
#include "background.h"
#include "player.h"
#include "animal.h"
#include <list>
#include <memory>
#include "contentmanager.h"

class Game {

public:
    Game();

    int run();

private:
    bool running;
    SDL_Surface *canvas;
    ContentManager contentManager;

    // константы
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    // основные функции
    bool initialize();

    void handleEvents(SDL_Event const &event);

    void update();

    void draw();

    void cleanUp();

    // TODO it all should be in gameplay screen
    void createAnimal();

    void removeDeadElements();

    bool haveAnimalCollidedWithBullet(std::shared_ptr<Bullet> bullet);

    int numberOfCollisionsAnimalsBullets();

    // основные объекты
    std::shared_ptr<Player> player;

    std::list<std::shared_ptr<Animal>> animals;
    std::list<std::shared_ptr<Bullet>> bullets;
    std::list<std::shared_ptr<DrawableElement>> allElements;

    const int MAXIMUM_NUMBER_OF_ANIMALS = 12;

    int currentNumberOfAnimals;
};

#endif // GAME_H