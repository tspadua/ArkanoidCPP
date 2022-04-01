#pragma once

#include "GameState.h"

#define PLAYSTATE_H
class PlayState : public GameState {
public:
	PlayState();
	float test;
	bool update(EntityManager& entityManager, float deltaTime);
	void initialize(EntityManager& entityManager);
};