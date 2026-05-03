#include <SDL.h>
#include <stdio.h>
#include "cursor.h"
#include "render.h"

#define WIDTH 900
#define HEIGHT 600

#define CURSOR_DEFAULTS {WIDTH / 2.0, HEIGHT / 2.0, 0, 0, 1, 0, 40, 10}

int main() {
	int done = 0;


	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow("Paint", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	SDL_Surface *surface = SDL_GetWindowSurface(window);

	Cursor cursor = CURSOR_DEFAULTS; 

	while (done != 1) { //polling for exit
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				done = 1;
			}
		}
	
		SDL_FillRect(surface, NULL, 0x00000000);
		update_cursor(&cursor);
		draw_cursor(surface, &cursor);
		SDL_UpdateWindowSurface(window);
			
			
	}


	return 0;
	
}
