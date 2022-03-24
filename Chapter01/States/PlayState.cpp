#include "PlayState.h"

PlayState::PlayState() {
};

void PlayState::initialize(EntityManager& entityManager)
{
	entityManager.initialize();
}

void PlayState::update(EntityManager& entityManager) {
	// TODO: pass deltaTime and call entityManager.update(deltaTime);
};