#include "mainmenuscreen.h"
#include "functions.h"
#include "gameplayscreen.h"

void MainMenuScreen::loadContent(){
    surface = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_second_try/images/nebula_brown.png");
}

void MainMenuScreen::unloadContent() {
    SDL_FreeSurface(surface);
}

//void MainMenuScreen::handleInput(const SDL_Event &event) {
//    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
//        screenManager->addScreen(std::make_shared<GameplayScreen>());
//    }
//}

void MainMenuScreen::draw() {
    SDL_Rect temp;
    temp.x = 0;
    temp.y = 0;
    temp.w = 200;
    temp.h = 250;
    applySurface(300, 150, surface, SDL_GetVideoSurface(), &temp);
    MenuScreen::draw();
}

MainMenuScreen::MainMenuScreen() {
    menuEntries.push_back(MenuEntry("Играть", screenManager, 200, 200, [this] {
        screenManager->addScreen(std::make_shared<GameplayScreen>());
    }));
}
