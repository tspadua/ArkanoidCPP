#pragma once

#include "../Utils/MathUtils.h"
#include "Entity.h"

class Tile : Entity {
public:
    int resistance = 1;
    Vector2 pos;
    float height = 15.0f;
    float width = 80.0f;

    void populate(float posX, float posY, int resistance);
};