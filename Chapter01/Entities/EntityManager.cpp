
#include "EntityManager.h"

EntityManager::EntityManager() {
};

void EntityManager::initialize() {


	float initialBallPosX = 1024.0f / 2.0f;//posi��o da bola eixo x
	float initialBallPosY = 768.0f / 2.0f;//posi��o da bola eixo y

	float initialBallVelX = -200.0f;//velocidade de movimenta��o da bola no eixo x
	float initialBallVelY = 500.0f;//velocidade de movimenta��o da bola no eixo y

    balls[0].populate(initialBallPosX, initialBallPosY, initialBallVelX, initialBallVelY);
    
	paddle.populate(1024.0f / 2 - (paddle.width / 2), 768.0f - 60.f, 300.0f, SDL_SCANCODE_A, SDL_SCANCODE_D);
};


void EntityManager::update(float deltaTime) {
	if (paddle.direction != 0)
	{
		paddle.pos.x += paddle.direction * paddle.speed * deltaTime;
		// verifique que a raquete n�o se move para fora da tela - usamos "thickness", que definimos como a altura dos elementos
		if (paddle.pos.x <= 5)
		{
			paddle.pos.x = 5;
		}
		else if (paddle.pos.x >= (1024 - paddle.width - 5))
		{
			paddle.pos.x = (1024 - paddle.width - 5);
		}
	}
};

void EntityManager::handleInput(const Uint8* state) {
	paddle.handleInput(state);
};

