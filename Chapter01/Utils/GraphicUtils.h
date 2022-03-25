#pragma once

#include "SDL/SDL.h"
#include <vector>
#include "../Entities/Entity.h"
#include "../Entities/EntityManager.h"
#define GRAPHICUTILS_H

class GraphicUtils {
public:
    GraphicUtils();

    float deltaTime;

    bool initializeWindow();

    float updateFrame();

    //void drawObjects(std::vector<Entity>& entities);
    void drawObjects(EntityManager& entities);

    void shutdown();
    
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    Uint32 mTicksCount = 0;

};