#include "menuentry.h"
#include "functions.h"

MenuEntry::MenuEntry(std::string text, ScreenManager &screenManager,
        std::function<void(void)> actionOnSelection, int x, int y)
        : screenManager(screenManager),
          actionOnSelection(actionOnSelection),
          text(text), x(x), y(y)  {
    surface = TTF_RenderUTF8_Solid(screenManager.getMenuFont(), text.c_str(), textColor);
}

void MenuEntry::onSelect() {
    actionOnSelection();
}

void MenuEntry::draw() {
    applySurface(x, y, surface, SDL_GetVideoSurface());
}
