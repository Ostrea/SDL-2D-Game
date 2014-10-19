#include "backgroundscreen.h"
#include "functions.h"
#include "mainmenuscreen.h"

void BackgroundScreen::loadContent(){
    surface = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_second_try/images/nebula_blue.png");
}

void BackgroundScreen::unloadContent() {
    SDL_FreeSurface(surface);
}

void BackgroundScreen::handleInput(const SDL_Event &event) {
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
        screenManager->addScreen(std::make_shared<MainMenuScreen>());
    }
}

void BackgroundScreen::draw() {
    applySurface(0, 0, surface, SDL_GetVideoSurface());
}