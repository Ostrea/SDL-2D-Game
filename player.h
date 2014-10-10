#ifndef PLAYER_H
#define PLAYER_H

#include "movablegraphicalelement.h"
#include "staticgraphicalelement.h"
#include "bullet.h"
#include <list>
#include <memory>

class Player : public MovableGraphicalElement, public StaticGraphicalElement {

public:
    Player(int x, int y, const int width, std::list<std::shared_ptr<StaticGraphicalElement>> &allElements,
            std::list<std::shared_ptr<Bullet>> &bullets);

    virtual void handleEvents(SDL_Event &event) override;

    virtual void logic() override;

    virtual bool initialize() override;

    void shoot();

private:
    const double ACCELERATION = 3;
    const int SCREEN_WIDTH;
    std::list<std::shared_ptr<StaticGraphicalElement>> &allElements;
    std::list<std::shared_ptr<Bullet>> &bullets;
};

#endif // PLAYER_H