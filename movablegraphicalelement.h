#ifndef MOVABLEGRAPHICALELEMENT_H
#define MOVABLEGRAPHICALELEMENT_H

#include "SDL/SDL.h"

class MovableGraphicalElement {

public:
    MovableGraphicalElement(double velocityX, double velocityY);
    virtual void handleEvents(SDL_Event &event) = 0;
    virtual ~MovableGraphicalElement();

protected:
    double velocityX;
    double velocityY;
};

#endif // MOVABLEGRAPHICALELEMENT_H