#include "Ball.h"

Ball::Ball() {};

void Ball::populate(float posX, float posY, float velX, float velY) {
    pos.x = posX;
    pos.y = posY;
    vel.x = velX;
    vel.y = velY;

    isInstanced = true;
};

void Ball::update(float deltaTime, Vector2 paddle1, Vector2 paddle2) {
    // atualiza a posi��o da bola com base na sua velocidade
    pos.x += vel.x * deltaTime;
    pos.y += vel.y * deltaTime;

    // atualiza a posi��o da bola se ela colidiu com a raquete
    diff = paddle1.y - pos.y;
    diff2 = paddle2.y - pos.y;
    //pegue o valor absoluto de diferen�a entre o eixo y da bolinha e da raquete
    //isso � necess�rio para os casos em que no pr�ximo frame a bolinha ainda n�o esteja t�o distante da raquete
    //verifica se a bola est� na area da raquete e na mesma posi��o no eixo x
    diff = (diff > 0.0f) ? diff : -diff;
    diff2 = (diff2 > 0.0f) ? diff2 : -diff2;

    updateYDirection();
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
    if (
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
};

void Ball::updateYDirection() {
    if (pos.y <= thickness && vel.y < 0.0f)
    {
        vel.y *= -1;
    }


    else if (pos.y >= (768 - thickness) && vel.y > 0.0f)
    {
        vel.y *= -1;
    }
};

bool Ball::isOutLeft() {
    return pos.x <= 0.0f;
};

bool Ball::isOutRight() {
    return pos.x >= 1024;
};

/*
bool Ball::isInstanced() {
    return isInstanced;
}
*/