#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "staticgraphicalelement.h"

class Background : public StaticGraphicalElement {

public:
    Background(int x, int y);
    ~Background();
    void initialize();
};

#endif // BACKGROUND_H