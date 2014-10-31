#include "menuentry.h"
#include "functions.h"

MenuEntry::MenuEntry(std::string text, ScreenManager *screenManager, int x, int y,
        std::function<void(void)> actionOnSelection)
        : screenManager(screenManager),
          actionOnSelection(actionOnSelection),
          text(text), x(x), y(y)  {

}

void MenuEntry::onSelect() {
    actionOnSelection();
}

void MenuEntry::draw(bool selected) {
    SDL_Color textColor = selected ? activated : deactivated;
    surface = TTF_RenderUTF8_Solid(screenManager->getMenuFont(), text.c_str(), textColor);
    applySurface(x, y, surface, SDL_GetVideoSurface());
}
