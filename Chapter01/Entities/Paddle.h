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
    float speed;
    float height = 15.0f;
    float width = 2080.0f;
    SDL_Scancode leftInputKey;
    SDL_Scancode rightInputKey;

    Uint8* moveToRightKey;
    Uint8* moveToLeftKey;

    Paddle();

    void populate(float posX, float posY, float vel, SDL_Scancode leftInput, SDL_Scancode rigthInput);
    void update(){};
    void handleInput(const Uint8* state);
    //void handleCollision();
};