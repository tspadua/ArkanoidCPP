#pragma once

#include "../Utils/MathUtils.h"
#include "Entity.h"
#include "Paddle.h"
#define BALL_H

class Ball : Entity {
    public:
        Vector2 pos;
        Vector2 vel;
        float height = 15.0f;
        float width = 15.0f;
        bool isInstanced = false;
        float diff;
        float diff2;
        int thickness = 15;

        Ball();

        void populate(float posX, float posY, float velX, float velY);
        void update(float deltaTime, Paddle paddle);
        bool touchedPaddle(Paddle paddle);
        void updateDirection();

        bool isOutLeft();
        bool isOutRight();
        //bool isInstanced();
};