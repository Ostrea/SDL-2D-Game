#ifndef MENUENTRY_H
#define MENUENTRY_H

#include <string>
#include "gameplayscreen.h"

class ScreenManager;

class MenuEntry {

public:
    MenuEntry(std::string text, ScreenManager *screenManager, int x, int y,
            std::function<void(void)> actionOnSelection);

    void onSelect();

    void draw(bool selected);

private:
    ScreenManager *screenManager;
    std::string text;
    int x;
    int y;
    std::function<void(void)> actionOnSelection;
    SDL_Surface *surface;
    SDL_Color deactivated = {255, 255, 255};
    SDL_Color activated = {0, 0, 255};
};

#endif // MENUENTRY_H