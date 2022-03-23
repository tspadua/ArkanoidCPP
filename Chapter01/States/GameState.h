#pragma once

// forward declarations of derived gamestates
class PlayState;
class MenuState;

#define GAMESTATE_H
class GameState {
public:
    static PlayState Play;
    static MenuState Menu;
    virtual ~GameState() {}; // destructor
    virtual void update() {};
};