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

    int getX();

    int getY();

private:
    bool alive;
};

#endif // BULLET_H