#include <iostream>
#include "gameplayscreen.h"
#include "background.h"
#include <stdexcept>

void GameplayScreen::loadContent() {
    canvas = SDL_GetVideoSurface();

    allElements.push_back(std::make_shared<Background>(0, 0, contentManager));
    player = std::make_shared<Player>(canvas ->w / 2 -40,
            canvas->h - 100, contentManager);
    allElements.push_back(player);
    currentNumberOfAnimals = 0;

    contentManager.loadContent();

    for (auto element : allElements) {
        if (!element->initialize()) {
            throw std::runtime_error(std::string("Не удалось инициализировать какой-то объект, ") + SDL_GetError());
        }
    }
}

void GameplayScreen::unloadContent() {
    contentManager.unloadContent();
}

void GameplayScreen::handleInput(const SDL_Event &event) {
    player->handleInput(event);
}

void GameplayScreen::update(bool otherScreenHasFocus, bool coveredByOtherScreen) {
    GameScreen::update(otherScreenHasFocus, coveredByOtherScreen);
    if (!otherScreenHasFocus) {
        numberOfCollisionsAnimalsBullets();
        for (auto element : allElements) {
            element->update();
        }
        removeDeadElements();
    }
}

void GameplayScreen::draw() {
    for (auto element : allElements) {
        element->draw();
    }
    SDL_Flip(canvas);
}

void GameplayScreen::createAnimal() {

}

void GameplayScreen::removeDeadElements() {

}

bool GameplayScreen::haveAnimalCollidedWithBullet(std::shared_ptr<Bullet> bullet) {
    return false;
}

int GameplayScreen::numberOfCollisionsAnimalsBullets() {
    return 0;
}
