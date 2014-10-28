#ifndef MENUENTRY_H
#define MENUENTRY_H

#include <string>
#include "gameplayscreen.h"

class ScreenManager;

class MenuEntry {

public:
    MenuEntry(std::string text, ScreenManager &screenManager, std::function<void(void)> actionOnSelection);

    void onSelect();

    void draw();

private:
    ScreenManager &screenManager;
    std::string text;
    int x;
    int y;
    std::function<void(void)> actionOnSelection;
};

#endif // MENUENTRY_H