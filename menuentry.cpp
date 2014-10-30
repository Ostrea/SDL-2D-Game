#include "menuentry.h"
#include "functions.h"

MenuEntry::MenuEntry(std::string text, ScreenManager *screenManager, int x, int y,
        std::function<void(void)> actionOnSelection)
        : screenManager(screenManager),
          actionOnSelection(actionOnSelection),
          text(text), x(x), y(y)  {
    TTF_Font *font = TTF_OpenFont("/usr/share/fonts/TTF/DejaVuSans-Bold.ttf", 10);
    surface = TTF_RenderUTF8_Solid(font, text.c_str(), textColor);
}

void MenuEntry::onSelect() {
    actionOnSelection();
}

void MenuEntry::draw() {
    applySurface(x, y, surface, SDL_GetVideoSurface());
}
