#include <iostream>

namespace play {
	int* player_motion() { // ход игрока
        static int coords[2]; // статический массив, чтобы вернуть указатель
        int x, y;

        while (true) {
            std::cout << "Ваш ход (введите координаты от 0 до 9):" << std::endl;

            std::cout << "Введите x: ";
            if (!(std::cin >> x) || x < 0 || x > 9) {
                std::cout << "Некорректный ввод! Попробуйте снова.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            std::cout << "Введите y: ";
            if (!(std::cin >> y) || y < 0 || y > 9) {
                std::cout << "Некорректный ввод! Попробуйте снова.\n";
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