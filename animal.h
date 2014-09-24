#ifndef ANIMAL_H
#define ANIMAL_H

#include "staticgraphicalelement.h"
#include "movablegraphicalelement.h"

class Animal : public StaticGraphicalElement, public MovableGraphicalElement {

public:
    virtual void handleEvents(SDL_Event &event) override;

    Animal(int x, int y, double velocityX, double velocityY);

    virtual ~Animal();

    virtual void render(SDL_Surface *screen) const override;

    virtual bool initialize() override;

    virtual void logic() override;

    virtual void collisionDetection() override;

private:
    bool alive;
};

#endif // ANIMAL_H