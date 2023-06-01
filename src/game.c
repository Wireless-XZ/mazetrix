#include "../inc/header.h"

/**
 * game_loop - handles the game loop
 * @instance: initialized SDL instance
 * @player: the player
 * @map: maze map
 */
void game_loop(SDL_Instance *instance, Player *player,
	int map[MAP_WIDTH][MAP_HEIGHT]
)
{
	SDL_Event event;
	int running = 1;

	while (running)
	{
		/* Handle events */
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = 0;
		}

		/* Update game state */

		/* Render graphics */
		glClear(GL_COLOR_BUFFER_BIT);
		render_walls(player, map);
		SDL_GL_SwapWindow(instance->window);
	}
}


void render_walls(Player *player, int map[MAP_WIDTH][MAP_HEIGHT])
{
    int screenWidth = 800;
    int screenHeight = 600;
    float wallHeight = 32.0f; // Height of the wall in pixels

    float playerX = player->x;
    float playerY = player->y;
    float playerAngle = player->angle;

    // Draw the ceiling
    glColor3f(0.6f, 0.6f, 0.6f); // Light gray color for the ceiling
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(screenWidth, 0);
    glVertex2f(screenWidth, screenHeight / 2);
    glVertex2f(0, screenHeight / 2);
    glEnd();

    // Draw the floor
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray color for the floor
    glBegin(GL_QUADS);
    glVertex2f(0, screenHeight / 2);
    glVertex2f(screenWidth, screenHeight / 2);
    glVertex2f(screenWidth, screenHeight);
    glVertex2f(0, screenHeight);
    glEnd();

    // Raycasting
    for (int x = 0; x < screenWidth; x++)
    {
        // Calculate the ray angle based on the player's current angle and the screen column
        float rayAngle = playerAngle - atan2((float)x - screenWidth / 2, screenWidth / 2);
        float distanceToWall = 0;
        int hitWall = 0;
        int wallHeightPixels = 0;

        float stepSize = 0.1f; // Step size for ray casting

        float eyeX = sin(rayAngle);
        float eyeY = cos(rayAngle);

        while (!hitWall && distanceToWall < 20.0f)
        {
            distanceToWall += stepSize;

            int testX = (int)(playerX + eyeX * distanceToWall);
            int testY = (int)(playerY + eyeY * distanceToWall);

            // Check if the ray is out of bounds
            if (testX < 0 || testX >= MAP_WIDTH || testY < 0 || testY >= MAP_HEIGHT)
            {
                hitWall = 1;
                distanceToWall = 20.0f; // Set distance to maximum to prevent rendering outside the map
            }
            else
            {
                // Check if the ray hits a wall
                if (map[testX][testY] == 1)
                {
                    hitWall = 1;

                    // Calculate the wall height based on the distance to the wall
                    wallHeightPixels = (int)(wallHeight / distanceToWall * screenHeight / 2);

                    // Choose a color for the wall
                    glColor3f(0.8f, 0.2f, 0.2f); // Red color for walls

                    // Calculate the position and size of the wall slice on the screen
                    int wallTop = (screenHeight / 2) - (wallHeightPixels / 2);
                    int wallBottom = (screenHeight / 2) + (wallHeightPixels / 2);

                    // Draw the wall slice
                    glBegin(GL_QUADS);
                    glVertex2f(x, wallTop);
                    glVertex2f(x + 1, wallTop);
                    glVertex2f(x + 1, wallBottom);
                    glVertex2f(x, wallBottom);
                    glEnd();
                }
            }
        }
    }
}
