#include <stdio.h>
#include <SDL.h>
#include <math.h>

typedef struct {
	double x;
	double y;
	int width;
	int height;
	double direction;

	double velocity;
	double acceleration;

} Cursor;


void step_cursor(Cursor *c);

