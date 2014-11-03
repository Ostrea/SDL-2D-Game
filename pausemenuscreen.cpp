#include "pausemenuscreen.h"

void PauseMenuScreen::loadContent(){
    menuEntries.push_back(MenuEntry("Продолжить", screenManager->getMenuFont(), 400, 200, [this] {
        gameTimer.unpause();
        exited = true;
    }));
    menuEntries.push_back(MenuEntry("Выход", screenManager->getMenuFont(), 400, 300, [this] {
        screenManager->setNeedToExit(true);
    }));
}

void PauseMenuScreen::unloadContent() {

}

void PauseMenuScreen::draw() {
    MenuScreen::draw();
}