#ifndef BULLET_H
#define BULLET_H

#include "staticgraphicalelement.h"
#include "movablegraphicalelement.h"

class Bullet : public StaticGraphicalElement, public MovableGraphicalElement {

public:
    Bullet(int x, int y, double velocityY);
    ~Bullet();
    void handleEvents(SDL_Event &event);
    void logic();
    bool initialize();
    void collisionDetection();

private:
    bool alive;
};

#endif // BULLET_H