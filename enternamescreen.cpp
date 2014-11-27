#include <iostream>
#include "enternamescreen.h"
#include "mainmenuscreen.h"
#include "functions.h"
#include <locale>

void EnterNameScreen::loadContent(){
    textSurface = nullptr;
    promptSurface = TTF_RenderUTF8_Solid(screenManager->getMenuFont(), "Введите имя", textColor);

    // таблица для конвертации кодов символов
    // заглавные буквы
    dictionary[1040] = "А";
    dictionary[1041] = "Б";
    dictionary[1042] = "В";
    dictionary[1043] = "Г";
    dictionary[1044] = "Д";
    dictionary[1045] = "Е";
    dictionary[1046] = "Ж";
    dictionary[1047] = "З";
    dictionary[1048] = "И";
    dictionary[1049] = "Й";
    dictionary[1050] = "К";
    dictionary[1051] = "Л";
    dictionary[1052] = "М";
    dictionary[1053] = "Н";
    dictionary[1054] = "О";
    dictionary[1055] = "П";
    dictionary[1056] = "Р";
    dictionary[1057] = "С";
    dictionary[1058] = "Т";
    dictionary[1059] = "У";
    dictionary[1060] = "Ф";
    dictionary[1061] = "Х";
    dictionary[1062] = "Ц";
    dictionary[1063] = "Ч";
    dictionary[1064] = "Ш";
    dictionary[1065] = "Щ";
    dictionary[1066] = "Ъ";
    dictionary[1067] = "Ы";
    dictionary[1068] = "Ь";
    dictionary[1069] = "Э";
    dictionary[1070] = "Ю";
    dictionary[1071] = "Я";

    // строчные буквы
    dictionary[1072] = "а";
    dictionary[1073] = "б";
    dictionary[1074] = "в";
    dictionary[1075] = "г";
    dictionary[1076] = "д";
    dictionary[1077] = "е";
    dictionary[1078] = "ж";
    dictionary[1079] = "з";
    dictionary[1080] = "и";
    dictionary[1081] = "й";
    dictionary[1082] = "к";
    dictionary[1083] = "л";
    dictionary[1084] = "м";
    dictionary[1085] = "н";
    dictionary[1086] = "о";
    dictionary[1087] = "п";
    dictionary[1088] = "р";
    dictionary[1089] = "с";
    dictionary[1090] = "т";
    dictionary[1091] = "у";
    dictionary[1092] = "ф";
    dictionary[1093] = "х";
    dictionary[1094] = "ц";
    dictionary[1095] = "ч";
    dictionary[1096] = "ш";
    dictionary[1097] = "щ";
    dictionary[1098] = "ъ";
    dictionary[1099] = "ы";
    dictionary[1100] = "ь";
    dictionary[1101] = "э";
    dictionary[1102] = "ю";
    dictionary[1103] = "я";

    // Ё и ё
    dictionary[1025] = "Ё";
    dictionary[1105] = "ё";
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
            if ((event.key.keysym.unicode >= static_cast<Uint16>('A')) &&
                    (event.key.keysym.unicode <= static_cast<Uint16>('Z'))) {
                text += (char) event.key.keysym.unicode;
                currentLength++;
            } else if ((event.key.keysym.unicode >= static_cast<Uint16>('a')) &&
                    (event.key.keysym.unicode <= static_cast<Uint16>('z'))) {
                text += (char) event.key.keysym.unicode;
                currentLength++;
            } else if ((event.key.keysym.unicode >= static_cast<Uint16>(u'А')) &&
                    (event.key.keysym.unicode <= static_cast<Uint16>(u'Я'))) {
                text += dictionary.at(event.key.keysym.unicode);
                currentLength++;
            } else if ((event.key.keysym.unicode >= static_cast<Uint16>(u'а')) &&
                    (event.key.keysym.unicode <= static_cast<Uint16>(u'я'))) {
                text += dictionary.at(event.key.keysym.unicode);
                currentLength++;
            } else if ((event.key.keysym.unicode == static_cast<Uint16>(u'Ё'))||
                    (event.key.keysym.unicode == static_cast<Uint16>(u'ё'))) {
                text += dictionary.at(event.key.keysym.unicode);
                currentLength++;
            }
        }

        if ((event.key.keysym.sym == SDLK_BACKSPACE) && (currentLength != 0)) {
            try {
                if (((text.substr(text.length() - 2, 2) >= "А" &&
                        text.substr(text.length() - 2, 2) <= "Я") ||
                        text.substr(text.length() - 2, 2) == "Ё") ||
                        ((text.substr(text.length() - 2, 2) >= "а" &&
                                text.substr(text.length() - 2, 2) <= "я") ||
                        text.substr(text.length() - 2, 2) == "ё")) {
                    text.pop_back();
                    text.pop_back();
                } else {
                    text.pop_back();
                }
            } catch (std::out_of_range) {
                text.pop_back();
            }
            currentLength--;
        }

        if (text != temp) {
            SDL_FreeSurface(textSurface);

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
