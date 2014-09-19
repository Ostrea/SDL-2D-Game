#ifndef MOVABLEGRAPHICALELEMENT_H
#define MOVABLEGRAPHICALELEMENT_H

#include "SDL/SDL.h"

class MovableGraphicalElement {

public:
    virtual void handleEvents(SDL_Event &event) = 0;
    virtual void logic() = 0;
    virtual ~MovableGraphicalElement() {}

protected:
    double velocityX;
    double velocityY;
    bool alive;
};

#endif