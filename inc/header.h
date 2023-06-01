#ifndef _HEADER_
#define _HEADER_

#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_opengl.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

/**
 * struct SDL_Instance - Node of a hash table
 *
 * @window: SDL window
 * @context: OpenGL context
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_GLContext context;
} SDL_Instance;

/**
 * struct Player - Node of a hash table
 *
 * @x: player's x cordinate
 * @y: player's y cordinate
 * @angle: rotation angle
 */
typedef struct Player
{
	float x;
	float y;
	float angle;
} Player;

/* function prototypes */
int init_instance(SDL_Instance *instance);
void game_loop(SDL_Instance *instance, Player *player,
			   int map[MAP_WIDTH][MAP_HEIGHT]);
void render_walls(Player *player,
				  int map[MAP_WIDTH][MAP_HEIGHT]);

#endif
