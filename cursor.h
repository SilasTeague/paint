#ifndef CURSOR_H
#define CURSOR_H

#include <stdio.h>
#include <SDL.h>
#include <math.h>

typedef struct {
	double x;
	double y;
	double direction;

	double velocity;
	double angular_velocity;
	double acceleration;

	int width;
	int height;
} Cursor;


void update_cursor(Cursor *c);


#endif
