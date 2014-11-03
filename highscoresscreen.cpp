#include "highscoresscreen.h"
#include "mainmenuscreen.h"

void HighScoresScreen::loadContent(){

}

void HighScoresScreen::unloadContent() {

}

void HighScoresScreen::handleInput(const SDL_Event &event) {
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
        exited = true;
    }
}

void HighScoresScreen::draw() {
    SDL_Surface *canvas = SDL_GetVideoSurface();
    SDL_Rect rect = {100, 100, 400, 400};
    SDL_FillRect(canvas, &rect, SDL_MapRGB(canvas->format, 100, 255, 20));
}
