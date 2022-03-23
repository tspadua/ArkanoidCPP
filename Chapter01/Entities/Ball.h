#pragma once

#include "../Utils/MathUtils.h"
#include "Entity.h"
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
        void update(float deltaTime, Vector2 paddle1, Vector2 paddle2);
        bool touchedPaddle(float paddleH);
        void updateYDirection();

        bool isOutLeft();
        bool isOutRight();
        //bool isInstanced();
};