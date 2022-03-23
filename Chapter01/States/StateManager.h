#pragma once

#include "GameState.h"
#include "PlayState.h"
#include "MenuState.h"

#define STATEMANAGER_H
class StateManager {
public:
    //State state;

    StateManager();

    //enum state { Play, Menu }

    GameState* state;

    //void setState(GameState* state_); // delegate to the state object
};