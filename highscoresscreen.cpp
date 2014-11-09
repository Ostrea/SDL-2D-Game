#include "highscoresscreen.h"
#include "functions.h"
#include <fstream>
#include <iostream>

void HighScoresScreen::loadContent() {
//    TODO insert new highscores in the vector using standard method and then delete last element to keep 10 elements
//    for (int i = 0; i < NUMBER_OF_SCORES; ++i) {
//        highScores.push_back(std::pair<std::string, int>("Ostrea", 0));
//    }
//
//    std::ofstream file("/home/ostrea/Programs/Labs_second_term/"
//            "Gushin/Coursework_third_try/coursework_third_try/highscores", std::ios::out | std::ios::binary);

//    std::copy(highScores.begin(), highScores.end(), std::ostreambuf_iterator<char>(file));

//    size_t sz = myVector.size();
//    file.write(reinterpret_cast<char*>(&sz), sizeof(sz));
//    file.write(reinterpret_cast<char*>(&myVector[0]), sz * sizeof(myVector[0]));

//    int numberOfElements = 0;
//    file.write(reinterpret_cast<char*>(&numberOfElements), sizeof(numberOfElements));
//    for (auto item : highScores) {
//        unsigned long size = item.first.size() + 1;
//        file.write(reinterpret_cast<char*>(&size), sizeof(size));
//        auto string = item.first.c_str();
//        file.write(&string[0], sizeof(char) * size);
//        int score = item.second;
//        file.write(reinterpret_cast<char*>(&score), sizeof(score));
//    }
//    file.close();

    std::ifstream file2("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/coursework_third_try/highscores", std::ios::in | std::ios::binary);
    int numberOfElements;
    file2.read(reinterpret_cast<char*>(&numberOfElements), sizeof(numberOfElements));
    for (int i = 0; i < numberOfElements; ++i) {
        unsigned long size;
        file2.read(reinterpret_cast<char*>(&size), sizeof(size));
        char string[size];
        file2.read(&string[0], sizeof(char) * size);
        int score;
        file2.read(reinterpret_cast<char*>(&score), sizeof(score));
        std::cout << "size = " << size << " score = " << score << " name = " << string << std::endl;
        highScores.push_back(std::pair<std::string, int>(string, score));
    }
    file2.close();

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
    background = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/highscores_background.jpg");
}
