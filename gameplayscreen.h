#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include "gamescreen.h"
#include "drawableelement.h"
#include "bullet.h"
#include "player.h"
#include <memory>
#include <list>
#include "contentmanager.h"
#include "timer.h"

class GameplayScreen : public GameScreen {

public:
    GameplayScreen();

    virtual void loadContent() override;

    virtual void unloadContent() override;

    virtual void handleInput(const SDL_Event &event) override;

    virtual void update(bool otherScreenHasFocus, bool coveredByOtherScreen) override;

    virtual void draw() override;

private:
    void createAnimal();

    void removeDeadElements();

    bool haveAnimalCollidedWithBullet(std::shared_ptr<Bullet> bullet);

    int numberOfCollisionsAnimalsBullets();

    void createBullet();

    // основные объекты
    SDL_Surface *canvas;

    std::shared_ptr<Player> player;

    std::list<std::shared_ptr<Animal>> animals;
    std::list<std::shared_ptr<Bullet>> bullets;
    std::list<std::shared_ptr<DrawableElement>> allElements;

    const int MAXIMUM_NUMBER_OF_ANIMALS = 12;

    int currentNumberOfAnimals;

    ContentManager contentManager;
    Timer animalTimer;
};

#endif // PLAYSCREEN_H