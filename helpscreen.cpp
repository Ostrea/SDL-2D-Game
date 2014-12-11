#include "helpscreen.h"
#include "functions.h"

void HelpScreen::loadContent() {
    auto font = screenManager->getTextFont();
    SDL_Color color = {255, 255, 255};
    text.push_back(TTF_RenderUTF8_Solid(font, "Цель игры в том, чтобы", color));
    text.push_back(TTF_RenderUTF8_Solid(font, "за 20 секунд уничтожить", color));
    text.push_back(TTF_RenderUTF8_Solid(font, "как можно больше енотов.", color));
    text.push_back(TTF_RenderUTF8_Solid(font, "Управление:", color));
    text.push_back(TTF_RenderUTF8_Solid(font, "стрелка влево - сдвинуться", color));
    text.push_back(TTF_RenderUTF8_Solid(font, "влево", color));
    text.push_back(TTF_RenderUTF8_Solid(font, "стрелка вправо - сдвинуться", color));
    text.push_back(TTF_RenderUTF8_Solid(font, "вправо", color));
    text.push_back(TTF_RenderUTF8_Solid(font, "p - пауза", color));
    text.push_back(TTF_RenderUTF8_Solid(font, "esc - выйти из игры", color));
    background = loadImage("/home/ostrea/Programs/Labs_second_term/Gushin/"
            "Coursework_third_try/images/help_backgound.png");
}

void HelpScreen::unloadContent() {
    for (auto surface : text) {
        SDL_FreeSurface(surface);
    }
    SDL_FreeSurface(background);
}

void HelpScreen::handleInput(SDL_Event const & event){
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
        exited = true;
    }
}

void HelpScreen::draw() {
    auto canvas = SDL_GetVideoSurface();
    int x = 160;
    int y = 20;
    applySurface(x, y, background, canvas);
    x += 20;
    y += 20;
    for (auto surface : text) {
        applySurface(x, y, surface, canvas);
        y += 50;
    }
}
