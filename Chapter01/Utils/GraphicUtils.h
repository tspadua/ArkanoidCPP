#pragma once

#include "SDL/SDL.h"
#include <vector>
#include "../Entities/Entity.h"
#define GRAPHICUTILS_H

class GraphicUtils {
public:
    GraphicUtils();

    float deltaTime;

    bool initializeWindow();

    void updateFrame();

    //void drawObjects(std::vector<Entity>& entities);
    void drawObjects();

    void shutdown();
    
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    Uint32 mTicksCount;

};