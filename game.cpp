#include "game.h"
#include <iostream>

Game::Game() : background{0, 0} {
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

    background.initialize();
    return true;
}

void Game::handleEvents(SDL_Event &event) {
    if (event.type == SDL_QUIT) {
        running = false;
    }
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        running = false;
    }
}

void Game::logic() {

}

void Game::render() {
    background.render(screen);
    SDL_Flip(screen);
}

void Game::cleanUp() {
    SDL_Quit();
}