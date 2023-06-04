#include "../inc/header.h"

void castRays(SDL_Instance instance)
{
    for (int rayIndex = 0; rayIndex < NUM_RAYS; rayIndex++)
    {
        float rayAngle = playerAngle - (FOV_ANGLE / 2) + (rayIndex * FOV_ANGLE / NUM_RAYS);
        float distanceToWall = 0;

        float rayX = cos(rayAngle);
        float rayY = sin(rayAngle);

        float testX = playerX;
        float testY = playerY;

        while (map[(int)(testY / TILE_SIZE)][(int)(testX / TILE_SIZE)] == 0)
        {
            SDL_SetRenderDrawColor(instance.renderer, 0, 0, 255, 255);
            SDL_RenderDrawPoint(instance.renderer, testX*0.2, testY*0.2);

            SDL_SetRenderDrawColor(instance.renderer, 0, 255, 0, 255);
            SDL_RenderDrawPoint(instance.renderer, testX*0.2, testY*0.2);

            distanceToWall += 0.2;
            testX += rayX;
            testY += rayY;
        }

       

        // Calculate the distance to the wall using the Pythagorean theorem
        distanceToWall = distanceToWall * cos(playerAngle - rayAngle);

        // Calculate the wall height based on the distance
        float wallHeight = (MAP_SIZE / distanceToWall) * (WINDOW_HEIGHT / 2);

        // Draw the walls
        SDL_SetRenderDrawColor(instance.renderer, 255, 0, 0, 0);
        SDL_RenderDrawLine(instance.renderer, rayIndex, (WINDOW_HEIGHT / 2) - (wallHeight / 2),
                           rayIndex, (WINDOW_HEIGHT / 2) + (wallHeight / 2));
        
         // Draw the floor
        SDL_SetRenderDrawColor(instance.renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(instance.renderer, rayIndex, (WINDOW_HEIGHT / 2) + (wallHeight / 2),
                           rayIndex, 639);
    }
}

void renderMap(SDL_Instance instance)
{
    for (int y = 0; y < MAP_NUM_COLS; y++)
    {
        for (int x = 0; x < MAP_NUM_ROWS; x++)
        {
            if (map[y][x] == 1)
            {
                SDL_SetRenderDrawColor(instance.renderer, 255, 255, 255, 255);
                SDL_Rect wallRect = {x * MAP_SIZE, y * MAP_SIZE,
                                        MAP_SIZE, MAP_SIZE};
    
                SDL_RenderFillRect(instance.renderer, &wallRect);
            }
            else
            {
                SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 255);
                SDL_Rect wallRect = {x * MAP_SIZE, y * MAP_SIZE,
                                        MAP_SIZE, MAP_SIZE};
                SDL_RenderFillRect(instance.renderer, &wallRect);
            }
        }
    }

    /* Player postioned in the center */
    SDL_SetRenderDrawColor(instance.renderer, 0, 255, 0, 255);
    SDL_RenderDrawPoint(instance.renderer, 5 * MAP_SIZE, 5 * MAP_SIZE);
}