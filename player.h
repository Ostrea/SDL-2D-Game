#ifndef PLAYER_H
#define PLAYER_H

#include "movablegraphicalelement.h"
#include "staticgraphicalelement.h"
#include "bullet.h"
#include <list>
#include <memory>

class Player : public MovableGraphicalElement, public StaticGraphicalElement {

public:
    Player(int x, int y, const int width,
            std::list<std::shared_ptr<StaticGraphicalElement>> &allElements);
    void handleEvents(SDL_Event &event);
    void logic();
    bool initialize();
    void shoot();
    void collisionDetection();
    ~Player();

private:
    const double ACCELERATION = 3;
    const int SCREEN_WIDTH;
    std::list<std::shared_ptr<StaticGraphicalElement>> &allElements;
};

#endif // PLAYER_H