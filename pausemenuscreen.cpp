#include "pausemenuscreen.h"

void PauseMenuScreen::loadContent(){
    menuEntries.push_back(MenuEntry("Продолжить", screenManager, 400, 200, [this] {
        gameTimer.unpause();
        exited = true;
    }));
    menuEntries.push_back(MenuEntry("Выход", screenManager, 400, 300, [this] {
        screenManager->setNeedToExit(true);
    }));
}

void PauseMenuScreen::unloadContent() {

}

void PauseMenuScreen::draw() {
    MenuScreen::draw();
}