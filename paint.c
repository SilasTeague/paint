#include <SDL.h>
#include <stdio.h>

#define WIDTH 900
#define HEIGHT 600

int main() {
	int done = 0;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow("Paint", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);


	while (done != 1) { //polling for exit
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				done = 1;
			}
		}
	}


	return 0;
	
}
