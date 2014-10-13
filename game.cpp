#include "game.h"
#include "timer.h"
#include <iostream>
#include <chrono>
#include <random>

Game::Game() {
    allElements.push_back(std::make_shared<Background>(0, 0, contentManager));
    player = std::make_shared<Player>(SCREEN_WIDTH / 2 -40, SCREEN_HEIGHT - 100, contentManager);
    allElements.push_back(player);

    running = true;
    canvas = nullptr;
    currentNumberOfAnimals = 0;
}

int Game::run() {
    if (!initialize()) {
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

        update();
        draw();

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

    canvas = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (canvas == nullptr) {
        std::cerr << "Не удалось создать окно.\n";
        return false;
    }
    SDL_WM_SetCaption("Hunting", nullptr);

    contentManager.loadContent();

    for (auto element : allElements) {
        if (!element->initialize()) {
            std::cerr << "Что-то пошло не так: " << SDL_GetError();
            return false;
        }
    }

    return true;
}

void Game::handleEvents(SDL_Event const &event) {
    player->handleInput(event);

    if (event.type == SDL_USEREVENT) {
        std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(player->getX() + 42,
                player->getY(), -3, contentManager);
        bullet->initialize();
        allElements.push_back(bullet);
        bullets.push_back(bullet);
    }
    if (event.type == SDL_QUIT) {
        running = false;
    }
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        running = false;
    }
}

void Game::update() {
    numberOfCollisionsAnimalsBullets();
    for (auto element : allElements) {
        element->update();
    }
    removeDeadElements();
}

void Game::draw() {
    for (auto element : allElements) {
        element->draw();
    }
    SDL_Flip(canvas);
}

void Game::cleanUp() {
    contentManager.unloadContent();
    SDL_Quit();
}

void Game::createAnimal() {
    if (currentNumberOfAnimals <= MAXIMUM_NUMBER_OF_ANIMALS) {
        unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::minstd_rand0 generator(seed);
        std::uniform_int_distribution<int> distributionX(100, SCREEN_WIDTH - 100);
        std::uniform_int_distribution<int> distributionY(100, SCREEN_HEIGHT - 195);
        std::uniform_int_distribution<int> distributionVelocity(1, 2);
        auto getX = std::bind(distributionX, generator);
        auto getY = std::bind(distributionY, generator);
        auto getVelocity = std::bind(distributionVelocity, generator);

        int x{getX()};
        int y{getY()};
        double velocityX{static_cast<double>(getVelocity())};
        std::shared_ptr<Animal> animal = std::make_shared<Animal>(x, y, velocityX, contentManager);
        animal->initialize();
        allElements.push_back(animal);
        animals.push_back(animal);
    }

}

void Game::removeDeadElements() {
    auto element = allElements.begin();
    while (element != allElements.end()) {
        if (!(*element)->isAlive()) {
            element = allElements.erase(element);
        } else {
            element++;
        }
    }

    auto element2 = animals.begin();
    while (element2 != animals.end()) {
        if (!(*element2)->isAlive()) {
            element2 = animals.erase(element2);
        } else {
            element2++;
        }
    }

    auto element3 = bullets.begin();
    while (element3 != bullets.end()) {
        if (!(*element3)->isAlive()) {
            element3 = bullets.erase(element3);
        } else {
            element3++;
        }
    }
}

bool Game::haveAnimalCollidedWithBullet(std::shared_ptr<Bullet> bullet) {
    for (auto animal : animals) {
        if (animal->isAlive()) {
            if (animal->isCollided(bullet)) {
                animal->makeDead();
                return true;
            }
        }
    }
    return false;
}

int Game::numberOfCollisionsAnimalsBullets() {
    int count {0};
    for (auto bullet : bullets) {
        if (haveAnimalCollidedWithBullet(bullet)) {
            bullet->makeDead();
            count++;
        }
    }
    return count;
}