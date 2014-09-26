#include "player.h"
#include "functions.h"

void Player::handleEvents(SDL_Event& event){
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                velocityX -= ACCELERATION;
                break;
            case SDLK_RIGHT:
                velocityX += ACCELERATION;
                break;
            case SDLK_SPACE:
                shoot();
                break;
        }
    } else if (event.type == SDL_KEYUP) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                velocityX += ACCELERATION;
                break;
            case SDLK_RIGHT:
                velocityX -= ACCELERATION;
                break;
        }
    }
}

void Player::logic() {
    if (x + velocityX <= SCREEN_WIDTH - 90 && x + velocityX > 0 ) {
        x += velocityX;
    }
}

bool Player::initialize() {
    surface = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/ship_without_thrusters.png");
    return surface != nullptr;
}

Player::Player(int x, int y, const int width, std::list<std::shared_ptr<StaticGraphicalElement>> &allElements,
        std::list<std::shared_ptr<Bullet>> &bullets)
        : StaticGraphicalElement{x, y},
          MovableGraphicalElement{0, 0}, SCREEN_WIDTH{width}, allElements{allElements},
          bullets{bullets}{

}

void Player::shoot() {
    std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(x + 42, y, -3);
    bullet->initialize();
    allElements.push_back(bullet);
    bullets.push_back(bullet);
}

void Player::collisionDetection() {

}
