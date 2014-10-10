#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "staticgraphicalelement.h"

class Background : public StaticGraphicalElement {

public:
    Background(int x, int y);

    ~Background();

    virtual bool initialize() override;

    virtual void logic() override;

};

#endif // BACKGROUND_H