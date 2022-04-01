#pragma once

//#include "../Entities/EntityManager.h"

//#include "../Entities/EntityManager.h"

// forward declarations of derived gamestates
class PlayState;
class MenuState;
#include "../Entities/EntityManager.h"

#define GAMESTATE_H

class GameState {
public:
    static PlayState Play;
    static MenuState Menu;
    virtual ~GameState() {}; // destructor
    virtual bool update(EntityManager& entityManager, float deltaTime);
    virtual void initialize(EntityManager& entityManager);
    virtual void exit(EntityManager& entityManager);
    float test;
};