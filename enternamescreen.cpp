#include "enternamescreen.h"
#include "mainmenuscreen.h"
#include "functions.h"

void EnterNameScreen::loadContent(){
    textSurface = nullptr;
    promptSurface = TTF_RenderUTF8_Solid(screenManager->getMenuFont(), "Введите имя", textColor);
}

void EnterNameScreen::unloadContent() {
    SDL_FreeSurface(textSurface);
    SDL_FreeSurface(promptSurface);

    SDL_EnableUNICODE(SDL_DISABLE);
}

void EnterNameScreen::handleInput(const SDL_Event &event) {
    if( event.type == SDL_KEYDOWN ) {
        std::string temp = text;

        if (text.length() <= 5) {
            if ((event.key.keysym.unicode >= (Uint16) 'A') && (event.key.keysym.unicode <= (Uint16) 'Z')) {
                text += (char) event.key.keysym.unicode;
            } else if ((event.key.keysym.unicode >= (Uint16) 'a') && (event.key.keysym.unicode <= (Uint16) 'z')) {
                text += (char) event.key.keysym.unicode;
            }
        }

        if ((event.key.keysym.sym == SDLK_BACKSPACE) && (text.length() != 0)) {
            text.erase(text.length() - 1);
        }

        if (text != temp) {
            SDL_FreeSurface(textSurface);

            textSurface = TTF_RenderUTF8_Solid(screenManager->getMenuFont(), text.c_str(), textColor);
        }
    }

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
        screenManager->setName(text);
        screenManager->addScreen(std::make_shared<MainMenuScreen>());
        exited = true;
    }
}

void EnterNameScreen::draw() {
    SDL_Surface *canvas = SDL_GetVideoSurface();
    SDL_Rect rect = {350, 150, 250, 200};
    SDL_FillRect(canvas, &rect, SDL_MapRGB(canvas->format, 100, 255, 20));

    applySurface(370, 150, promptSurface, canvas);

    if (textSurface != nullptr) {
        applySurface(370, 200, textSurface, canvas);
    }
}

EnterNameScreen::EnterNameScreen() {
    popup = true;

    SDL_EnableUNICODE(SDL_ENABLE);
}
