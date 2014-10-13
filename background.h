#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "drawableelement.h"
#include "contentmanager.h"

class Background : public DrawableElement {

public:
    Background(int x, int y, ContentManager const &contentManager);

    virtual bool initialize() override;

    virtual void update() override;

private:
    ContentManager const &contentManager;
};

#endif // BACKGROUND_H