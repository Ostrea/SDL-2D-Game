#ifndef ANIMAL_H
#define ANIMAL_H

#include "staticgraphicalelement.h"
#include "movablegraphicalelement.h"

class Animal : public StaticGraphicalElement, public MovableGraphicalElement {

public:
    virtual void handleEvents(SDL_Event &event) override;

    Animal(int x, int y, double velocityX, int width, int height);

    virtual bool initialize() override;

    virtual void logic() override;

    virtual void collisionDetection() override;

    virtual bool isAlive() override;

private:
    bool alive;
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;
};

#endif // ANIMAL_H