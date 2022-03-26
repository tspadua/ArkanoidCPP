#include "SDL/SDL.h"
#include "GraphicUtils.h"
#include <vector>

GraphicUtils::GraphicUtils() { };
const int thickness = 15;
bool GraphicUtils::initializeWindow() {
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

    return true;
}

float GraphicUtils::updateFrame() {
    // Espere que 16ms tenham passado desde o �ltimo frame - limitando os frames
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));

	// Delta time � a diferen�a em ticks do �ltimo frame
	// (convertido pra segundos) - calcula o delta time para atualiza��o do jogo
	deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;

	// "Clamp" (lima/limita) valor m�ximo de delta time
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}

	// atualize a contagem de ticks par ao pr�ximo frame
	mTicksCount = SDL_GetTicks();

	return deltaTime;
}


//                --------------->			std::vector<Entity>& entities
void GraphicUtils::drawObjects(EntityManager& entities) {
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

    //TODO: draw entities
    //entities.draw()
	SDL_Rect paddle {
		entities.paddle.pos.x,			// Top left x
		entities.paddle.pos.y,			// Top left y
		entities.paddle.width,		    // Width
		entities.paddle.height	        // Height
	};
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
	SDL_RenderFillRect(mRenderer, &paddle);

	for (int i = 0; i < maxBalls; i++) {
		//mudar a cor do renderizador para a bola
		SDL_SetRenderDrawColor(mRenderer, 255, 255, 0, 255);
		// Draw ball
		SDL_Rect ball{
			static_cast<int>(entities.balls[i].pos.x - entities.balls[i].thickness / 2),
			static_cast<int>(entities.balls[i].pos.y - entities.balls[i].thickness / 2),
			entities.balls[i].thickness,
			entities.balls[i].thickness
		};
		SDL_RenderFillRect(mRenderer, &ball);
	}

	for (int i = 0; i < maxTiles; i++) {
		if (entities.tiles[i].resistance > 0) {
			//mudar a cor do renderizador para a bola
			int red = 25 * entities.tiles[i].resistance;
			int green = 25 * entities.tiles[i].resistance;
			int blue = 25 * entities.tiles[i].resistance;
			SDL_SetRenderDrawColor(mRenderer, red, green, blue, 255);
			// Draw Tile
			SDL_Rect tile{
				entities.tiles[i].pos.x,			// Top left x
				entities.tiles[i].pos.y,			// Top left y
				entities.tiles[i].width,		    // Width
				entities.tiles[i].height
			};
			SDL_RenderFillRect(mRenderer, &tile);
		}
	}


	SDL_SetRenderDrawColor(mRenderer, 255, 255, 0, 255);


	// Swap front buffer and back buffer
	SDL_RenderPresent(mRenderer);
}

void GraphicUtils::shutdown() {
	SDL_DestroyRenderer(mRenderer);//encerra o renderizador
	SDL_DestroyWindow(mWindow);//encerra a janela aberta
}