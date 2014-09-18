#include "staticgraphicalelement.h"
#include "functions.h"

void StaticGraphicalElement::render(SDL_Surface *screen) {
    applySurface(x, y, surface, screen);
}

StaticGraphicalElement::~StaticGraphicalElement() {
    SDL_FreeSurface(surface);
}
