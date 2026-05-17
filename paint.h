#ifndef PAINT_H
#define PAINT_H
#include "cursor.h"
#include "canvas.h"


void put_pixel_canvas(Canvas *canvas, int x, int y, Uint32 color);

void paint(Canvas *canvas, Cursor *c);

#endif

