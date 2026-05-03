#include <SDL.h>
#include <stdio.h>
#include "cursor.h"
#include "render.h"

#define WIDTH 900
#define HEIGHT 600

#define CURSOR_DEFAULTS {WIDTH / 2.0, HEIGHT / 2.0, 90, 0, 1, 0, 10, 40}

void process_input(Cursor *c);

int main() {
	int done = 0;


	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow("Paint", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	SDL_Surface *surface = SDL_GetWindowSurface(window);

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
		process_input(&cursor);
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


void process_input(Cursor *c) {
	const Uint8 *keyboard = SDL_GetKeyboardState(NULL);
	if (keyboard[SDL_SCANCODE_W]) {
		c->velocity += 2;
	}
	if (keyboard[SDL_SCANCODE_S]) {
		c->velocity -= 2;
	}
	if (keyboard[SDL_SCANCODE_A]) {
		c->angular_velocity -= 2;
	}
	if (keyboard[SDL_SCANCODE_D]) {
		c->angular_velocity += 2;
	}
	if (keyboard[SDL_SCANCODE_C]) {
		c->x = WIDTH / 2.0;
		c->y = HEIGHT / 2.0;
	}
}
