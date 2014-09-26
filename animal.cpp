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
    collisionRectangle.h = 45;
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

void Animal::collisionDetection() {

}

bool Animal::isAlive() {
    return alive;
}

bool Animal::isCollided(std::shared_ptr<Bullet> bullet) {

    return x == bullet->getX() && y == bullet->getY();
}

void Animal::makeDead() {
    alive = false;
}
