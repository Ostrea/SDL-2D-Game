#include <iostream>
#include <SDL/SDL_ttf.h>
#include "gametemp.h"
#include "backgroundscreen.h"
#include "mainmenuscreen.h"
#include "timer.h"

Game::Game() {
    running = true;
    canvas = nullptr;
}

int Game::run() {
    if (!initialize()) {
        return -1;
    }

    Timer fpsTimer;
    screenManager.addScreen(std::make_shared<BackgroundScreen>());
    screenManager.addScreen(std::make_shared<MainMenuScreen>());
    SDL_Event event;
    while (running) {
        fpsTimer.start();

        while (SDL_PollEvent(&event)) {
            handleEvents(event);
        }

        screenManager.update();

        screenManager.draw();

        if (screenManager.exitGame()) {
            running = false;
        }

        Uint32 ticks = fpsTimer.getTicks();
        if (ticks < 1000 / 60 ) {
            SDL_Delay((1000 / 60) - ticks);
        }
    }

    cleanUp();
    return 0;
}

bool Game::initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "Не удалось запустить SDL.\n";
        return false;
    }

    if (TTF_Init() == -1) {
        std::cerr << "Не удалось запустить SDL TTF.\n";
        return false;
    }

    canvas = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (canvas == nullptr) {
        std::cerr << "Не удалось создать окно.\n";
        return false;
    }
    SDL_WM_SetCaption("Hunting", nullptr);

    screenManager.loadContent();

    return true;
}

void Game::handleEvents(SDL_Event const &event) {
    screenManager.handleEvents(event);
    if (event.type == SDL_QUIT) {
        running = false;
    }
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        running = false;
    }
}

void Game::update() {

}

void Game::draw() {

}

void Game::cleanUp() {
    screenManager.unloadContent();
    TTF_Quit();
    SDL_Quit();
}
