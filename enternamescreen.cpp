#include <iostream>
#include "enternamescreen.h"
#include "mainmenuscreen.h"
#include "functions.h"
#include <locale>
#include <unordered_map>

void EnterNameScreen::loadContent(){
    textSurface = nullptr;
    promptSurface = TTF_RenderUTF8_Solid(screenManager->getMenuFont(), "Введите имя", textColor);
}

void EnterNameScreen::unloadContent() {
    SDL_FreeSurface(textSurface);
    SDL_FreeSurface(promptSurface);

    SDL_EnableUNICODE(SDL_DISABLE);
}

// TODO for russian get unicode code and convert it to UTF8 code
void EnterNameScreen::handleInput(const SDL_Event &event) {
    if( event.type == SDL_KEYDOWN ) {
        auto temp = text;
        std::string test = "1";
//        char te = '\u0444';
        wchar_t t = L'л';
        size_t index;
//        std::cout << "Ж\n";
//        printf("%u\n", "Ж"[0]);
//        std::cout << std::stoul(test, &index, 10) << std::endl;
//        std::string a = "привет. Hellop\n";
//        std::cout << a.size() << std::endl;
//        std::cout << a.length() << std::endl;
//        std::cout << text.length() << std::endl;
//        std::cout << event.key.keysym.unicode << std::endl;
        static std::unordered_map<Uint16, std::string> dictionary = {{1046,"Ж"}};

        if (currentLength <= 5) {
            if ((event.key.keysym.unicode >= static_cast<Uint16>('A')) &&
                    (event.key.keysym.unicode <= static_cast<Uint16>('Z'))) {
                text += (char) event.key.keysym.unicode;
                currentLength++;
            } else if ((event.key.keysym.unicode >= static_cast<Uint16>('a')) &&
                    (event.key.keysym.unicode <= static_cast<Uint16>('z'))) {
                text += (char) event.key.keysym.unicode;
                currentLength++;
//            }
            } else if ((event.key.keysym.unicode >= static_cast<Uint16>(u'а')) &&
                    (event.key.keysym.unicode <= static_cast<Uint16>(u'я'))) {
//                text += (char) event.key.keysym.unicode;
//                text += dictionary.at(1046);
            } else if ((event.key.keysym.unicode >= static_cast<Uint16>(u'А')) &&
                    (event.key.keysym.unicode <= static_cast<Uint16>(u'Я'))) {
//                text += (char) event.key.keysym.unicode;
            }
            if (event.key.keysym.unicode == 1046) {
                text += dictionary.at(1046);
                currentLength++;
//                std::cout << dictionary.at(1046) << std::endl;
            }
        }
        std::cout << text.length() << std::endl;
        if ((event.key.keysym.sym == SDLK_BACKSPACE) && (currentLength != 0)) {
            try {
                if (text.substr(text.length() - 2, 2) == "Ж") {
                    text.pop_back();
                    text.pop_back();
                } else {
                    text.pop_back();
                }
            } catch (std::out_of_range exception) {
                text.pop_back();
            }
            currentLength--;
        }

        if (text != temp) {
            SDL_FreeSurface(textSurface);

//            textSurface = TTF_RenderUNICODE_Solid(screenManager->getTextFont(),
//                    reinterpret_cast<const Uint16*>(text.c_str()), nameColor);

            textSurface = TTF_RenderUTF8_Solid(screenManager->getTextFont(), text.c_str(), nameColor);
        }
    }

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN && text.length() > 0) {
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
