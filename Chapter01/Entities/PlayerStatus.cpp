#include "PlayerStatus.h"

PlayerStatus::PlayerStatus() { };

void PlayerStatus::populate(float posX, float posY) {
	pos.x = posX;
	pos.y = posY;
}

void PlayerStatus::update(bool isRight) {
	float updateValue = 30.0f;
	width -= updateValue;
	if (isRight) {
		pos.x = pos.x + (updateValue / 2);
	}
	else {
		pos.x = pos.x - (updateValue / 2);
	}
}

Vector2 PlayerStatus::getPos() {
	return pos;
};

//int getThickness() {
//	return thickness;
//}

bool PlayerStatus::isDead() {
	return width < 10.0f;
}