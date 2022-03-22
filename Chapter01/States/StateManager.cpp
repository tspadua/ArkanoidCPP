#include "StateManager.h"
#define STATEMANAGER_H

StateManager::StateManager();

void StateManager::setState(State _state) {
    state = _state;
}