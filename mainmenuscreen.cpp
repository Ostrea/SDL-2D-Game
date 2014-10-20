#include "mainmenuscreen.h"
#include "functions.h"

void MainMenuScreen::loadContent(){
    surface = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_second_try/images/nebula_brown.png");
}

void MainMenuScreen::unloadContent() {
    SDL_FreeSurface(surface);
}

void MainMenuScreen::handleInput(const SDL_Event &event) {
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
        exited = true;
    }
}

void MainMenuScreen::draw() {
    applySurface(0, 0, surface, SDL_GetVideoSurface());
}
