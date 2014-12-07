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
    text.push_back(TTF_RenderUTF8_Solid(screenManager->getMenuFont(), "Ок", {0xFF, 0x99, 0x33}));
}

void HelpScreen::unloadContent() {
    for (auto surface : text) {
        SDL_FreeSurface(surface);
    }
}

void HelpScreen::handleInput(SDL_Event const & event){
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
        exited = true;
    }
}

void HelpScreen::draw() {
    auto canvas = SDL_GetVideoSurface();
    Sint16 x = 160;
    Sint16 y = 20;
    SDL_Rect rect = {x, y, 460, 570};
    SDL_FillRect(canvas, &rect, SDL_MapRGB(canvas->format, 0, 0, 0));

    x += 20;
    y += 20;
    for (auto surface : text) {
        applySurface(x, y, surface, canvas);
        y += 50;
    }
}
