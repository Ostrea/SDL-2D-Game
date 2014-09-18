#include "background.h"
#include "functions.h"

Background::Background(int x, int y) {
    this->x = x;
    this->y = y;
}

Background::~Background() {
}

void Background::initialize() {
    surface = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/nebula_brown.png");
}
