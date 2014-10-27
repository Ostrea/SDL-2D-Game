#ifndef PLAYER_H
#define PLAYER_H

#include "controllableelement.h"
#include "drawableelement.h"
#include "bullet.h"
#include <list>
#include <memory>

class Player : public ControllableElement, public DrawableElement, public MovableElement {

public:
    Player(int x, int y, ContentManager const &contentManager, std::function<void(void)> createBullet);

    virtual void handleInput(SDL_Event const &event) override;

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
    ContentManager const &contentManager;
    std::function<void(void)> createBullet;
};

#endif // PLAYER_H