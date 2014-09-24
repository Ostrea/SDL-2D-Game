#include "functions.h"
#include <SDL/SDL_image.h>

SDL_Surface *loadImage(std::string fileName) {
    SDL_Surface *loadedImage = IMG_Load(fileName.c_str());
    SDL_Surface *optimizedImage {nullptr};

    if (loadedImage != nullptr) {
        // создается оптимизированная поверхность
        optimizedImage = SDL_DisplayFormatAlpha(loadedImage);

        SDL_FreeSurface(loadedImage);
    }

    return optimizedImage;
}

void applySurface(int x, int y, SDL_Surface *source,
        SDL_Surface *destination, SDL_Rect *clip) {
    SDL_Rect offset{static_cast<Sint16>(x), static_cast<Sint16>(y)};
    SDL_BlitSurface(source, clip, destination, &offset);
}