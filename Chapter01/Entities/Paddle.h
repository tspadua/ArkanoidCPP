#pragma once

#include "SDL/SDL.h"
#include "../Utils/MathUtils.h"
#include "Entity.h"
#include <stdint.h>

#define PADDLE_H

class Paddle : Entity {
public:
    Vector2 pos;
    Vector2 vel;
    int direction = 0;
    float speed = 0;
    float height = 40.0f;
    float width = 15.0f;

    Uint8* moveToRightKey;
    Uint8* moveToLeftKey;

    Paddle();

    void populate(float posX, float posY, float vel);
    void update(){};
    void handleInput(Uint8* state);
    //void handleCollision();
};