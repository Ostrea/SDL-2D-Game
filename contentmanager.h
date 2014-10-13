#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

#include "SDL/SDL.h"

class ContentManager {

public:
    void loadContent();

    void unloadContent();

    SDL_Surface *getBackground() const {
        return background;
    }

    SDL_Surface *getAnimal() const {
        return animal;
    }

    SDL_Surface *getBullet() const {
        return bullet;
    }

    SDL_Surface *getPlayer() const {
        return player;
    }

private:
    SDL_Surface *background;
    SDL_Surface *animal;
    SDL_Surface *bullet;
    SDL_Surface *player;
};

#endif // CONTENTMANAGER_H