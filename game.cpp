#include "game.h"
#include "animal.h"
#include "timer.h"
#include <iostream>

Game::Game() {
    background = std::make_shared<Background>(0, 0);
    player = std::make_shared<Player>(SCREEN_WIDTH / 2 -40, SCREEN_HEIGHT - 100,
    SCREEN_WIDTH, allElements);
    running = true;
    screen = nullptr;
}

int Game::execute() {
    if (!init()) {
        return -1;
    }

    Timer fpsTimer;
    Timer animalTimer;
    animalTimer.start();

    SDL_Event event;
    while (running) {
        fpsTimer.start();

        while (SDL_PollEvent(&event)) {
            handleEvents(event);
        }

        if (animalTimer.getTicks() > 2000) {
            createAnimal();
            animalTimer.start();
        }

        logic();
        render();

        Uint32 ticks = fpsTimer.getTicks();
        if (ticks < 1000 / 60 ) {
            SDL_Delay((1000 / 60) - ticks);
        }
    }

    cleanUp();
    return 0;
}

bool Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "Не удалось запустить SDL.\n";
        return false;
    }

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == nullptr) {
        std::cerr << "Не удалось создать окно.\n";
        return false;
    }

    SDL_WM_SetCaption("Hunting", nullptr);

    if (!background->initialize()) {
        std::cerr << "Не удалось создать объект фона\n";
        return false;
    }

    if (!player->initialize()) {
        std::cerr << "Не удалось создать игрока\n";
        return false;
    }

    allElements.push_back(background);
    allElements.push_back(player);

    return true;
}

void Game::handleEvents(SDL_Event &event) {
    player->handleEvents(event);

    if (event.type == SDL_QUIT) {
        running = false;
    }
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        running = false;
    }
}

void Game::logic() {
    for (auto element : allElements) {
        element->collisionDetection();
    }
    for (auto element : allElements) {
        element->logic();
    }
}

void Game::render() {
    for (auto element : allElements) {
        element->render(screen);
    }
    SDL_Flip(screen);
}

void Game::cleanUp() {
    SDL_Quit();
}

void Game::createAnimal() {
    int x {350};
    int y {260};
    double velocityX {1};
    double velocityY {1};
    std::shared_ptr<Animal> animal = std::make_shared<Animal>(x, y, velocityX, velocityY);
    animal->initialize();
    allElements.push_back(animal);
}
