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
using namespace std;
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
	// Initialize SDL
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	// Create an SDL Window
	mWindow = SDL_CreateWindow(
		"Game Programming in C++ (Chapter 1)", // Window title
		100,	// Top left x-coordinate of window
		100,	// Top left y-coordinate of window
		1024,	// Width of window
		768,	// Height of window
		0		// Flags (0 for no flags set)
	);

	if (!mWindow)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	//// Create SDL renderer
	mRenderer = SDL_CreateRenderer(
		mWindow, // Window to create renderer for
		-1,		 // Usually -1
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!mRenderer)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}

	mPaddle1Pos.x = 10.0f;//posi��o inicial da raquete eixo x
	mPaddle1Pos.y = 768.0f / 2.0f;//posi��o inicial da raquee eixo y

	mPaddle2Pos.x = 1000.0f;//posi��o inicial da raquete eixo x
	mPaddle2Pos.y = 768.0f / 2.0f;//posi��o inicial da raquee eixo y

	initialBallPos.x = 1024.0f / 2.0f;//posi��o da bola eixo x
	initialBallPos.y = 768.0f / 2.0f;//posi��o da bola eixo y

	initialBallVel.x = -200.0f;//velocidade de movimenta��o da bola no eixo x
	initialBallVel.y = 500.0f;//velocidade de movimenta��o da bola no eixo y

	//Ball balls [maxBalls] = {}; // instancia o array de tamanho fixo para entidades de bola

	/*for (int i = 0; i < maxBalls; i++) {
		balls[i] = new Ball();
	}*/

	entityManager.initialize();

	/*if (!entityManager.balls[0].isInstanced) {
		entityManager.balls[0].populate(initialBallPos.x, initialBallPos.y, initialBallVel.x, initialBallVel.y);
	}*/

	player1HP.populate(250, 50);
	player2HP.populate(775, 50);

	return true;
}

void Game::RunLoop()
{
	while (mIsRunning)
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
			mIsRunning = false;
			break;
		}
	}

	// Get state of keyboard - podemos buscar por alguma tecla espec�fica pressionada no teclado, nesse caso, Escape
	const Uint8* state = SDL_GetKeyboardState(NULL);

	// If escape is pressed, also end loop
	if (state[SDL_SCANCODE_ESCAPE])
	{
		mIsRunning = false;
	}

	// Update paddle direction based on W/S keys - atualize a dire��o da raquete com base na entrada do jogador
	// W -> move a raquete para cima, S -> move a raquete para baixo
	mPaddle1Dir = 0;
	//entityManager.handleInput(state);
	if (state[SDL_SCANCODE_A])
	{
		mPaddle1Dir -= 1;
	}
	if (state[SDL_SCANCODE_D])
	{
		mPaddle1Dir += 1;
	}

}

