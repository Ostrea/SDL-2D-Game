#include "contentmanager.h"
#include "functions.h"

void ContentManager::loadContent() {
    background = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/nebula_brown.png");
    animal = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/racoon.png");
    player = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/ship_without_thrusters.png");
    bullet = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/shot1.png");
}

void ContentManager::unloadContent() {
    SDL_FreeSurface(background);
    SDL_FreeSurface(animal);
    SDL_FreeSurface(player);
    SDL_FreeSurface(bullet);
}
