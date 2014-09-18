#ifndef STATICGRAPHICALELEMENT_H
#define STATICGRAPHICALELEMENT_H

#include "SDL/SDL.h"

class StaticGraphicalElement {

public:
    virtual ~StaticGraphicalElement();
    virtual void render(SDL_Surface *screen);
    virtual void initialize() = 0;

protected:
    SDL_Surface *surface;
    int x;
    int y;
};

#endif // STATICGRAPHICALELEMENT_H