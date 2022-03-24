#pragma once

#include "GameState.h"

#define PLAYSTATE_H
class PlayState : public GameState {
public:
	PlayState();
	float test;
	void update(EntityManager& entityManager);
	void initialize(EntityManager& entityManager);
};