#ifndef INPUT_H
#define INPUT_H
#include <SDL.h>
#include "cursor.h"
#include "canvas.h"

void process_input(Cursor *c, SDL_Window *window, Canvas *canvas, SDL_Surface *surface);

#endif

