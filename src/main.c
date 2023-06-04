#include "../inc/header.h"

const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

float playerX = 64 * 5;
float playerY = 64 * 5;
float playerAngle = 0;

/**
* main - entry point of the game
* Return: always 0 on success.
*/
int main(void)
{
	SDL_Instance instance;

	/* Initializing the Window and Render */
	if (init_instance(&instance) != 0)
		return (1);
	
	while ("game is running")
	{
		/* Retrieving Input Events */
		if (poll_events() == 1)
			break;
		
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 255);
		SDL_RenderClear(instance.renderer);

		renderMap(instance);
    	castRays(instance);

		SDL_RenderPresent(instance.renderer);

		/* Game Update */

		/* Rendering */
		
	}

	/* Render and Window destroy before quitting */
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();

	return (0);
}