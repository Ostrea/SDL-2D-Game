#ifndef DRAWABLEELEMENT_H
#define DRAWABLEELEMENT_H

#include "SDL/SDL.h"

class DrawableElement {

public:
    DrawableElement(int x, int y);

    virtual ~DrawableElement();

    virtual void draw() const;

    virtual bool initialize() = 0;

    virtual void update() = 0;

    virtual bool isAlive() const;

protected:
    SDL_Surface *surface;
    int x;
    int y;
    double velocityX;
    double velocityY;
};

#endif // DRAWABLEELEMENT_H