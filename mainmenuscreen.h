#ifndef MAINMENUSCREEN_H
#define MAINMENUSCREEN_H

#include "menuscreen.h"

class MainMenuScreen : public MenuScreen {

public:
    MainMenuScreen() {
        popup = true;
    }

    virtual void loadContent() override;

    virtual void unloadContent() override;
};

#endif // MAINMENUSCREEN_H