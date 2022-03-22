
#include "EntityManager.h"

EntityManager::EntityManager() {};

void EntityManager::initialize() {

	Vector2 initialBallVel;
	Vector2 initialBallPos;

	initialBallPos.x = 1024.0f / 2.0f;//posi��o da bola eixo x
	initialBallPos.y = 768.0f / 2.0f;//posi��o da bola eixo y

	initialBallVel.x = -200.0f;//velocidade de movimenta��o da bola no eixo x
	initialBallVel.y = 500.0f;//velocidade de movimenta��o da bola no eixo y

    if (!balls[0].isInstanced) {
        balls[0].populate(initialBallPos.x, initialBallPos.y, initialBallVel.x, initialBallVel.y);
    }

	paddle.populate(10.0f, 768.0f / 2.0f, 1.0f);
};


void EntityManager::update(float deltatime) {
	/*
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
	*/
};

void EntityManager::handleInput(Uint8* state) {
	paddle.handleInput(state);
}

