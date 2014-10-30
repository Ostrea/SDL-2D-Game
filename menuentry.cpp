#include "menuentry.h"

MenuEntry::MenuEntry(std::string text, ScreenManager &screenManager,
        std::function<void(void)> actionOnSelection) : screenManager(screenManager),
            actionOnSelection(actionOnSelection) {
    this->text = text;
    x = 0;
    y = 0;
}

void MenuEntry::onSelect() {
    actionOnSelection();
}

void MenuEntry::draw() {
}
