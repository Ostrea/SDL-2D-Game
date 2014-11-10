#include "highscoresscreen.h"
#include "functions.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

void HighScoresScreen::loadContent() {
    background = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/highscores_background.jpg");

//    TODO insert new highscores in the vector using standard method and then delete last element to keep 10 elements
//    for (int i = 0; i < NUMBER_OF_SCORES; ++i) {
//        highScores.push_back(std::pair<std::string, int>("Ostrea", 0));
//    }
//

    readHighScores();

    if (overwrite) {
        updateHighScores();
    }

    for (auto score : highScores) {
        std::string message = score.first + " : " + std::to_string(score.second);
        highScoresSurfaces.push_back(TTF_RenderUTF8_Solid(screenManager->getGameFont(),
                message.c_str(), textColor));
    }
}

void HighScoresScreen::unloadContent() {
    for (auto surface : highScoresSurfaces) {
        SDL_FreeSurface(surface);
    }
    SDL_FreeSurface(background);

    if (overwrite) {
        writeHighScores();
    }
}

void HighScoresScreen::handleInput(const SDL_Event &event) {
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
        exited = true;
    }
}

void HighScoresScreen::draw() {
    SDL_Surface *canvas = SDL_GetVideoSurface();

    int x = canvas->w / 2 - 200;
    int y = 0;
    SDL_Rect rect = {0, 0, 400, 600};
    applySurface(x, y, background, canvas, &rect);

    x += 80;
    y += 20;
    for (auto scoresSurface : highScoresSurfaces) {
        applySurface(x, y, scoresSurface, canvas);
        y += 50;
    }
}

HighScoresScreen::HighScoresScreen() {
    popup = true;
    currentScores = 0;
    overwrite = false;
}

HighScoresScreen::HighScoresScreen(int currentScores) :
        currentScores(currentScores) {
    popup = true;
    overwrite = true;
}

void HighScoresScreen::readHighScores() {
    std::ifstream file("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/coursework_third_try/highscores", std::ios::in | std::ios::binary);
    if (file.fail()) {
        throw std::runtime_error("Не удалось открыть файл");
    }

    if (file.peek() != std::ifstream::traits_type::eof()) {
        unsigned long numberOfElements;
        file.read(reinterpret_cast<char*>(&numberOfElements), sizeof(numberOfElements));
        for (int i = 0; i < numberOfElements; ++i) {
            unsigned long size;
            file.read(reinterpret_cast<char*>(&size), sizeof(size));
            char string[size];
            file.read(&string[0], sizeof(char) * size);
            int score;
            file.read(reinterpret_cast<char*>(&score), sizeof(score));

//            TODO delete after testing
            std::cout << "size = " << size << " score = " << score << " name = " << string << std::endl;

            highScores.push_back(std::pair<std::string, int>(string, score));
        }
    }
}

void HighScoresScreen::writeHighScores() {
    std::ofstream file("/home/ostrea/Programs/Labs_second_term/"
        "Gushin/Coursework_third_try/coursework_third_try/highscores", std::ios::out | std::ios::binary);
    if (file.fail()) {
        throw std::runtime_error("Не удалось открыть файл");
    }

    unsigned long numberOfElements = highScores.size();
    file.write(reinterpret_cast<char*>(&numberOfElements), sizeof(numberOfElements));
    for (auto item : highScores) {
        unsigned long size = item.first.size() + 1;
        file.write(reinterpret_cast<char*>(&size), sizeof(size));
        auto string = item.first.c_str();
        file.write(&string[0], sizeof(char) * size);
        int score = item.second;
        file.write(reinterpret_cast<char*>(&score), sizeof(score));
    }
}

void HighScoresScreen::updateHighScores() {
    if (highScores.empty()) {
        highScores.push_back(std::pair<std::string, int>(screenManager->getName(), currentScores));
    }
}
