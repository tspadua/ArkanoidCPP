// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Game.h"
#include <stdlib.h>
#include <iostream>

const int thickness = 15;//sera usado para setar a altura de alguns objetos
const float paddleH = 400.0f;//tamanho da raquete

Game::Game()
	:mWindow(nullptr)//para criar uma janela
	, mRenderer(nullptr)//para fins de renderiza��o na tela
	, mTicksCount(0)//para guardar o tempo decorrido no jogo
	, mIsRunning(true)//verificar se o jogo ainda deve continuar sendo executado
	, mPaddle1Dir(0)//direcao da bolinha
{

}

bool Game::Initialize()
{
	if (!graphicUtils.initializeWindow()) {
		return false;
	}

	//Set state to play state
	stateManager.setState(State.Play);


    //TODO: initialize game's entities here
	//EntityManager();

	return true;
}

void Game::RunLoop()
{
	while (stateManager.state == State.Play)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::ProcessInput()
{
	SDL_Event event;//evento, inputs do jogador s�o armazenados aqui
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			// If we get an SDL_QUIT event, end loop
		case SDL_QUIT:
			stateManager.setState(State.Menu);
			break;
		}
	}

	// Get state of keyboard - podemos buscar por alguma tecla espec�fica pressionada no teclado, nesse caso, Escape
	const Uint8* state = SDL_GetKeyboardState(NULL);
	// If escape is pressed, also end loop
	if (state[SDL_SCANCODE_ESCAPE])
	{
		stateManager.setState(State.Menu);
	}


	//TODO: paddle inputs goes here
}

void Game::UpdateGame()
{
	graphicUtils.updateFrame();

	//TODO:  update paddle position here


	//TODO: player's death logic
	// if (player.isDead())
	// {
	// 	printf("\n\n|||   Perdeste!   |||");
	// 	stateManager.setState(State.Menu);
	// }
}

void Game::Reposition()
{
	//TODO: reposition of the objects in case of restart
}

void Game::UpdatePoints(int lado)
{
	//TODO: update points
}

//Desenhando a tela do jogo
void Game::GenerateOutput()
{
	graphicUtils.drawObjects();
}

//Para encerrar o jogo
void Game::Shutdown()
{
	graphicUtils.shutdown();
	SDL_Quit();//encerra o jogo
}
