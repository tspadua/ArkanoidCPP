#pragma once

#include "../Utils.h"
#define PLAYERSTATUS_H

class PlayerStatus {
public:
    Vector2 pos;
    float height = 15.0f;
    float width = 300.0f;
    int thickness = 300;

    PlayerStatus();

    void populate(float posX, float posY);
    void update(bool isRight);
    Vector2 getPos();
    //int getThickness();

    bool isDead();
};