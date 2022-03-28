#include "GameState.h"
#include "PlayState.h"
#include "MenuState.h"

PlayState GameState::Play;

MenuState GameState::Menu;

void GameState::initialize(EntityManager& entityManager)
{

}

void GameState::update(EntityManager& entityManager, float deltaTime)
{

}

void GameState::exit(EntityManager& entityManager)
{

}

GameState* GameState::handleInput(EntityManager& entityManager, const Uint8* keystate)
{
    return NULL;
}