#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "SDL/SDL.h"
#include <string>

SDL_Surface *loadImage(std::string fileName);
void applySurface(int x, int y, SDL_Surface *source,
        SDL_Surface *destination, SDL_Rect *clip = nullptr);

#endif // FUNCTIONS_H