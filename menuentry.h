#ifndef MENUENTRY_H
#define MENUENTRY_H

#include <string>
#include "gameplayscreen.h"

class ScreenManager;

class MenuEntry {

public:
    MenuEntry(std::string text, ScreenManager &screenManager,
            std::function<void(void)> actionOnSelection, int x, int y);

    void onSelect();

    void draw();

private:
    ScreenManager &screenManager;
    std::string text;
    int x;
    int y;
    std::function<void(void)> actionOnSelection;
    SDL_Surface *surface;
    SDL_Color textColor = {255, 255, 255};
};

#endif // MENUENTRY_H