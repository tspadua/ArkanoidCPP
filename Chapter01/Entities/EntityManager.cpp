
#include "EntityManager.h"

EntityManager::EntityManager() {
};

void EntityManager::initialize() {


	float initialBallPosX = 1024.0f / 2.0f;//posi��o da bola eixo x
	float initialBallPosY = 768.0f / 2.0f;//posi��o da bola eixo y

	float initialBallVelX = -200.0f;//velocidade de movimenta��o da bola no eixo x
	float initialBallVelY = 500.0f;//velocidade de movimenta��o da bola no eixo y

    balls[0].populate(initialBallPosX, initialBallPosY, initialBallVelX, initialBallVelY * -1);
    
	paddle.populate(1024.0f / 2 - (paddle.width / 2), 768.0f - 60.f, 300.0f, SDL_SCANCODE_A, SDL_SCANCODE_D);

	float posX = 15;
	float posY = 50;
	int resistance = 1;
	for (int i = 0; i < maxTiles; i++) {
		posX += (tiles[i].width + 20);

		//posY += 15;

		tiles[i].populate(posX, posY, resistance);		resistance++;
	}
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

	for (int i = 0; i < maxBalls; i++) {
		if (balls[i].isInstanced) {
			balls[i].update(deltaTime, paddle);

			if (balls[i].touchedPaddle(paddle)) {
				if (i < (maxBalls - 1) && !balls[i + 1].isInstanced) {
					Vector2 newPos = balls[i].pos;
					Vector2 newVel = balls[i].vel;

					//balls[i + 1].populate(newPos.x, newPos.y, (newVel.x) * 1.2f, newVel.y * -1.0f);
				}
			}

			for (int j = 0; j < maxTiles; j++) {
				if (tiles[j].resistance > 0) {
					bool touched = balls[i].touchedTile(tiles[j]);
					if (tiles[j].resistance == 0 && touched) {
						// update score here
					}

				}
			}
			

			if (balls[i].isOutLeft()) {
				//lado = 1;
				//UpdatePoints(lado);
				//Reposition();
				//printf("Pontuacao player 1: %d\n", p1Score);
				//printf("Pontuacao player 2: %d\n\n", p2Score);
				bool isRight = false;
				//player1HP.update(isRight);
			}

			if (balls[i].isOutRight()) {
				//lado = 0;
				//UpdatePoints(lado);
				//Reposition();
				//printf("Pontuacao player 1: %d\n", p1Score);
				//printf("Pontuacao player 2: %d\n\n", p2Score);
				bool isRight = true;
				//player2HP.update(isRight);
			}
		}
	}
};

void EntityManager::handleInput(const Uint8* state) {
	paddle.handleInput(state);
};

