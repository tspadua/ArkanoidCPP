#pragma once

#include "GameState.h"

#define PLAYSTATE_H
class PlayState : public GameState {
public:
	PlayState();
	virtual void update();
};