#include "input.h"

void process_input(Cursor *c, SDL_Window *window) {
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
		int center_x, center_y;
		SDL_GetWindowSize(window, &center_x, &center_y);
		c->x = center_x / 2.0;
		c->y = center_y / 2.0;
	}
}
