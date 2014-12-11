#include "pausemenuscreen.h"

void PauseMenuScreen::loadContent(){
    int x = SDL_GetVideoSurface()->w / 2 - 80;
    int y = 200;
    TTF_Font *font = screenManager->getMenuFont();

    menuEntries.push_back(MenuEntry("Продолжить", font, x, y, [this] {
        gameTimer.unpause();
        exited = true;
    }));
    menuEntries.push_back(MenuEntry("Выход", font, x, y + 100, [this] {
//        screenManager->setNeedToExit(true);
        exited = true;
        screenManager->closePreviousScreen();
    }));
}

void PauseMenuScreen::unloadContent() {

}