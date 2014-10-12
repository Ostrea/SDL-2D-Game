#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "drawableelement.h"

class Background : public DrawableElement {

public:
    Background(int x, int y);

    ~Background();

    virtual bool initialize() override;

    virtual void update() override;

};

#endif // BACKGROUND_H