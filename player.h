#ifndef PLAYER_H
#define PLAYER_H

#include "controllableelement.h"
#include "drawableelement.h"
#include "bullet.h"
#include <list>
#include <memory>

class Player : public ControllableElement, public DrawableElement {

public:
    Player(int x, int y, const int width, std::list<std::shared_ptr<DrawableElement>> &allElements,
            std::list<std::shared_ptr<Bullet>> &bullets);

    virtual void handleEvents(SDL_Event const &event) override;

    virtual void update() override;

    virtual bool initialize() override;

    void shoot();

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

private:
    const double ACCELERATION = 3;
    const int SCREEN_WIDTH;
    std::list<std::shared_ptr<DrawableElement>> &allElements;
    std::list<std::shared_ptr<Bullet>> &bullets;
};

#endif // PLAYER_H