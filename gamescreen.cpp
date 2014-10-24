#include "gamescreen.h"

GameScreen::GameScreen() {
    state = ScreenState::ACTIVE;
    popup = false;
    exited = false;
}

void GameScreen::update(bool otherScreenHasFocus, bool coveredByOtherScreen) {
    this->otherScreenHasFocus = otherScreenHasFocus;
    if (coveredByOtherScreen) {
        state = ScreenState::HIDDEN;
    } else {
        state = ScreenState::ACTIVE;
    }
}