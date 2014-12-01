#include <iostream>
#include "enternamescreen.h"
#include "mainmenuscreen.h"
#include "functions.h"
#include <locale>

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
        auto temp = text;

        if (currentLength <= 5) {
            Uint16 unicodeCode = event.key.keysym.unicode;
            if (((unicodeCode >= static_cast<Uint16>('A')) &&
                    (unicodeCode <= static_cast<Uint16>('Z'))) ||
                    ((unicodeCode >= static_cast<Uint16>('a')) &&
                    (unicodeCode <= static_cast<Uint16>('z'))) ||
                    ((unicodeCode >= static_cast<Uint16>(u'А')) &&
                    (unicodeCode <= static_cast<Uint16>(u'я'))) ||
                    ((unicodeCode == static_cast<Uint16>(u'Ё')) ||
                    (unicodeCode == static_cast<Uint16>(u'ё')))) {

                if (!text.empty()) {
                    text.pop_back();
                }
                text.push_back(unicodeCode);
                text.push_back('\0');
                currentLength++;
            }
        }

        if ((event.key.keysym.sym == SDLK_BACKSPACE) && (currentLength != 0)) {
            if (!text.empty()) {
                text.pop_back();
                text.pop_back();
                text.push_back('\0');
                currentLength--;
            }
        }
        
        if (text != temp) {
            SDL_FreeSurface(textSurface);

            textSurface = TTF_RenderUNICODE_Solid(screenManager->getTextFont(), text.data(), nameColor);
        }
    }

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN && text.size() > 0) {
        screenManager->setName(text);
        screenManager->addScreen(std::make_shared<MainMenuScreen>());
        exited = true;
    }
}

void EnterNameScreen::draw() {
    SDL_Surface *canvas = SDL_GetVideoSurface();

    applySurface(canvas->w / 2 - 85, canvas->h / 2 - 40, promptSurface, canvas);

    if (textSurface != nullptr) {
        applySurface(canvas->w / 2 - 45, canvas->h / 2, textSurface, canvas);
    }
}

EnterNameScreen::EnterNameScreen() {
    popup = true;

    SDL_EnableUNICODE(SDL_ENABLE);
}
