#include "bullet.h"

void Bullet::update() {
    y += velocityY;
    collisionRectangle.y = y;
    if (y < 0) {
        this->alive = false;
    }
}

bool Bullet::initialize() {
    surface = contentManager.getBullet();
    return surface != nullptr;
}

Bullet::Bullet(int x, int y, double velocityY, ContentManager const &contentManager) : DrawableElement{x, y},
      contentManager(contentManager) {
    velocityX = 0;
    this->velocityY = velocityY;
    alive = true;
    collisionRectangle.x = x + 2;
    collisionRectangle.y = y;
    collisionRectangle.w = 8;
    collisionRectangle.h = 16;
}

bool Bullet::hasCollided(std::shared_ptr<CollideableElement> anotherElement) {
    return false;
}