void Game::UpdateGame()
{
	// Espere que 16ms tenham passado desde o �ltimo frame - limitando os frames
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16))
		;

	// Delta time � a diferen�a em ticks do �ltimo frame
	// (convertido pra segundos) - calcula o delta time para atualiza��o do jogo
	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;

	// "Clamp" (lima/limita) valor m�ximo de delta time
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}

	// atualize a contagem de ticks par ao pr�ximo frame
	mTicksCount = SDL_GetTicks();

	 
	// atualiza a posi��o da raquete 1
	if (mPaddle1Dir != 0)
	{
		mPaddle1Pos.y += mPaddle1Dir * paddleSpeed * deltaTime;
		// verifique que a raquete n�o se move para fora da tela - usamos "thickness", que definimos como a altura dos elementos
		if (mPaddle1Pos.y < (paddleH / 2.0f + thickness))
		{
			mPaddle1Pos.y = paddleH / 2.0f + thickness;
		}
		else if (mPaddle1Pos.y > (768.0f - paddleH / 2.0f - thickness))
		{
			mPaddle1Pos.y = 768.0f - paddleH / 2.0f - thickness;
		}
	}
	

	// atualiza a posi��o da raquete 2
	if (mPaddle2Dir != 0)
	{
		mPaddle2Pos.y += mPaddle2Dir * paddleSpeed * deltaTime;
		// verifique que a raquete n�o se move para fora da tela - usamos "thickness", que definimos como a altura dos elementos
		if (mPaddle2Pos.y < (paddleH / 2.0f + thickness))
		{
			mPaddle2Pos.y = paddleH / 2.0f + thickness;
		}
		else if (mPaddle2Pos.y > (768.0f - paddleH / 2.0f - thickness))
		{
			mPaddle2Pos.y = 768.0f - paddleH / 2.0f - thickness;
		}
	}

	for (int i = 0; i < maxBalls; i++) {
		if (entityManager.balls[i].isInstanced) {
			entityManager.balls[i].update(deltaTime, mPaddle1Pos, mPaddle2Pos);

			if (entityManager.balls[i].touchedPaddle(paddleH)) {
				if (i < (maxBalls - 1) && !entityManager.balls[i + 1].isInstanced) {
					Vector2 newPos = entityManager.balls[i].getPos();
					Vector2 newVel = entityManager.balls[i].getVel();

					entityManager.balls[i + 1].populate(newPos.x, newPos.y, (newVel.x)*1.2f, newVel.y * -1.0f);
				}
			}

			if (entityManager.balls[i].isOutLeft()) {
				//lado = 1;
				//UpdatePoints(lado);
				Reposition();
				//printf("Pontuacao player 1: %d\n", p1Score);
				//printf("Pontuacao player 2: %d\n\n", p2Score);
				bool isRight = false;
				player1HP.update(isRight);
			}

			if (entityManager.balls[i].isOutRight()) {
				//lado = 0;
				//UpdatePoints(lado);
				Reposition();
				//printf("Pontuacao player 1: %d\n", p1Score);
				//printf("Pontuacao player 2: %d\n\n", p2Score);
				bool isRight = true;
				player2HP.update(isRight);
			}
		}
	}


	if (player2HP.isDead())
	{
		printf("\n\n|||   Player 1 venceu!   |||");
		mIsRunning = false;
	}
	else if (player1HP.isDead())
	{
		printf("\n\n|||   Player 2 venceu!   |||");
		mIsRunning = false;
	}

}

void Game::Reposition()
{
	mPaddle1Pos.x = 10.0f;//posi��o inicial da raquete eixo x
	mPaddle1Pos.y = 768.0f / 2.0f;//posi��o inicial da raquee eixo y

	mPaddle2Pos.x = 1000.0f;//posi��o inicial da raquete eixo x
	mPaddle2Pos.y = 768.0f / 2.0f;//posi��o inicial da raquee eixo y

	initialBallPos.x = 1024.0f / 2.0f;//posi��o da bola eixo x
	initialBallPos.y = 768.0f / 2.0f;//posi��o da bola eixo y

	initialBallVel.x = -200.0f;//velocidade de movimenta��o da bola no eixo x
	initialBallVel.y = 500.0f;//velocidade de movimenta��o da bola no eixo y

	for (int i = 0; i < maxBalls; i++) {
		entityManager.balls[i] = Ball();
	}

	if (!entityManager.balls[0].isInstanced) {
		entityManager.balls[0].populate(initialBallPos.x, initialBallPos.y, initialBallVel.x, initialBallVel.y);
	}

}

void Game::UpdatePoints(int lado)
{
	if (lado == 0)
	{
		p1Score++;
	}
	else
	{
		p2Score++;
	}
}

