#include "highscoresscreen.h"
#include "functions.h"

void HighScoresScreen::loadContent(){
    for (int i = 0; i < NUMBER_OF_SCORES; ++i) {
        highScores.push_back(std::pair<std::string, int>("Вася", 10));
    }

    for (auto score : highScores) {
        std::string message = score.first + " : " + std::to_string(score.second);
        highScoresSurfaces.push_back(TTF_RenderUTF8_Solid(screenManager->getGameFont(),
                message.c_str(), textColor));
    }
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
    SDL_Rect rect = {100, 100, 400, 600};
    SDL_FillRect(canvas, &rect, SDL_MapRGB(canvas->format, 0, 0, 0));
    int x = 100;
    int y = 100;
    for (auto scoresSurface : highScoresSurfaces) {
        applySurface(x, y, scoresSurface, canvas);
        y += 50;
    }
}
