#include "menuentry.h"
#include "functions.h"

MenuEntry::MenuEntry(std::string text, TTF_Font *font, int x, int y,
        std::function<void(void)> actionOnSelection)
        : font(font),
          actionOnSelection(actionOnSelection),
          text(text), x(x), y(y)  {

}

void MenuEntry::onSelect() {
    actionOnSelection();
}

void MenuEntry::draw(bool selected) {
    SDL_Color textColor = selected ? activated : deactivated;
    surface = TTF_RenderUTF8_Solid(font, text.c_str(), textColor);
    applySurface(x, y, surface, SDL_GetVideoSurface());
}
