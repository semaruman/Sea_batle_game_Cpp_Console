#include <iostream>

namespace play {
	int* player_motion() { // ход игрока
		int x, y;
		int coords[2];
		std::cout << "¬аш ход(введите координаты от 0 до 9): "<<std::endl;
		std::cout << "¬ведите x: "; std::cin >> x; coords[0] = x;
		std::cout << "¬ведите y: "; std::cin >> y; coords[1] = y;

		return coords;
	}
}