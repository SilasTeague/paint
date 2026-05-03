#include "render.h"
#include <math.h>

void put_pixel(SDL_Surface *surface, int x, int y, Uint32 color) {
	if (x < 0 || x >= surface->w || y < 0 || y >= surface->h) {
		return;
	}
	Uint32 *pixels = (Uint32 *) surface->pixels;

	pixels[(y * surface->pitch / 4) + x] = color;
}

void draw_cursor(SDL_Surface *surface, Cursor *c) {
	int cx = c->x;
	int cy = c->y;
	int w = c->width;
	int h = c->height;

	double angle = c->direction;
	double sina = sin(angle);
	double cosa = cos(angle);

	// Calculate vertices
	int x1 = -w/2, y1 = -h/2;
	int x2 = w/2, y2 = -h/2;
	int x3 = w/2, y3 = h/2;
	int x4 = -w/2, y4 = h/2;

	// Rotate vertices (local coordinates)
	double x1p = x1 * cosa - y1 * sina, y1p = x1 * sina + y1 * cosa;
	double x2p = x2 * cosa - y2 * sina, y2p = x2 * sina + y2 * cosa;
	double x3p = x3 * cosa - y3 * sina, y3p = x3 * sina + y3 * cosa;
	double x4p = x4 * cosa - y4 * sina, y4p = x4 * sina + y4 * cosa;

	// Convert local coordinates to display relative
	x1p += cx;
	y1p += cy;
	x2p += cx;
	y2p += cy;
	x3p += cx;
	y3p += cy;
	x4p += cx;
	y4p += cy;

	// Determine bounds
	double min_x = fmin(fmin(x1p, x2p), fmin(x3p, x4p));
	double max_x = fmax(fmax(x1p, x2p), fmax(x3p, x4p));
	double min_y = fmin(fmin(y1p, y2p), fmin(y3p, y4p));
	double max_y = fmax(fmax(y1p, y2p), fmax(y3p, y4p));


	// Rendering TODO: actually render the rectangle
	for (int y = (int) min_y; y < (int) max_y; y++) {
		for (int x = (int) min_x; x < (int) max_x; x++) {

			put_pixel(surface, x, y, 0x00FF0000);
		}
	}
}




