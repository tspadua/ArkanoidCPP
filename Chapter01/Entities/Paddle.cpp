#include "Paddle.h"

Paddle::Paddle() {};

void Paddle::populate(float posX, float posY, float vel, SDL_Scancode leftInput, SDL_Scancode rigthInput) {
    pos.x = posX;
    pos.y = posY;
    speed = vel;
    leftInputKey = leftInput;
    rightInputKey = rigthInput;
};

/*
void Paddle::update(float deltaTime) {
    // handle gameover, reset time, etc...
};
*/

void Paddle::handleInput(const Uint8* state) {
    direction = 0;
    if (state[leftInputKey])
    {
        direction -= 1;
    }
    if (state[rightInputKey])
    {
        direction += 1;
    }
};