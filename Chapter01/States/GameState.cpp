#include "GameState.h"
#include "PlayState.h"
#include "MenuState.h"

PlayState GameState::Play;

MenuState GameState::Menu;

void GameState::initialize(EntityManager& entityManager)
{

}

bool GameState::update(EntityManager& entityManager, float deltaTime)
{
	return true;
}

void GameState::exit(EntityManager& entityManager)
{

}