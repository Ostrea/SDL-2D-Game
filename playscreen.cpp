#include "playscreen.h"

void PlayScreen::loadContent(){

}

void PlayScreen::unloadContent() {

}

void PlayScreen::handleInput(const SDL_Event &event) {

}

void PlayScreen::update(bool otherScreenHasFocus, bool coveredByOtherScreen) {
    GameScreen::update(otherScreenHasFocus, coveredByOtherScreen);
}

void PlayScreen::draw() {

}

void PlayScreen::createAnimal() {

}

void PlayScreen::removeDeadElements() {

}

bool PlayScreen::haveAnimalCollidedWithBullet(std::shared_ptr<Bullet> bullet) {
    return false;
}

int PlayScreen::numberOfCollisionsAnimalsBullets() {
    return 0;
}
