#include <iostream>

namespace play {
	int* computer_motion() {
		int x, y;
		int coords[2];

		x = rand()%10; coords[0] = x;

		y = rand()%10; coords[1] = y;

		return coords;
	}
}