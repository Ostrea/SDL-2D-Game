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
    SDL_Surface *canvas = SDL_GetVideoSurface();
    SDL_Rect rect = {350, 150, 250, 200};
    SDL_FillRect(canvas, &rect, SDL_MapRGB(canvas->format, 100, 255, 20));
    MenuScreen::draw();
}