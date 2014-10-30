#include <string>
#include "gameplayscreen.h"
#include "background.h"
#include <random>
#include <chrono>
#include <stdexcept>
#include "animal.h"
#include "functions.h"

void GameplayScreen::loadContent() {
    contentManager.loadContent();

    for (auto element : allElements) {
        if (!element->initialize()) {
            throw std::runtime_error(std::string("Не удалось инициализировать какой-то объект, ") + SDL_GetError());
        }
    }
}

void GameplayScreen::unloadContent() {
    contentManager.unloadContent();
}

void GameplayScreen::handleInput(const SDL_Event &event) {
    player->handleInput(event);
}

void GameplayScreen::update(bool otherScreenHasFocus, bool coveredByOtherScreen) {
    GameScreen::update(otherScreenHasFocus, coveredByOtherScreen);
    if (!otherScreenHasFocus) {
        if (animalTimer.getTicks() > 2000) {
            createAnimal();
            animalTimer.start();
        }

        if (gameTimer.getTicks() >= 20000) {
            exited = true;
        }

        std::string message = "Очки: " + std::to_string(score);
        scoreMessage = TTF_RenderUTF8_Solid(screenManager->getGameFont(), message.c_str(), textColor);

        message = "Время: " + std::to_string(gameTimer.getTicks() / 1000);
        timeMessage = TTF_RenderUTF8_Solid(screenManager->getGameFont(), message.c_str(), textColor);

        score += numberOfCollisionsAnimalsBullets();

        for (auto element : allElements) {
            element->update();
        }

        removeDeadElements();
    }
}

void GameplayScreen::draw() {
    for (auto element : allElements) {
        element->draw();
    }
    applySurface(25, 25, scoreMessage, canvas);
    applySurface(canvas->w - 75, 25, timeMessage, canvas);
    SDL_Flip(canvas);
}

void GameplayScreen::createAnimal() {
    if (currentNumberOfAnimals <= MAXIMUM_NUMBER_OF_ANIMALS) {
        unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::minstd_rand0 generator(seed);
        std::uniform_int_distribution<int> distributionX(100, canvas->w - 100);
        std::uniform_int_distribution<int> distributionY(100, canvas->h - 195);
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

void GameplayScreen::removeDeadElements() {
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

bool GameplayScreen::haveAnimalCollidedWithBullet(std::shared_ptr<Bullet> bullet) {
    for (auto animal : animals) {
        if (animal->isAlive()) {
            if (animal->hasCollided(bullet)) {
                animal->makeDead();
                return true;
            }
        }
    }
    return false;
}

int GameplayScreen::numberOfCollisionsAnimalsBullets() {
    int count {0};
    for (auto bullet : bullets) {
        if (bullet->isAlive()) {
            if (haveAnimalCollidedWithBullet(bullet)) {
                bullet->makeDead();
                count++;
            }
        }
    }
    return count;
}

GameplayScreen::GameplayScreen() {
    canvas = SDL_GetVideoSurface();

    allElements.push_back(std::make_shared<Background>(0, 0, contentManager));

    player = std::make_shared<Player>(canvas ->w / 2 -40,
            canvas->h - 100, contentManager, [this] {
                std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(player->getX() + 42,
                        player->getY(), -3, contentManager);
                bullet->initialize();
                allElements.push_back(bullet);
                bullets.push_back(bullet);
            });
    allElements.push_back(player);

    currentNumberOfAnimals = 0;
    animalTimer.start();

    score = 0;
    textColor = {255, 255, 255};

    gameTimer.start();
}