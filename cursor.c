#include "cursor.h"

void update_cursor(Cursor *c) {
	double radians = c->direction * M_PI / 180.0;

	c->direction += c->angular_velocity;
	c->x += cos(radians) * c->velocity;
	c->y += sin(radians) * c->velocity;
}
