#include "game.h"
#include <iostream>
#include "SDL/SDL_image.h"

Game::Game() {
    running = true;
    screen = nullptr;
}

int Game::execute() {
    if (!init()) {
        return -1;
    }
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            handleEvents(event);
        }

        logic();
        render();
    }

    cleanUp();
    return 0;
}

bool Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "Не удалось запустить СДЛ.\n";
        return false;
    }
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == nullptr) {
        std::cerr << "Не удалось создать окно.\n";
        return false;
    }
    return true;
}

void Game::handleEvents(SDL_Event &event) {
    if (event.type == SDL_QUIT) {
        running = false;
    }
}

void Game::logic() {

}

void Game::render() {
    SDL_Flip(screen);
}

void Game::cleanUp() {
    SDL_Quit();
}

SDL_Surface *Game::loadImage(std::string fileName) {
    SDL_Surface *loadedImage = IMG_Load(fileName.c_str());
    SDL_Surface *optimizedImage {nullptr};

    if (loadedImage != nullptr) {
        // создается оптимизированная поверхность
        optimizedImage = SDL_DisplayFormatAlpha(loadedImage);

        SDL_FreeSurface(loadedImage);
    }

    return optimizedImage;
}

void Game::applySurface(int x, int y, SDL_Surface *source,
        SDL_Surface *destination, SDL_Rect *clip) {
    SDL_Rect offset{static_cast<Sint16>(x), static_cast<Sint16>(y)};
    SDL_BlitSurface(source, clip, destination, &offset);
}
