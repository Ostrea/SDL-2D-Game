#ifndef BULLET_H
#define BULLET_H

#include "drawableelement.h"
#include "controllableelement.h"
#include "movableelement.h"
#include "contentmanager.h"
#include "collideableelement.h"

class Animal;

class Bullet : public DrawableElement, public MovableElement, public CollideableElement {

public:
    Bullet(int x, int y, double velocityY, ContentManager const &contentManager);

    virtual void update() override;

    virtual bool initialize() override;

    virtual bool isAlive() const override {
        return alive;
    }

    void makeDead() {
        alive = false;
    }

    virtual bool hasCollided(std::shared_ptr<CollideableElement> anotherElement) override;

    virtual SDL_Rect getCollisionRectangle() const override {
        return collisionRectangle;
    }

private:
    bool alive;
    SDL_Rect collisionRectangle;
    ContentManager const &contentManager;

public:
    virtual void draw() const override;
};

#endif // BULLET_H