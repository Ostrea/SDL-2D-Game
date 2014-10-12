#include "bullet.h"
#include "functions.h"

void Bullet::handleEvents(SDL_Event const &event){

}

void Bullet::update() {
    y += velocityY;
    collisionRectangle.y = y;
    if (y < 0) {
        this->alive = false;
    }
}

bool Bullet::initialize() {
    surface = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/shot1.png");
    return surface != nullptr;
}

Bullet::Bullet(int x, int y, double velocityY) : DrawableElement{x, y} {
    velocityX = 0;
    this->velocityY = velocityY;
    alive = true;
    collisionRectangle.x = x;
    collisionRectangle.y = y;
    collisionRectangle.w = 10;
    collisionRectangle.h = 10;
}

bool Bullet::isAlive() const{
    return alive;
}

void Bullet::makeDead() {
    alive = false;
}

// TODO delete after testing (base class draw does all needed work)
void Bullet::draw() const {
    SDL_Rect tempRect = collisionRectangle;
    auto screen = SDL_GetVideoSurface();
    SDL_FillRect(screen, &tempRect, SDL_MapRGB(screen->format, 255, 255, 255));
    DrawableElement::draw();
}
