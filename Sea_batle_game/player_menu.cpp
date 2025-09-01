#include <iostream>
#include "print_turnament_table.h"
#include "play_stuped_computer.h"
#include "play_smart_computer.h"
#include "play_friend.h"
#include "console_clear.h"



namespace menu {
	void menu() {
		int menu_value; // переменная для взаимодействия пользователя и меню
		int pc_play_menu; // переменная для взаимодействия пользователя и режима игры с компьютером

		while (true) {

			std::cout << "\tВыберете опцию" << std::endl;
			std::cout << "1 - вывести турнирную таблицу" << std::endl;
			std::cout << "2 - играть с компьютером" << std::endl;
			std::cout << "3 - играть с другом на одном устройстве" << std::endl;
			std::cout << "иначе - выход из игры" << std::endl<<std::endl;

			std::cin >> menu_value;

			switch (menu_value) {
			case 1:
				turnament_table::print_turnament_table();

				console_clear();
				break;

			case 2:
				std::cout << "Выберете режим" << std::endl;
				std::cout << "0 - выход" << std::endl;
				std::cout << "1 - играть с глупым компьютером" << std::endl;
				std::cout << "иначе - играть с умным компьютером" << std::endl;
				std::cin >> pc_play_menu;
				
				if (pc_play_menu == 1) {

					console_clear();
					play::play_stuped_computer();
				}
				else if (pc_play_menu == 0) {

					console_clear();
					break;
				}
				else {

					console_clear();
					play::play_smart_computer();
				}
				console_clear();
				break;

			case 3:

				console_clear();

				play::play_friend();

				console_clear();
				break;

			case 0:

				console_clear();
				exit(0);
			}

		}

	}
}