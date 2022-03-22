#include "Ball.h"
#include "Entity.h"
#include "Paddle.h"
#include <vector>
#include <stdint.h>

class EntityManager {
public:
    std::vector<Entity> entities;
    //std::vector<Tile> tiles;
    Paddle paddle;
    Ball balls[10] = {};
    //static Ball ball;

    EntityManager();

    void initialize();

    void update(float deltaTime);

    void draw();

    void handleCollisions();

    void handleInput(Uint8* state);
};