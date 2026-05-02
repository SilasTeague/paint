#include "cursor.h"

void step_cursor(Cursor *c) {
	double radians = c->direction * M_PI / 180.0;

	c->x += cos(radians) * c->velocity;
	c->y += sin(radians) * c->velocity;
}
