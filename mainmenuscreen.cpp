#include "mainmenuscreen.h"
#include "functions.h"
#include "gameplayscreen.h"
#include "highscoresscreen.h"
#include "enternamescreen.h"

void MainMenuScreen::loadContent(){
    int x = SDL_GetVideoSurface()->w / 2 - 80;
    int y = 100;
    TTF_Font *font = screenManager->getMenuFont();

    menuEntries.push_back(MenuEntry("Играть", font, x, y, [this] {
        screenManager->addScreen(std::make_shared<GameplayScreen>());
    }));
    menuEntries.push_back(MenuEntry("Рекорды", font, x, y + 100, [this] {
        screenManager->addScreen(std::make_shared<HighScoresScreen>());
    }));
    menuEntries.push_back(MenuEntry("Смена игрока", font, x, y + 200, [this] {
        screenManager->addScreen(std::make_shared<EnterNameScreen>());
        exited = true;
    }));
    menuEntries.push_back(MenuEntry("Выход", font, x, y + 300, [this] {
        exited = true;
    }));

    nameSurface = TTF_RenderUNICODE_Solid(screenManager->getTextFont(),
            screenManager->getName().data(), {0x9A, 0xCD, 0x32});
}

void MainMenuScreen::unloadContent() {
    SDL_FreeSurface(nameSurface);
}

void MainMenuScreen::draw() {
    MenuScreen::draw();
    auto canvas = SDL_GetVideoSurface();
    applySurface(canvas->w / 2 - 80, 500, nameSurface, canvas);
}
