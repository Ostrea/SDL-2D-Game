#include "game.h"
#include <iostream>
#include "functions.h"

Game::Game() {
    running = true;
    screen = nullptr;
    background = nullptr;
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
    background = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/nebula_brown.png");
    if (background == nullptr) {
        std::cerr << "Не удалось загрузить фон.\n";
        return false;
    }
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
    applySurface(0, 0, background, screen);
    SDL_Flip(screen);
}

void Game::cleanUp() {
    SDL_FreeSurface(background);
    SDL_Quit();
}