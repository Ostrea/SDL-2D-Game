#ifndef ANIMAL_H
#define ANIMAL_H

#include "drawableelement.h"
#include "controllableelement.h"
#include "movableelement.h"
#include "contentmanager.h"
#include <memory>

class Bullet;

class Animal : public DrawableElement, public MovableElement {

public:
    Animal(int x, int y, double velocityX, ContentManager const &contentManager);

    virtual bool initialize() override;

    virtual void update() override;

    virtual bool isAlive() const override;

    bool isCollided(std::shared_ptr<Bullet> bullet);

    void makeDead();

private:
    bool alive;
    SDL_Rect collisionRectangle;
    ContentManager const &contentManager;

public:
    virtual void draw() const override;
};

#endif // ANIMAL_H