#include <iostream>

namespace play {
	int* player_motion() { // ��� ������
        static int coords[2]; // ����������� ������, ����� ������� ���������
        int x, y;

        while (true) {
            std::cout << "��� ��� (������� ���������� �� 0 �� 9):" << std::endl;

            std::cout << "������� x: ";
            if (!(std::cin >> x) || x < 0 || x > 9) {
                std::cout << "������������ ����! ���������� �����.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            std::cout << "������� y: ";
            if (!(std::cin >> y) || y < 0 || y > 9) {
                std::cout << "������������ ����! ���������� �����.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            coords[0] = x;
            coords[1] = y;
            return coords;
        }
	}
}