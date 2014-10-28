#include "menuscreen.h"

void MenuScreen::handleInput(const SDL_Event& event){
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                selectedEntry--;
                if (selectedEntry < 0) {
                    selectedEntry = menuEntries.size() - 1;
                }
                break;
            case SDLK_DOWN:
                selectedEntry++;
                if (selectedEntry >= menuEntries.size()) {
                    selectedEntry = 0;
                }
                break;
            case SDLK_RETURN:
                menuEntries.at(selectedEntry).onSelect();
                break;
        }
    }
}

void MenuScreen::draw() {

}
