#pragma once

#include "GameState.h"

#define PLAYSTATE_H
class PlayState : public GameState {
public:
	PlayState();
	void update(EntityManager& entityManager, float deltaTime);
	void initialize(EntityManager& entityManager);
	void exit(EntityManager& entityManager);
	GameState* handleInput(EntityManager& entityManager, const Uint8* keystate);
};