#include "../inc/header.h"

/**
* init_instance - initializing SDL2
* @instance: new SDL instance
* Return: 0 if it fails, 1 if it's successful.
*/
int init_instance(SDL_Instance *instance)
{
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL initialization failed: %s\n", SDL_GetError());
		return (1);
	}

	/* Create a window */
	instance->window = SDL_CreateWindow("Mazetrix", SDL_WINDOWPOS_CENTERED,
										SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
										WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
	if (instance->window == NULL)
	{
		printf("Failed to create SDL window: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	/* Create a new Renderer instance linked to the Window */
	instance->renderer = SDL_CreateRenderer(instance->window, -1,
		    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	/*instance->renderer = SDL_CreateRenderer(instance->window, -1, 0);*/
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n",
			SDL_GetError());
		SDL_Quit();
		return (1);
	}

	SDL_SetRenderDrawColor(instance->renderer, 255, 0, 0, 255);

	/* Clear the renderer and present the changes */
	SDL_RenderClear(instance->renderer);
	SDL_RenderPresent(instance->renderer);

	return (0);
}
