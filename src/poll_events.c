#include "../inc/header.h"

int poll_events()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return (1);
        }
    }

    return (0);
}
