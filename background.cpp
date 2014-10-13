#include "background.h"

Background::Background(int x, int y, ContentManager const &contentManager) : DrawableElement(x, y),
                contentManager(contentManager){
    surface = nullptr;
}

bool Background::initialize() {
    surface = contentManager.getBackground();
    return surface != nullptr;
}

void Background::update() {

}
