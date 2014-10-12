#include "animal.h"
#include "functions.h"
#include "bullet.h"

void Animal::handleEvents(SDL_Event const &event){

}

Animal::Animal(int x, int y, double velocityX, int width, int height) : DrawableElement(x, y),
                                                                        SCREEN_WIDTH{width},
                                                                        SCREEN_HEIGHT{height} {
    velocityY = 0;
    this->velocityX = velocityX;
    alive = true;
    collisionRectangle.x = x + 5;
    collisionRectangle.y = y + 5;
    collisionRectangle.w = 75;
    collisionRectangle.h = 78;
}

bool Animal::initialize() {
    surface = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/asteroid_blue.png");
    return surface != nullptr;
}

void Animal::update() {
    x += velocityX;
    y += velocityY;

    // выход за карту и возвращение в нее. Приходится писать таким образом из-за того,
    // что % имеет знак делимого (стандарт C++11)
    x = (x % SCREEN_WIDTH + SCREEN_WIDTH) % SCREEN_WIDTH;

    collisionRectangle.x = x + 5;
    collisionRectangle.y = y + 5;
}

bool Animal::isAlive() const {
    return alive;
}

bool Animal::isCollided(std::shared_ptr<Bullet> bullet) {
    SDL_Rect bulletRectangle = bullet->getCollisionRectangle();

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

// TODO delete after testing (base class draw does all needed work)
void Animal::draw() const {
    SDL_Rect tempRect = collisionRectangle;
    auto screen = SDL_GetVideoSurface();
    SDL_FillRect(screen, &tempRect, SDL_MapRGB(screen->format, 255, 255, 255));
    DrawableElement::draw();
}

void Animal::makeDead() {
    alive = false;
}