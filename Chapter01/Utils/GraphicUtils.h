#pragma once

#include "SDL/SDL.h"
#define GRAPHICUTILS_H

class GraphicUtils {
    public:
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;
		Uint32 mTicksCount;
        float deltaTime;

        GraphicUtils();

        bool initializeWindow();

        void updateFrame();

        void drawObjects();

        void shutdown();
}