#ifndef _HEADER_
#define _HEADER_

#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_opengl.h>
#include <stdbool.h>
#include <math.h>


#define TILE_SIZE 64
#define MAP_SIZE (TILE_SIZE * 0.2)
#define MAP_NUM_ROWS 10
#define MAP_NUM_COLS 10

#define FOV_ANGLE 60 * (M_PI/ 180)
#define NUM_RAYS WINDOW_WIDTH

#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

extern const int map[MAP_NUM_ROWS][MAP_NUM_COLS];
extern float playerX;
extern float playerY;
extern float playerAngle;

/**
 * struct SDL_Instance - Node of a hash table
 *
 * @window: SDL window
 * @context: OpenGL context
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

/* Function prototypes */
int init_instance(SDL_Instance *instance);
int poll_events();
void renderMap(SDL_Instance instance);
void castRays(SDL_Instance instance);

#endif
