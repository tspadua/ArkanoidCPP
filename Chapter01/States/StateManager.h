#pragma once

#include "GameState.h"
#include "PlayState.h"
#include "MenuState.h"
#include "../Entities/EntityManager.h"

#define STATEMANAGER_H
class StateManager {
public:
    //State state;

    StateManager();

    //enum state { Play, Menu }

    GameState* state;

    EntityManager entityManager = EntityManager();

    //void setState(GameState* state_); // delegate to the state object
};