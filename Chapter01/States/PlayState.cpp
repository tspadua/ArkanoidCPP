#include "PlayState.h"

PlayState::PlayState() {
};

void PlayState::initialize(EntityManager& entityManager)
{
	entityManager.initialize();
}

void PlayState::update(EntityManager& entityManager, float deltaTime) {
	// TODO: pass deltaTime and call entityManager.update(deltaTime);
	entityManager.update(deltaTime);
};