#include <SDL.h>
#include <stdio.h>
#include "cursor.h"
#include "render.h"
#include "input.h"
#include "canvas.h"

#define WIDTH 900
#define HEIGHT 600

#define CURSOR_DEFAULTS {WIDTH / 2.0, HEIGHT / 2.0, 0, 0, 1, 0, 10, 40}

int main() {
	int done = 0;


	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow("Paint", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	SDL_Surface *surface = SDL_GetWindowSurface(window);
	Canvas canvas;
	initialize_canvas(&canvas, surface);

	Cursor cursor = CURSOR_DEFAULTS; 

	while (done != 1) { //polling for exit
		Uint32 frame_start = SDL_GetTicks();
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				done = 1;
			}
		}
	


		SDL_FillRect(surface, NULL, 0x00000000);
		memcpy(surface->pixels, canvas.pixels, sizeof(uint32_t) * canvas.width * canvas.height);

		process_input(&cursor, window);
		update_cursor(&cursor);
		draw_cursor(surface, &cursor);
		SDL_UpdateWindowSurface(window);
			
		Uint32 frame_time = SDL_GetTicks() - frame_start;

		if (frame_time < 16) {
			SDL_Delay(16 - frame_time);
		}
			
	}


	return 0;
	
}


