#include <iostream>
#include "print_turnament_table.h"
#include "play_stuped_computer.h"
#include "play_smart_computer.h"
#include "play_friend.h"
#include "console_clear.h"
#include <string>


namespace menu {
	void menu() {
		int menu_value; // ���������� ��� �������������� ������������ � ����
		int pc_play_menu; // ���������� ��� �������������� ������������ � ������ ���� � �����������
		std::string tmp_menu_value, tmp_pc_play_menu;

		while (true) {

			std::cout << "\t�������� �����" << std::endl;
			std::cout << "1 - ������� ��������� �������" << std::endl;
			std::cout << "2 - ������ � �����������" << std::endl;
			std::cout << "3 - ������ � ������ �� ����� ����������" << std::endl;
			std::cout << "����� - ����� �� ����" << std::endl<<std::endl;

			std::cin >> tmp_menu_value;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			try
			{
				menu_value = stoi(tmp_menu_value);
			}

			catch (...)
			{
				std::cout << "������������ ����" << std::endl;
				system("pause");
				console_clear();
				continue;
			}

			switch (menu_value) {
			case 1:
			    {
				    turnament_table::print_turnament_table();
					system("pause");

				    console_clear();
			    }
				break;

			case 2:
				std::cout << "�������� �����" << std::endl;
				std::cout << "0 - �����" << std::endl;
				std::cout << "1 - ������ � ������ �����������" << std::endl;
				std::cout << "������ ����� - ������ � ����� �����������" << std::endl;
				
				std::cin >> tmp_pc_play_menu;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				try
				{
					pc_play_menu = stoi(tmp_pc_play_menu);
				}

				catch (...)
				{
					std::cout << "������������ ����" << std::endl;
					system("pause");
					console_clear();
					continue;
				}
				
				if (pc_play_menu == 1) {

					console_clear();
					play::play_stuped_computer();
					system("pause");
				}
				else if (pc_play_menu == 0) {

					console_clear();
					break;
				}
				else {

					console_clear();
					play::play_smart_computer();
					system("pause");
				}
				console_clear();
				break;

			case 3:

				console_clear();
				{
					play::play_friend();
					system("pause");
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