//Desenhando a tela do jogo
void Game::GenerateOutput()
{
	// Setamos a cor de fundo par azul
	SDL_SetRenderDrawColor(
		mRenderer,
		0,		// R
		0,		// G 
		255,	// B
		255		// A
	);

	// limpa o back buffer
	SDL_RenderClear(mRenderer);

	// Desenha as paredes - mudamos a cor de mRenderer para o desenho dos retangulos que formaram as paredes
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);

	// Desenha a parede de cima - desenhando um retangulo no topo da tela, coordenada x e y = 0, 0 representa o topo esquerdo
	//primeiro definimos as coordenadas e tamanhos do triangulo
	SDL_Rect wall{
		0,			// Top left x
		0,			// Top left y
		1024,		// Width
		thickness	// Height
	};
	SDL_RenderFillRect(mRenderer, &wall);//finalmente, desenhamos um retangulo no topo

	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);

	//desenhamos as outras paredes apenas mudando as coordenadas de wall

	// parede de baixo
	wall.y = 768 - thickness;
	SDL_RenderFillRect(mRenderer, &wall);

	SDL_SetRenderDrawColor(mRenderer, 255, 0, 0, 255);

	// parede da direita
	wall.x = 1024 - thickness;
	wall.y = 0;
	wall.w = 1024;
	wall.h = thickness;
	SDL_RenderFillRect(mRenderer, &wall);

	//como as posi��es da raquete e da bola ser�o atualizadas a cada itera��o do game loop, criamos "membros" na classe
	//Game.h para tal

	//mudar a cor da raquete
	SDL_SetRenderDrawColor(mRenderer, 0, 255, 0, 255);

	//desenhando a raquete - usando mPaddlePos que � uma struc de coordenada que foi definida em Game.h
	// 
	SDL_Rect paddle{
		static_cast<int>(mPaddle1Pos.x),//static_cast converte de float para inteiros, pois SDL_Rect trabalha com inteiros
		static_cast<int>(mPaddle1Pos.y - paddleH / 2),
		thickness,
		static_cast<int>(paddleH)
	};
	SDL_RenderFillRect(mRenderer, &paddle);

	SDL_Rect paddle2{
		static_cast<int>(mPaddle2Pos.x),//static_cast converte de float para inteiros, pois SDL_Rect trabalha com inteiros
		static_cast<int>(mPaddle2Pos.y - paddleH / 2),
		thickness,
		static_cast<int>(paddleH)
	};
	SDL_RenderFillRect(mRenderer, &paddle2);
	//desenhando a bola - usando mBallPos que � uma struc de coordenadas definida como membro em Game.h


	for (int i = 0; i < maxBalls; i++) {
		//mudar a cor do renderizador para a bola
		SDL_SetRenderDrawColor(mRenderer, 255, 255, 0, 255);
		// Draw ball
		SDL_Rect ball{
			static_cast<int>(entityManager.balls[i].getPos().x - thickness / 2),
			static_cast<int>(entityManager.balls[i].getPos().y - thickness / 2),
			thickness,
			thickness
		};
		SDL_RenderFillRect(mRenderer, &ball);
	}

	//mudar a cor do renderizador para a hp
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	// Draw hp
	SDL_Rect outlinehp1{
		static_cast<int>(250 - 300 / 2),
		static_cast<int>(50 - 15 / 2),
		300,
		15
	};
	SDL_RenderFillRect(mRenderer, &outlinehp1);

	// Draw hp
	SDL_Rect outlinehp2{
		static_cast<int>(775 - 300 / 2),
		static_cast<int>(50 - 15 / 2),
		300,
		15
	};
	SDL_RenderFillRect(mRenderer, &outlinehp2);

	//mudar a cor do renderizador para a hp
	SDL_SetRenderDrawColor(mRenderer, 255, 0, 0, 255);
	// Draw hp
	SDL_Rect player1hp{
		static_cast<int>(player1HP.getPos().x - player1HP.width / 2),
		static_cast<int>(player1HP.getPos().y - player1HP.height / 2),
		player1HP.width,
		player1HP.height
	};
	SDL_RenderFillRect(mRenderer, &player1hp);

	// Draw hp
	SDL_Rect player2hp{
		static_cast<int>(player2HP.getPos().x - player2HP.width / 2),
		static_cast<int>(player2HP.getPos().y - player2HP.height / 2),
		player2HP.width,
		player2HP.height
	};
	SDL_RenderFillRect(mRenderer, &player2hp);

	SDL_SetRenderDrawColor(mRenderer, 255, 255, 0, 255);


	// Swap front buffer and back buffer
	SDL_RenderPresent(mRenderer);
}

//Para encerrar o jogo
void Game::Shutdown()
{
	SDL_DestroyRenderer(mRenderer);//encerra o renderizador
	SDL_DestroyWindow(mWindow);//encerra a janela aberta
	SDL_Quit();//encerra o jogo
}
