#include "animal.h"
#include "bullet.h"

Animal::Animal(int x, int y, double velocityX, ContentManager const &contentManager) : DrawableElement(x, y),
        contentManager(contentManager) {
    velocityY = 0;
    this->velocityX = velocityX;
    alive = true;
    collisionRectangle.x = x + 2;
    collisionRectangle.y = y + 3;
    collisionRectangle.w = 83;
    collisionRectangle.h = 72;
    surface = nullptr;
}

bool Animal::initialize() {
    surface = contentManager.getAnimal();
    return surface != nullptr;
}

void Animal::update() {
    x += velocityX;
    y += velocityY;

    // выход за карту и возвращение в нее. Приходится писать таким образом из-за того,
    // что % имеет знак делимого (стандарт C++11)
    int screenWidth = SDL_GetVideoSurface()->w;
    x = (x % screenWidth + screenWidth) % screenWidth;

    collisionRectangle.x = x + 2;
    collisionRectangle.y = y + 3;
}

bool Animal::isAlive() const {
    return alive;
}

bool Animal::hasCollided(std::shared_ptr<CollideableElement> anotherElement) {
    SDL_Rect bulletRectangle = anotherElement->getCollisionRectangle();

    int leftA = collisionRectangle.x;
    int rightA = collisionRectangle.x + collisionRectangle.w;
    int topA = collisionRectangle.y;
    int bottomA = collisionRectangle.y + collisionRectangle.h;

    int leftB = bulletRectangle.x;
    int rightB = bulletRectangle.x + bulletRectangle.w;
    int topB = bulletRectangle.y;
    int bottomB = bulletRectangle.y + bulletRectangle.h;

    if (bottomA <= topB) {
        return false;
    }
    if (topA >= bottomB) {
        return false;
    }
    if (rightA <= leftB) {
        return false;
    }
    return leftA < rightB;
}

void Animal::makeDead() {
    alive = false;
}