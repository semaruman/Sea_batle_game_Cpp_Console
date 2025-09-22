#include <iostream>
#include "print_turnament_table.h"
#include "play_stuped_computer.h"
#include "play_smart_computer.h"
#include "play_friend.h"
#include "console_clear.h"



namespace menu {
	void menu() {
		int menu_value; // ���������� ��� �������������� ������������ � ����
		int pc_play_menu; // ���������� ��� �������������� ������������ � ������ ���� � �����������

		while (true) {

			std::cout << "\t�������� �����" << std::endl;
			std::cout << "1 - ������� ��������� �������" << std::endl;
			std::cout << "2 - ������ � �����������" << std::endl;
			std::cout << "3 - ������ � ������ �� ����� ����������" << std::endl;
			std::cout << "����� - ����� �� ����" << std::endl<<std::endl;

			std::cin >> menu_value;

			switch (menu_value) {
			case 1:
			    {
				    turnament_table::print_turnament_table();
				    std::cout << "������� ���-������ ��� �����������..." << std::endl;
					char temp[255];
					std::cin >> temp;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				    console_clear();
			    }
				break;

			case 2:
				std::cout << "�������� �����" << std::endl;
				std::cout << "0 - �����" << std::endl;
				std::cout << "1 - ������ � ������ �����������" << std::endl;
				std::cout << "����� - ������ � ����� �����������" << std::endl;
				try {
					std::cin >> pc_play_menu;
					pc_play_menu += 1;
					pc_play_menu -= 1;
				}
				catch (...) {
					continue;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				
				if (pc_play_menu == 1) {

					console_clear();
					play::play_stuped_computer();
					std::cout << "������� ���-������ ��� �����������..." << std::endl;
					char temp[255];
					std::cin >> temp;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else if (pc_play_menu == 0) {

					console_clear();
					break;
				}
				else {

					console_clear();
					play::play_smart_computer();
					std::cout << "������� ���-������ ��� �����������..." << std::endl;
					char temp[255];
					std::cin >> temp;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				console_clear();
				break;

			case 3:

				console_clear();
				{
					play::play_friend();
					std::cout << "������� ���-������ ��� �����������..." << std::endl;
					char temp[255];
					std::cin >> temp;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					console_clear();
					break;
				}
			case 0:

				console_clear();
				exit(0);
			}

		}

	}
}