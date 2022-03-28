d#include "PlayState.h"

PlayState::PlayState() {
};

void PlayState::initialize(EntityManager& entityManager)
{
	entityManager.initialize();
};

void PlayState::update(EntityManager& entityManager, float deltaTime)
{
	// TODO: pass deltaTime and call entityManager.update(deltaTime);
	entityManager.update(deltaTime);
};

GameState* PlayState::handleInput(EntityManager& entityManager, const Uint8* keystate){
	entityManager.paddle.handleInput(keystate);

	if (keystate){
        return &GameState::Menu;
    }

	return NULL;
}

void PlayState::exit(EntityManager& entityManager) 
{
	entityManager = EntityManager();
};