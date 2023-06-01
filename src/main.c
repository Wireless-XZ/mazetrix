#include "../inc/header.h"


/**
* main - entry point of the game
* Return: always 0 on success.
*/
int main(void)
{
	SDL_Instance instance;
	Player player;

    /* Initializing the Window and Open GL */
	if (init_instance(&instance) != 0)
		return (1);

	player.x = 5.0f;
	player.y = 5.0f;
	player.angle = 0.0f;

	int map[MAP_WIDTH][MAP_HEIGHT] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	game_loop(&instance, &player, map);

	SDL_GL_DeleteContext(instance.context);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();

	return (0);
}
