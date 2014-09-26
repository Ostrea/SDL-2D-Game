#ifndef ANIMAL_H
#define ANIMAL_H

#include "staticgraphicalelement.h"
#include "movablegraphicalelement.h"
#include <memory>

class Bullet;

class Animal : public StaticGraphicalElement, public MovableGraphicalElement {

public:
    virtual void handleEvents(SDL_Event &event) override;

    Animal(int x, int y, double velocityX, int width, int height);

    virtual bool initialize() override;

    virtual void logic() override;

    virtual void collisionDetection() override;

    virtual bool isAlive() override;

    bool isCollided(std::shared_ptr<Bullet> bullet);

    void makeDead();

private:
    bool alive;
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;
    SDL_Rect collisionRectangle;
};

#endif // ANIMAL_H