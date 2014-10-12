#ifndef CONTROLLABLEELEMENT_H
#define CONTROLLABLEELEMENT_H

#include "SDL/SDL.h"

class ControllableElement {

public:
    virtual void handleEvents(SDL_Event const &event) = 0;

    virtual ~ControllableElement() {}
};

#endif // CONTROLLABLEELEMENT_H