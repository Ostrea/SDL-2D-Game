#include <ncurses.h>
#include <curses.h>
#include "screenmanager.h"
#include "gamescreen.h"
#include "constants.h"

void ScreenManager::loadContent(){

}

void ScreenManager::unloadContent() {
    for (auto screen : screens) {
        screen->unloadContent();
    }
}

void ScreenManager::update(const SDL_Event &event) {
    screensToUpdate.clear();
    screensToUpdate = screens;
    bool otherScreenHasFocus = false;
    bool coveredByOtherScreen = false;

    while (!screensToUpdate.empty()) {
        auto screen = screensToUpdate.back();
        screensToUpdate.pop_back();

        screen->update(otherScreenHasFocus, coveredByOtherScreen);

        if (screen->getState() == ScreenState::ACTIVE) {
            if (!otherScreenHasFocus) {
                screen->handleInput(event);
                otherScreenHasFocus = true;
            }
        }

        if (!screen->isPopup()) {
            coveredByOtherScreen = true;
        }
    }
}

void ScreenManager::draw() {
    for (auto screen : screens) {
        if (screen->getState() == ScreenState::HIDDEN) {
            continue;
        }
        screen->draw();
    }
    SDL_Flip(SDL_GetVideoSurface());
}

void ScreenManager::addScreen(std::shared_ptr<GameScreen> screen) {
    screen->setScreenManager(this);
    screen->loadContent();
    screens.push_back(screen);
}

void ScreenManager::removeScreen(std::shared_ptr<GameScreen> screen) {
    screen->unloadContent();
    screens.remove(screen);
    screensToUpdate.remove(screen);
}
