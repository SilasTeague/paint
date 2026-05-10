#ifndef CANVAS_H
#define CANVAS_H

#include <stdint.h>
#include <SDL.h>

typedef struct {
	int width;
	int height;
	uint32_t *pixels;	
} Canvas;

void initialize_canvas(Canvas *canvas, SDL_Surface *surface); 

#endif

