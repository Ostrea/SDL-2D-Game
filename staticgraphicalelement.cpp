#include "staticgraphicalelement.h"
#include "functions.h"

StaticGraphicalElement::StaticGraphicalElement(int x, int y) : x{x}, y{y} {
}

void StaticGraphicalElement::render(SDL_Surface *screen) const {
    applySurface(x, y, surface, screen);
}

StaticGraphicalElement::~StaticGraphicalElement() {
    SDL_FreeSurface(surface);
}

bool StaticGraphicalElement::isAlive() {
    return true;
}
