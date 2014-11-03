#include "mainmenuscreen.h"
#include "functions.h"
#include "gameplayscreen.h"
#include "highscoresscreen.h"

void MainMenuScreen::loadContent(){
    menuEntries.push_back(MenuEntry("Играть", screenManager->getMenuFont(), 400, 200, [this] {
        screenManager->addScreen(std::make_shared<GameplayScreen>());
    }));
    menuEntries.push_back(MenuEntry("Рекорды", screenManager->getMenuFont(), 400, 300, [this] {
        screenManager->addScreen(std::make_shared<HighScoresScreen>());
    }));
    menuEntries.push_back(MenuEntry("Выход", screenManager->getMenuFont(), 400, 400, [this] {
        exited = true;
    }));
}

void MainMenuScreen::unloadContent() {

}
