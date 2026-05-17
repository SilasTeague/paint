#ifndef RENDER_H
#define RENDER_H

#include <SDL.h>
#include "cursor.h"

void put_pixel_surface(SDL_Surface *surface, int x, int y, Uint32 color);

void draw_cursor(SDL_Surface *surface, Cursor *c);

#endif
