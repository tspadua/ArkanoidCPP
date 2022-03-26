#pragma once

#include "SDL/SDL.h"
#include "Ball.h"
#include "Paddle.h"
#include <vector>
#include <stdint.h>

#define ENTITYMANAGER_H

const int  maxBalls = 10;

class EntityManager {
public:
    //std::vector<Entity> entities;
    //std::vector<Tile> tiles;
    Paddle paddle;
    Ball balls[maxBalls] = {};

    EntityManager();

    void initialize();

    void update(float deltaTime);

    //void draw();

    // void handleCollisions();

    void handleInput(const Uint8* state);
};