#include "animal.h"
#include "functions.h"
#include "bullet.h"

void Animal::handleEvents(SDL_Event& event){

}

Animal::Animal(int x, int y, double velocityX, int width, int height) : StaticGraphicalElement(x, y),
                                                                        MovableGraphicalElement(velocityX, 0),
                                                                        SCREEN_WIDTH{width},
                                                                        SCREEN_HEIGHT{height} {
    alive = true;
    collisionRectangle.x = x;
    collisionRectangle.y = y;
    collisionRectangle.w = 45;
    collisionRectangle.h = 60;
}

bool Animal::initialize() {
    surface = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/asteroid_blue.png");
    return surface != nullptr;
}

void Animal::logic() {
    x += velocityX;
    y += velocityY;

    // выход за карту и возвращение в нее. Приходится писать таким образом из-за того,
    // что % имеет знак делимого (стандарт C++11)
    x = (x % SCREEN_WIDTH + SCREEN_WIDTH) % SCREEN_WIDTH;

    collisionRectangle.x = x;
    collisionRectangle.y = y;
}

bool Animal::isAlive() {
    return alive;
}

bool Animal::isCollided(std::shared_ptr<Bullet> bullet) {
    SDL_Rect bulletRectangle = bullet->getCollisionRectangle();
//    return ( ( x >= bulletRectangle.x && x <= bulletRectangle.x + bulletRectangle.w )
//            && ( y >= bulletRectangle.y && y <= bulletRectangle.y + bulletRectangle.h ) );

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