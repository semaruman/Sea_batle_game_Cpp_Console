#include <iostream>

namespace play {
	int* player_motion() { // ��� ������
		int x, y;
		int coords[2];
		std::cout << "��� ���(������� ���������� �� 0 �� 9): "<<std::endl;
		std::cout << "������� x: "; std::cin >> x; coords[0] = x;
		std::cout << "������� y: "; std::cin >> y; coords[1] = y;

		return coords;
	}
}