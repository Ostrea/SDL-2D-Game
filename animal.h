#ifndef ANIMAL_H
#define ANIMAL_H

#include "drawableelement.h"
#include "controllableelement.h"
#include <memory>

class Bullet;

class Animal : public DrawableElement, public ControllableElement {

public:
    virtual void handleEvents(SDL_Event const &event) override;

    Animal(int x, int y, double velocityX, int width, int height);

    virtual bool initialize() override;

    virtual void update() override;

    virtual bool isAlive() const override;

    bool isCollided(std::shared_ptr<Bullet> bullet);

    void makeDead();

private:
    bool alive;
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;
    SDL_Rect collisionRectangle;
public:
    virtual void draw() const override;
};

#endif // ANIMAL_H