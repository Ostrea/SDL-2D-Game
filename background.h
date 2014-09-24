#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "staticgraphicalelement.h"

class Background : public StaticGraphicalElement {

public:
    Background(int x, int y);

    ~Background();

    bool initialize();

    void logic();

    void collisionDetection();
};

#endif // BACKGROUND_H