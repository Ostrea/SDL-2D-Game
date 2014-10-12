#ifndef BULLET_H
#define BULLET_H

#include "drawableelement.h"
#include "controllableelement.h"

class Animal;

class Bullet : public DrawableElement, public ControllableElement {

public:
    Bullet(int x, int y, double velocityY);

    virtual void handleEvents(SDL_Event const &event) override;

    virtual void update() override;

    virtual bool initialize() override;

    virtual bool isAlive() const override;

    void makeDead();

    SDL_Rect getCollisionRectangle() const {
        return collisionRectangle;
    }

private:
    bool alive;
    SDL_Rect collisionRectangle;
public:
    virtual void draw() const override;
};

#endif // BULLET_H