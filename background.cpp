#include "background.h"
#include "functions.h"

Background::Background(int x, int y) : StaticGraphicalElement(x, y) {
}

Background::~Background() {
}

bool Background::initialize() {
    surface = loadImage("/home/ostrea/Programs/Labs_second_term/"
            "Gushin/Coursework_third_try/images/nebula_brown.png");
    return surface != nullptr;
}

void Background::logic() {
}

void Background::collisionDetection() {
}
