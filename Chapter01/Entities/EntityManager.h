#pragma once

#include "SDL/SDL.h"
#include "Ball.h"
#include "Tile.h"
#include "Paddle.h"
#include <stdint.h>

#define ENTITYMANAGER_H

const int maxBalls = 10;
const int maxTiles = 18;
const int numRows = 2;
class EntityManager {
public:
    //std::vector<Entity> entities;
    Paddle paddle;
    Tile tiles[maxTiles] = {};
    Ball balls[maxBalls] = {};

    EntityManager();

    void initialize();

    void update(float deltaTime);

    //void draw();

    // void handleCollisions();

    void handleInput(const Uint8* state);
};