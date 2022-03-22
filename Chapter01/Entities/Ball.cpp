
#include "Ball.h"

Ball::Ball() {};

void Ball::populate(float posX, float posY, float velX, float velY) {
    pos.x = posX;
    pos.y = posY;
    vel.x = velX;
    vel.y = velY;

    isInstanced = true;
};

void Ball::update(float deltaTime, Vector2 paddle) {
    // atualiza a posi��o da bola com base na sua velocidade
    pos.x += vel.x * deltaTime;
    pos.y += vel.y * deltaTime;

    // atualiza a posi��o da bola se ela colidiu com a raquete
    diff = paddle.x - pos.x;
    //pegue o valor absoluto de diferen�a entre o eixo y da bolinha e da raquete
    //isso � necess�rio para os casos em que no pr�ximo frame a bolinha ainda n�o esteja t�o distante da raquete
    //verifica se a bola est� na area da raquete e na mesma posi��o no eixo x
    diff = (diff > 0.0f) ? diff : -diff;

    updateXDirection();
};

bool Ball::touchedPaddle(float paddleH) {
    if (
        // A diferen�a no eixo y y-difference is small enough
        diff <= paddleH / 2.0f &&
        // Estamos na posicao x correta
        pos.x <= 25.0f && pos.x >= 20.0f &&
        // A bolinha est� se movendo para a esquerda
        vel.x < 0.0f)
    {
        vel.x *= -1.0f;
        return true;
    }
    if(
        diff2 <= paddleH / 2.0f &&
        // Estamos na posicao x correta
        pos.x <= 1000.0f && pos.x >= 995.0f &&
        // A bolinha est� se movendo para a esquerda
        vel.x > 0.0f)
    {
        vel.x *= -1.0f;
        return true;
    }
    return false;
}

void Ball::updateXDirection() {
    if (pos.x <= thickness && vel.x < 0.0f)
    {
        vel.x *= -1;
    }


    else if (pos.x >= (768 - thickness) && vel.x > 0.0f)
    {
        vel.x *= -1;
    }
};

bool Ball::isOut() {
    return pos.y <= 0.0f;
};


Vector2 Ball::getPos() {
    return pos;
};

Vector2 Ball::getVel() {
    return vel;
};