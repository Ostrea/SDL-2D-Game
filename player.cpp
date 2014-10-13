#include "player.h"

void Player::handleInput(SDL_Event const &event){
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

void Player::update() {
    if (x + velocityX <= SDL_GetVideoSurface()->w - 90 && x + velocityX > 0 ) {
        x += velocityX;
    }
}

bool Player::initialize() {
    surface = contentManager.getPlayer();
//    surface = loadImage("/home/ostrea/Programs/Labs_second_term/"
//            "Gushin/Coursework_third_try/images/ship_without_thrusters.png");
    return surface != nullptr;
}

Player::Player(int x, int y, ContentManager const &contentManager) : DrawableElement{x, y},
            contentManager(contentManager) {
    velocityX = 0;
    velocityY = 0;
}

void Player::shoot() {
    SDL_Event tempEvent;
    tempEvent.type = SDL_USEREVENT;
    tempEvent.user.code = 0;
    tempEvent.user.data1 = nullptr;
    tempEvent.user.data2 = nullptr;
    SDL_PushEvent(&tempEvent);
}

