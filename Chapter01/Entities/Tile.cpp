#include "Tile.h"

void Tile::populate(float posX, float posY, int resistance_) {
    pos.x = posX;
    pos.y = posY;

    resistance = resistance_;
};