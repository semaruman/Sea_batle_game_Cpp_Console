#include <iostream>
#include "CONSTANTS.h"

namespace coord {

	// функци€ дл€ проверки, попал ли игрок по кораблю или нет
	// ќна работает так: если координаты хода наход€тс€ в массиве из координат корабл€ противника,
	// то игрок попал => return true; иначе (если не попал) => return false;
	bool coord_in(int* coords, int computer_sheep_coords[2][SHEEP_SIZE]) { 
		
		bool flag = false;
		for (int i = 0;i < SHEEP_SIZE;i++) {
			if (coords[0] == computer_sheep_coords[0][i] && coords[1] == computer_sheep_coords[1][i]) {
				flag = true;
				computer_sheep_coords[0][i] = INT_MIN; // исключение координаты X из списка
				computer_sheep_coords[1][i] = INT_MIN; // исключение координаты Y из списка
				break;
			}
		}
		return flag;
	}
}