#include "canvas.h"
#include <stdio.h>



void initialize_canvas(Canvas *canvas, SDL_Surface *surface) {

	canvas->width = surface->w;
	canvas->height = surface->h;
	canvas->pixels = malloc(sizeof(uint32_t) * canvas->width * canvas->height);
	if (canvas->pixels == NULL) {
		printf("Aww man the canvas wasn't malloc-ed right");
		return;
	}

	// Fill canvas with yellow-white color
	for (int i = 0; i < canvas->width * canvas->height; i++) {
		canvas->pixels[i] = SDL_MapRGB(surface->format, 0xFF, 0xFB, 0xEE);
	}
	
}

