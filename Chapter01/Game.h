// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "States/StateManager.h"
//#include "Entities/EntityManager.h"
#include "Utils/GraphicUtils.h"
#include "SDL/SDL.h"

// Game class
#define GAME_h
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

		// Helper functions for the game loop
		void ProcessInput();
		void UpdateGame();
		void GenerateOutput();
		void Reposition();
		void UpdatePoints(int lado);

		bool isRunning;


		GraphicUtils graphicUtils = GraphicUtils();
		
		StateManager stateManager = StateManager();

		//EntityManager entityManager = EntityManager();
};

