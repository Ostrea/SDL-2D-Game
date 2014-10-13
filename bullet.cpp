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
//    surface = loadImage("/home/ostrea/Programs/Labs_second_term/"
//            "Gushin/Coursework_third_try/images/shot1.png");
    return surface != nullptr;
}

Bullet::Bullet(int x, int y, double velocityY, ContentManager const &contentManager) : DrawableElement{x, y},
      contentManager(contentManager) {
    velocityX = 0;
    this->velocityY = velocityY;
    alive = true;
    collisionRectangle.x = x;
    collisionRectangle.y = y;
    collisionRectangle.w = 10;
    collisionRectangle.h = 10;
}

// TODO delete after testing (base class draw does all needed work)
void Bullet::draw() const {
    SDL_Rect tempRect = collisionRectangle;
    auto screen = SDL_GetVideoSurface();
    SDL_FillRect(screen, &tempRect, SDL_MapRGB(screen->format, 255, 255, 255));
    DrawableElement::draw();
}

bool Bullet::hasCollided(std::shared_ptr<CollideableElement> anotherElement) {
    return false;
}
