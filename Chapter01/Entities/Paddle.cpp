#include "Paddle.h"

Paddle::Paddle() {};

void Paddle::populate(float posX, float posY, float vel) {
    pos.x = posX;
    pos.y = posY;
    speed = vel;
};

/*
void Paddle::update(float deltaTime) {
    // handle gameover, reset time, etc...
};
*/

void Paddle::handleInput(Uint8* state) {
    direction = 0;

    if (state[SDL_SCANCODE_A])
    {
        direction -= 1;
    }
    if (state[SDL_SCANCODE_D])
    {
        direction += 1;
    }
};