#ifndef ANIMAL_H
#define ANIMAL_H

#include "drawableelement.h"
#include "controllableelement.h"
#include "movableelement.h"
#include "contentmanager.h"
#include "collideableelement.h"
#include <memory>

class Bullet;

class Animal : public DrawableElement, public MovableElement, public CollideableElement {

public:
    Animal(int x, int y, double velocityX, ContentManager const &contentManager);

    virtual bool initialize() override;

    virtual void update() override;

    virtual bool isAlive() const override;

    virtual bool hasCollided(std::shared_ptr<CollideableElement> anotherElement) override;

    virtual SDL_Rect getCollisionRectangle() const override {
        return collisionRectangle;
    }

    void makeDead();

private:
    bool alive;
    SDL_Rect collisionRectangle;
    ContentManager const &contentManager;
};

#endif // ANIMAL_H