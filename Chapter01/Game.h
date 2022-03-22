// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "States/StateManager.h"
#include "SDL/SDL.h"
#include "Utils/GraphicUtils.h"
#include "Entities/Ball.h"
#include "Entities/PlayerStatus.h"

// Game class
class Game
{
	public:
		Game();
		// Initialize the game
		bool Initialize();
		// Runs the game loop until the game is over
		void RunLoop();
		// Shutdown the game
		void Shutdown();
	private:
		// Helper functions for the game loop
		void ProcessInput();
		void UpdateGame();
		void GenerateOutput();
		void Reposition();
		void UpdatePoints(int lado);

		//TODO: instance game's entities here
		GraphicUtils graphicUtils;

		StateManager stateManager;


};
