#include "PlayState.h"

PlayState::PlayState() {
};

void PlayState::initialize(EntityManager& entityManager)
{
	entityManager.initialize();
}

bool PlayState::update(EntityManager& entityManager, float deltaTime) {
	// TODO: pass deltaTime and call entityManager.update(deltaTime);
	return entityManager.update(deltaTime);
};