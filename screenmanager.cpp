#include "screenmanager.h"
#include "gamescreen.h"
#include "constants.h"

void ScreenManager::loadContent(){
    menuFont = TTF_OpenFont("/home/ostrea/Programs/SOTH 2/SOTH/a_MachinaOrtoShtRegular.ttf", 30);
    gameFont = TTF_OpenFont("/usr/share/fonts/TTF/DejaVuSans-Bold.ttf", 10);
}

void ScreenManager::unloadContent() {
    for (auto screen : screens) {
        screen->unloadContent();
    }

    TTF_CloseFont(menuFont);
    TTF_CloseFont(gameFont);
}

void ScreenManager::update() {
    auto screensToUpdate = screens;
    bool otherScreenHasFocus = false;
    bool coveredByOtherScreen = false;

    while (!screensToUpdate.empty()) {
        auto screen = screensToUpdate.back();
        screensToUpdate.pop_back();

        screen->update(otherScreenHasFocus, coveredByOtherScreen);

        if (screen->getState() == ScreenState::ACTIVE) {
          if (!otherScreenHasFocus) {
//                screen->handleInput(event);
                otherScreenHasFocus = true;
            }
        }

        if (!screen->isPopup()) {
            coveredByOtherScreen = true;
        }

        if (screen->isExited()) {
            removeScreen(screen);
        }
    }
}

void ScreenManager::draw() {
    for (auto screen : screens) {
//        if (screen->getState() == ScreenState::HIDDEN) {
//            continue;
//        }
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
}

void ScreenManager::handleEvents(const SDL_Event &event) {
    auto screen = screens.back();
    screen->handleInput(event);
}
