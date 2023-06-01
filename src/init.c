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
										SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	if (instance->window == NULL)
	{
		printf("Failed to create SDL window: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	/* Create an OpenGL context */
	instance->context = SDL_GL_CreateContext(instance->window);
	if (instance->context == NULL)
	{
		printf("Failed to create OpenGL context: %s\n", SDL_GetError());
		SDL_DestroyWindow(instance->window);
		SDL_Quit();
		return (1);
	}

		/* Set the clear color */
	glClearColor(0.2f, 0.3f, 0.4f, 1.0f);

	return (0);
}
