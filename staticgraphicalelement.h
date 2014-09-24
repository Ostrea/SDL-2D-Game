#ifndef STATICGRAPHICALELEMENT_H
#define STATICGRAPHICALELEMENT_H

#include <SDL/SDL.h>

class StaticGraphicalElement {

public:
    StaticGraphicalElement(int x, int y);

    virtual ~StaticGraphicalElement();

    virtual void render(SDL_Surface *screen) const;

    virtual bool initialize() = 0;

    virtual void logic() = 0;

    virtual void collisionDetection() = 0;

    virtual bool isAlive();

protected:
    SDL_Surface *surface;
    int x;
    int y;
};

#endif // STATICGRAPHICALELEMENT_H