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
	double cx = c->x;
	double cy = c->y;
	int w = c->width;
	int h = c->height;

	double angle = c->direction * M_PI / 180.0;
	double sina = sin(angle);
	double cosa = cos(angle);

	// Calculate vertices
	double x1 = -w/2.0, y1 = -h/2.0;
	double x2 = w/2.0, y2 = -h/2.0;
	double x3 = w/2.0, y3 = h/2.0;
	double x4 = -w/2.0, y4 = h/2.0;

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

	// Cross product precomputation
	double e1x = x2p - x1p;
	double e1y = y2p - y1p;
	double e2x = x3p - x2p;
	double e2y = y3p - y2p;
	double e3x = x4p - x3p;
	double e3y = y4p - y3p;
	double e4x = x1p - x4p;
	double e4y = y1p - y4p;

	// Rendering 
	for (int y = (int) floor(min_y); y < (int) ceil(max_y); y++) {
		for (int x = (int) floor(min_x); x < (int) ceil(max_x); x++) {
			double cross1 = (e1x) * (y - y1p) - (e1y) * (x - x1p);	
			double cross2 = (e2x) * (y - y2p) - (e2y) * (x - x2p);	
			double cross3 = (e3x) * (y - y3p) - (e3y) * (x - x3p);	
			double cross4 = (e4x) * (y - y4p) - (e4y) * (x - x4p);	

			if ((cross1 >= 0 && cross2 >= 0 && cross3 >= 0 && cross4 >= 0)
			|| (cross1 <= 0 && cross2 <= 0 && cross3 <= 0 && cross4 <= 0)) {
				put_pixel(surface, x, y, 0x00FF0000);
			}
		}
	}
}




