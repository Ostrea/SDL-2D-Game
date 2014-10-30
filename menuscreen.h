#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "gamescreen.h"
#include <vector>
#include "menuentry.h"

class MenuScreen : public GameScreen {

public:
    virtual void handleInput(const SDL_Event &event) override;

    virtual void draw() override;

protected:
    std::vector<MenuEntry> menuEntries;
    int selectedEntry = 0;
};

#endif // MENUSCREEN_H