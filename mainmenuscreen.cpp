#include "mainmenuscreen.h"
#include "functions.h"
#include "gameplayscreen.h"

void MainMenuScreen::loadContent(){
    surface = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_second_try/images/nebula_brown.png");

    menuEntries.push_back(MenuEntry("Играть", screenManager, 400, 200, [this] {
        screenManager->addScreen(std::make_shared<GameplayScreen>());
    }));
    menuEntries.push_back(MenuEntry("Выход", screenManager, 400, 300, [this] {
        exited = true;
    }));
}

void MainMenuScreen::unloadContent() {
    SDL_FreeSurface(surface);
}

void MainMenuScreen::draw() {
    SDL_Rect temp;
    temp.x = 0;
    temp.y = 0;
    temp.w = 200;
    temp.h = 250;
    applySurface(300, 150, surface, SDL_GetVideoSurface(), &temp);
    MenuScreen::draw();
}