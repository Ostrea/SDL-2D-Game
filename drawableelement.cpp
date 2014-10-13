#include "drawableelement.h"
#include "functions.h"

DrawableElement::DrawableElement(int x, int y) : x{x}, y{y} {

}

void DrawableElement::draw() const {
    SDL_Surface *canvas = SDL_GetVideoSurface();
    applySurface(x, y, surface, canvas);
}

DrawableElement::~DrawableElement() {

}

bool DrawableElement::isAlive() const {
    return true;
}