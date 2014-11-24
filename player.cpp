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
                createBullet();
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
    if (x + velocityX <= SDL_GetVideoSurface()->w - 95 && x + velocityX > -50 ) {
        x += velocityX;
    }
}

bool Player::initialize() {
    surface = contentManager.getPlayer();
    return surface != nullptr;
}

Player::Player(int x, int y, ContentManager const &contentManager, std::function<void(void)> createBullet) :
        DrawableElement{x, y},
        contentManager(contentManager), createBullet(createBullet) {
    velocityX = 0;
    velocityY = 0;
}