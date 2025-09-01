#include <iostream>
#include "CONSTANTS.h"

	// проверка, остался ли в живых линкор
bool kill_linkor_sheep(int coords_array[2][SHEEP_SIZE]) {
	if (coords_array[0][0] == INT_MIN && coords_array[0][1] == INT_MIN && // проверка, заняты ли его координаты
		coords_array[0][2] == INT_MIN && coords_array[0][3] == INT_MIN) { // минимальным числом

		return true;
	}
	return false;
}