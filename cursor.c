#include "cursor.h"

void update_cursor(Cursor *c) {
	double radians = c->direction * M_PI / 180.0;

	c->angular_velocity *= 0.70;
	c->velocity *= 0.95;
	c->direction += c->angular_velocity;
	c->x += cos(radians) * c->velocity;
	c->y += sin(radians) * c->velocity;
}
