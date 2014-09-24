#include "animal.h"
#include "functions.h"

void Animal::handleEvents(SDL_Event& event){

}

Animal::Animal(int x, int y, double velocityX, double velocityY) : StaticGraphicalElement(x, y),
MovableGraphicalElement(velocityX, velocityY){
    alive = true;
}

Animal::~Animal() {

}

void Animal::render(SDL_Surface *screen) const {
    StaticGraphicalElement::render(screen);
}

bool Animal::initialize() {
    surface = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/asteroid_blue.png");
    return surface != nullptr;
}

void Animal::logic() {
    // getting out of the map. Need to do this, cause % has sign of dividender (standart C++11)
    x = (x % SCREEN_WIDTH + SCREEN_WIDTH) % SCREEN_WIDTH;
    y = (y % SCREEN_HEIGHT + SCREEN_HEIGHT) % SCREEN_HEIGHT;
    x += velocityX;
    y += velocityY;
}

void Animal::collisionDetection() {

}
