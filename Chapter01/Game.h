// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "SDL/SDL.h"
#include "Utils.h"
#include "Entities/Ball.h"
#include "Entities/PlayerStatus.h"
#include "Entities/EntityManager.h"

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

		// Window created by SDL
		SDL_Window* mWindow;
		// Renderer for 2D drawing
		SDL_Renderer* mRenderer;
		// Number of ticks since start of game
		Uint32 mTicksCount;
		// Game should continue to run
		bool mIsRunning;

		// Pong specific
		// Direction of paddle 1
		int mPaddle1Dir;
		// Direction of paddle 2
		int mPaddle2Dir;
		// Position of paddle 1
		Vector2 mPaddle1Pos;
		// Position of paddle 2
		Vector2 mPaddle2Pos;
		// Position of ball
		Vector2 initialBallPos;
		// Velocity of ball
		Vector2 initialBallVel;

		float paddleSpeed = 500.0f;

		EntityManager entityManager = EntityManager();

		static const int maxBalls = 10;
		//Ball balls [maxBalls] = {};
		
		//Ball balls[10] = {};

		PlayerStatus player1HP;
		PlayerStatus player2HP;

		// Player Scores
		int p1Score = 0;
		int p2Score = 0;
		int lado;
};
