#include "gamescreen.h"

GameScreen::GameScreen() {
    state = ScreenState::ACTIVE;
    popup = false;
    exited = false;
}

void GameScreen::update(bool otherScreenHasFocus, bool coveredByOtherScreen) {
    this->otherScreenHasFocus = otherScreenHasFocus;
    if (exited) {
        screenManager->removeScreen(std::shared_ptr<GameScreen>(this));
    } else if (coveredByOtherScreen) {
        state = ScreenState::HIDDEN;
    } else {
        state = ScreenState::ACTIVE;
    }
}

bool GameScreen::operator==(const GameScreen &b) {
    return this == &b;
}