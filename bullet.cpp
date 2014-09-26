#include "bullet.h"
#include "functions.h"

void Bullet::handleEvents(SDL_Event& event){

}

void Bullet::logic() {
    y += velocityY;
    if (y < 0) {
        this->alive = false;
    }
}

bool Bullet::initialize() {
    surface = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/shot1.png");
    return surface != nullptr;
}

Bullet::Bullet(int x, int y, double velocityY) : StaticGraphicalElement{x, y},
MovableGraphicalElement{0, velocityY} {
    alive = true;
}

void Bullet::collisionDetection() {

}

bool Bullet::isAlive() {
    return alive;
}

void Bullet::makeDead() {
    alive = false;
}

int Bullet::getX() {
    return x;
}

int Bullet::getY() {
    return y;
}
