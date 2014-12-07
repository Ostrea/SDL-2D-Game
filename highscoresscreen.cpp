#include "highscoresscreen.h"
#include "functions.h"
#include <fstream>
#include <iostream>

void HighScoresScreen::loadContent() {
    background = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/highscores_background.png");

    readHighScores();

    if (overwrite) {
        updateHighScores();
    }

    TTF_Font *gameFont = screenManager->getGameFont();
    for (auto score : highScores) {
        std::vector<Uint16> message(std::begin(score.first), std::end(score.first) - 1);
        message.push_back(':');
        message.push_back('\0');

        highScoresNameSurfaces.push_back(TTF_RenderUNICODE_Solid(gameFont,
                message.data(), textColor));
        highScoresPointsSurfaces.push_back(TTF_RenderUTF8_Solid(gameFont,
                std::to_string(score.second).c_str(), textColor));
    }
    button = TTF_RenderUTF8_Solid(screenManager->getMenuFont(), "Ок", {0xFF, 0x99, 0x33});
}

void HighScoresScreen::unloadContent() {
    for (auto surface : highScoresNameSurfaces) {
        SDL_FreeSurface(surface);
    }
    for (auto surface : highScoresPointsSurfaces) {
        SDL_FreeSurface(surface);
    }
    SDL_FreeSurface(background);
    SDL_FreeSurface(button);
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

    x += 170;
    y += 120;
    for (int i = 0; i < highScores.size(); ++i) {
        applySurface(x, y, highScoresNameSurfaces.at(i), canvas);
        applySurface(x + 60, y, highScoresPointsSurfaces.at(i), canvas);
        y += 40;
    }
    applySurface(700, 550, button, canvas);
}

HighScoresScreen::HighScoresScreen() {
    popup = true;
    currentScores = 0;
    overwrite = false;
}

HighScoresScreen::HighScoresScreen(int currentScores) {
    this->currentScores = static_cast<Uint16>(currentScores);
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
            Uint16 string[size];
            file.read(reinterpret_cast<char*>(string), sizeof(Uint16) * size);
            Uint16 score;
            file.read(reinterpret_cast<char*>(&score), sizeof(score));

            highScores.push_back(std::pair<std::vector<Uint16>, Uint16>(std::vector<Uint16>
                    (string, string + size), score));
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
        unsigned long size = item.first.size();
        file.write(reinterpret_cast<char*>(&size), sizeof(size));
        auto string = item.first.data();
        file.write(reinterpret_cast<char*>(string), sizeof(Uint16) * size);
        Uint16 score = item.second;
        file.write(reinterpret_cast<char*>(&score), sizeof(score));
    }
}

void HighScoresScreen::updateHighScores() {
    if (highScores.empty()) {
        highScores.push_back(std::pair<std::vector<Uint16>, Uint16>(screenManager->getName(), currentScores));
    } else {
        auto currentPosition = highScores.begin();
        while (currentPosition->second > currentScores && currentPosition != highScores.end()) {
            currentPosition++;
        }
        highScores.insert(currentPosition, std::pair<std::vector<Uint16>, Uint16>
                (screenManager->getName(), currentScores));

        if (highScores.size() > NUMBER_OF_SCORES) {
            highScores.pop_back();
        }
    }
}
