#ifndef BULLET_H
#define BULLET_H

#include "staticgraphicalelement.h"
#include "movablegraphicalelement.h"

class Animal;

class Bullet : public StaticGraphicalElement, public MovableGraphicalElement {

public:
    Bullet(int x, int y, double velocityY);

    virtual void handleEvents(SDL_Event &event) override;

    virtual void logic() override;

    virtual bool initialize() override;

    virtual void collisionDetection() override;

    virtual bool isAlive() override;

    void makeDead();

    SDL_Rect getCollisionRectangle() const;

private:
    bool alive;
    SDL_Rect collisionRectangle;
};

#endif // BULLET_H