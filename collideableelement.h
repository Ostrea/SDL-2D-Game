#ifndef COLLIDEABLEELEMENT_H
#define COLLIDEABLEELEMENT_H

#include <memory>
#include "SDL/SDL.h"

class CollideableElement {

public:
    virtual bool hasCollided(std::shared_ptr<CollideableElement> anotherElement) = 0;
    virtual SDL_Rect getCollisionRectangle() const = 0;
    virtual ~CollideableElement() {}
};

#endif // COLLIDEABLEELEMENT_H