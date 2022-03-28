#pragma once

#include "GameState.h"

#define MENUSTATE_H
class MenuState : public GameState {
public:
	MenuState();
	void update(EntityManager& entityManager, float deltaTime);
	void initialize(EntityManager& entityManager);
	void exit(EntityManager& entityManager);
	GameState* handleInput(EntityManager& entityManager, const Uint8* keystate);
};