/*

#include <iostream>
#include "CONSTANTS.h"
#include <string>



namespace play {
	void player_ship_place(int player_coords[2][SHEEP_SIZE])
	{
		//������� ���������:
		//� ����� ������ list_ships �� ������� �������� ��������.
		//���� for ��� �� ����� ������� � � ����������� �� �������� �������� � ���� �������� � 4 ������ �����
		//����������, ������� ������������� ����������� ��������. ����������� ��� ����� switch.
		//������ ���������� ��� ���������� �����������, � ����������� �� ����������� ������ �������� �������,
		//� ���� ���������� �������� ���������� � ������ ������� ������� player_coords.
		//��������, ������ ����� ������������ �� ����� ������� list_ships �� �������� �� ��������� i=3,4,5.
		//� ���������� � ������ player_coords ����� �������� �� �������� � 10 �� 15.
		//������� ������ ����� ������������ � ����� if(i==3), else if(i==4) � ��,
		//��� ��������� � ���������� ������� � ��������.

		//� ��� ��� ����������� ������� � ��������� ������ (������� ��������� ����� ���������)
		//� ����� ������������ ��������� ������ free_cells, � ������� �������� ���������� ��� ��������
		//�������� ���������, ������ ��� �������� �� � ������� ������ player_coords.
		//���������� ������ ��������� ������ �������� ��������� (1 - ������ ��������, 0 - ������ ������), � �� ���� ����������
		//���� ���������, ������ ��������� ������ ����� ����������� ������.

		int list_ships[10]{ 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };//������ ������ ��� ������� �� �������� �� ���������
		int free_cells[100];//������ ������ ���� ��� �������� ��������/������.

		//��������� ���� ��� ���������� ������� ������ ���������. ���������� ���� ������, � ������ ��� ��������.
		for (int i = 0; i < 100; i++)
		{
			free_cells[i] = 1;
		}

		//������� ����, ������� �������� ��������� �� 10 ��������
		for (int i = 0; i < 10; i++)
		{
			std::string coord_1_beg_str, coord_2_beg_str, coord_1_end_str, coord_2_end_str;
			int coord_1_beg_int, coord_2_beg_int, coord_1_end_int, coord_2_end_int, tmp_coord_1_mid1, tmp_coord_2_mid1, tmp_coord_1_mid2, tmp_coord_2_mid2;

			//���������� ���������� ������� �����, ����� ��� ��������������� ����� �� ������ ��������
			//�� �������, � ���������� �������� ������ ������ � ����� �������.
			//��� ������ �� ������ � ������ ��������� ��� �������� � ��������� ����, � ����� ���������� � ��� ��� � ����������� ������� ������ �����.
			//���������� ����������:
			//coord_1_beg_str, coord_1_beg_int - ���������� ������ ������ ������ ������� � ��������� � ������� ���� ������ ��������������.
			//coord_2_beg_str, coord_2_beg_int - ���������� ������� ������ ������ ������� � ��������� � ������� ���� ������ ��������������.
			//coord_1_end_str, coord_1_end_int - ���������� ������ ��������� ������ ������� � ��������� � ������� ���� ������ ��������������.
			//coord_2_end_str, coord_2_end_int - ���������� ������� ��������� ������ ������� � ��������� � ������� ���� ������ ��������������.
			//tmp_coord_1_mid1, tmp_coord_2_mid1 - �� �������� � ���������� � ���� �������������, ������ �� �������� ��������� ������/��������� �����, ��� ������ ����� ������������� ������.
			//tmp_coord_1_mid2, tmp_coord_2_mid2 - ������������� �������������� ��� ������ �������������� ������ �� ������ �������� ��������� ������/���������. ������������ � ���� � ����������� ��� �������� ���������������.

			//��������� ���� ��� �������� ������������ �������. case 4 - ��������������, case 3 - ��� � ��.
			switch (list_ships[i])
			{
			case 4:

				//�� �������������� � ������������� � �� ����� ������ �� �������, ������� ����� �������� � ������� ��������� � ���, ��� ������ ����� ������.
				//������ � ����� � ������ ������� ������ � ����� ����� ������ �������, ����� ��� ������� ��� �������.
				std::cout << "������� ����� ������ ��� ���������� ������ ������ 4-� �������� �������: ";
				std::cin >> coord_1_beg_str;
				std::cout << "������� ����� ������� ��� ���������� ������ ������ 4-� �������� �������: ";
				std::cin >> coord_2_beg_str;

				//���� �������� � ��� ���. ����� �������� ������ � ����������� ���, ������� ������������� �������� �������� ���������.
				try
				{
					coord_1_beg_int = stoi(coord_1_beg_str);
					coord_2_beg_int = stoi(coord_2_beg_str);
				}

				//���� ���� �����, �� ��������� ��������� �� ������ � ��� ���������� �� ���� �������� �����, ��� �� ����� �������� � ���� ����, ����� ���������� ��������.
				catch (...)
				{
					std::cout << "������������ ����" << std::endl;
					i--;
					break;
				}

				//���� ���������, ����� �������� ��������� ���� � ��������� �� 0 �� 9. ����� ��� ���������� �� ���� �������� �����.
				if (!(coord_1_beg_int >= 0 && coord_1_beg_int < 10 && coord_2_beg_int >= 0 && coord_2_beg_int < 10))
				{
					std::cout << "������� ������������ ����������" << std::endl;
					i--;
					break;
				}

				//������ ���������� ��������� ������ � ������������ ����������.
				std::cout << "������� ����� ������ ��� ���������� ��������� ������ 4-� �������� �������: ";
				std::cin >> coord_1_end_str;
				std::cout << "������� ����� ������� ��� ���������� ��������� ������ 4-� �������� �������: ";
				std::cin >> coord_2_end_str;

				try
				{
					coord_1_end_int = stoi(coord_1_end_str);
					coord_2_end_int = stoi(coord_2_end_str);
				}

				catch (...)
				{
					std::cout << "������������ ����" << std::endl;
					i--;
					break;
				}

				//��� � ��������������� � ������� ����, �������� ���������� ������ � ��������� ������ �� ������, ���� ������������ ��� �� � �������� �������.
				if ((coord_1_beg_int * 10 + coord_2_beg_int) > (coord_1_end_int * 10 + coord_2_end_int))
				{
					int coord_1_tmp = coord_1_beg_int;
					int coord_2_tmp = coord_2_beg_int;
					coord_1_beg_int = coord_1_end_int;
					coord_2_beg_int = coord_2_end_int;
					coord_1_end_int = coord_1_tmp;
					coord_2_end_int = coord_2_tmp;
				}

				//��� �� ��������� �������� �� ������ ������ � ����� ������� �� ����� ������� ��������� ������.
				//���� ���� �� ����� �������� �� ������� ������, �� �� �������� ��������� �� ������ � ��� ����������� �� ���� ��������, ��� �� ����� ������ ����������.
				//����� ������� ��������, ��� �� ������ ���������� ���������������, �� ���� ��� �������� � ��� �������� �������.
				//� ��� ���� �� ��� ������������������ ��������, � ������� � �������� � ������. ���� � ���, ��� � �������� ������� ����� �����,
				//������� �� ������������, ��� � ��������� ��� ������� ����� �� ����� ���� � �������� ��� ���������� � ���������, ������������ ��� ������� ��������.
				//����� ����, ��� ������� ��������� �������� �� ���������� ���� ��������� ����. � ����������� � ���������, ������ ������ ����������� � ���� ������ �������.
				//� ���� ��, ��� ��������� ��������������. ������� � �������� �� ����� ����, ��� �� ��������, � ������ �������� ������� �����)
				if (free_cells[coord_1_beg_int * 10 + coord_2_beg_int] && free_cells[coord_1_end_int * 10 + coord_2_end_int]) {

					//��� �������� �� ���������� ����� �������� ��������. ��� �������� � �������� ���������� ����� � ������ ������ �� ������� (������*10+�������), ��� ��, ��������, ��� ����� (0, 1) (0, 4) �������� 1 � 4 ������.
					//��� ��������������� ������� ������ ���� ���� 3 ������ ��� �������������� ������������, ���� 30 ��� ������������.
					//���� ����� ������� ����, �� �� �������� ��������� �� ������ �, ��� �� ��� ��������, ������������ �� �������� �����.
					if (coord_1_end_int >= 0 && coord_1_end_int < 10 && coord_2_end_int >= 0 && coord_2_end_int < 10 && ((coord_1_end_int * 10 + coord_2_end_int) - (coord_1_beg_int * 10 + coord_2_beg_int) == 3 || (coord_1_end_int * 10 + coord_2_end_int) - (coord_1_beg_int * 10 + coord_2_beg_int) == 30))
					{
						//����� ��� ����� �������� ���������� 2 � 3 �����.
						//���� ���������� ������ ������ � ����� ���������, �� ������� ������������. � ��������.
						//��� �������������� � 2 � 3 ����� ������ ����� ����� ������ ������, � ������� +1 � +2 �� ������ ��������������. � ��������.
						if (coord_1_beg_int == coord_1_end_int)
						{
							tmp_coord_1_mid1 = coord_1_beg_int;
							tmp_coord_1_mid2 = coord_1_beg_int;
							tmp_coord_2_mid1 = coord_2_beg_int + 1;
							tmp_coord_2_mid2 = coord_2_beg_int + 2;
						}
						else
						{
							tmp_coord_1_mid1 = coord_1_beg_int + 1;
							tmp_coord_1_mid2 = coord_1_beg_int + 2;
							tmp_coord_2_mid1 = coord_2_beg_int;
							tmp_coord_2_mid2 = coord_2_beg_int;
						}

						//��� �������� �� ������������ ���� �������� � ��� �� ���������� ������� ��� ���������� � ������� ������ player_coords.
						player_coords[0][0] = coord_1_beg_int;
						player_coords[1][0] = coord_2_beg_int;
						player_coords[0][1] = tmp_coord_1_mid1;
						player_coords[1][1] = tmp_coord_2_mid1;
						player_coords[0][2] = tmp_coord_1_mid2;
						player_coords[1][2] = tmp_coord_2_mid2;
						player_coords[0][3] = coord_1_end_int;
						player_coords[1][3] = coord_2_end_int;


						//�� ����� ��� ������� ������ ������� � ������� ������ free_cells. � ��� ������� ����. � ���������� � ����� �������� ����� �������� � ������ ������ ���� if.
						//���������� ��������������� � �����������. �� ������� ���������� ����� 80 �� ������ ����� �����������.
						//������ ����� ���� ����������� � 9 ��������� �������� �� ����, ��� ������� � �������� ������ ���������� ������ ������ �����. � ��� ������ �� ���-�� ������ �� ����, ��� ���������� ������ ���������� ��� ����������.
						//���������� ���������� 4 ����, ������ ����� ����, �������� ����, � ��� � ��������� 1-8 ��� �����/�������� (����� ������, ����� ����).
						//� ������ ��������������, � ���������� ���� ������ ������� �����, ��� ������� ������������� ������ �� �� � ��� 2-3 �����.
						//� ��� � ������� 2-� � 3-� ��������, � ��������� ���������� ��������, ������� ���������� �������� �� ����� � ��� �� �������. ��� �� ������ �� ���������, �� �� �������� �����������.
						if (coord_1_beg_int == 0 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; }
						{
							if (coord_1_end_int == 0 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; }
							else if (coord_1_end_int == 0 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int == 0 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; };
						}

					}
					else
					{
						std::cout << "������� ������������ ����������" << std::endl;
						i--;
						break;
					}
				}

				else
				{
					std::cout << "������ ������" << std::endl;
					i--;
					break;
				}
				break;

			case 3:
				//��� 2-� � 3-� �������� �� ��������� ����������� ��������� � 4-�, ��� ��� �� ���� ������ �� �������� ���������.
				std::cout << "������� ����� ������ ��� ���������� ������ ������ 3-� �������� ������� ����� " << i << ": ";
				std::cin >> coord_1_beg_str;
				std::cout << "������� ����� ������� ��� ���������� ������ ������ 3-� �������� ������� ����� " << i << ": ";
				std::cin >> coord_2_beg_str;

				try
				{
					coord_1_beg_int = stoi(coord_1_beg_str);
					coord_2_beg_int = stoi(coord_2_beg_str);
				}

				catch (...)
				{
					std::cout << "������������ ����" << std::endl;
					i--;
					break;
				}

				if (!(coord_1_beg_int >= 0 && coord_1_beg_int < 10 && coord_2_beg_int >= 0 && coord_2_beg_int < 10))
				{
					std::cout << "������� ������������ ����������" << std::endl;
					i--;
					break;
				}

				std::cout << "������� ����� ������ ��� ���������� ��������� ������ 3-� �������� ������� ����� " << i << ": ";
				std::cin >> coord_1_end_str;
				std::cout << "������� ����� ������� ��� ���������� ��������� ������ 3-� �������� ������� ����� " << i << ": ";
				std::cin >> coord_2_end_str;

				try
				{
					coord_1_end_int = stoi(coord_1_end_str);
					coord_2_end_int = stoi(coord_2_end_str);
				}

				catch (...)
				{
					std::cout << "������������ ����" << std::endl;
					i--;
					break;
				}

				if ((coord_1_beg_int * 10 + coord_2_beg_int) > (coord_1_end_int * 10 + coord_2_end_int))
				{
					int coord_1_tmp = coord_1_beg_int;
					int coord_2_tmp = coord_2_beg_int;
					coord_1_beg_int = coord_1_end_int;
					coord_2_beg_int = coord_2_end_int;
					coord_1_end_int = coord_1_tmp;
					coord_2_end_int = coord_2_tmp;
				}

				if (free_cells[coord_1_beg_int * 10 + coord_2_beg_int] && free_cells[coord_1_end_int * 10 + coord_2_end_int]) {
					if (coord_1_end_int >= 0 && coord_1_end_int < 10 && coord_2_end_int >= 0 && coord_2_end_int < 10 && ((coord_1_end_int * 10 + coord_2_end_int) - (coord_1_beg_int * 10 + coord_2_beg_int) == 2 || (coord_1_end_int * 10 + coord_2_end_int) - (coord_1_beg_int * 10 + coord_2_beg_int) == 20))
					{
						if (coord_1_beg_int == coord_1_end_int)
						{
							tmp_coord_1_mid1 = coord_1_beg_int;
							tmp_coord_2_mid1 = coord_2_end_int - 1;
						}
						else
						{
							tmp_coord_1_mid1 = coord_1_end_int - 1;
							tmp_coord_2_mid1 = coord_2_beg_int;
						}

						if (i == 1)
						{
							player_coords[0][4] = coord_1_beg_int;
							player_coords[1][4] = coord_2_beg_int;
							player_coords[0][5] = tmp_coord_1_mid1;
							player_coords[1][5] = tmp_coord_2_mid1;
							player_coords[0][6] = coord_1_end_int;
							player_coords[1][6] = coord_2_end_int;
						}
						else if (i == 2)
						{
							player_coords[0][7] = coord_1_beg_int;
							player_coords[1][7] = coord_2_beg_int;
							player_coords[0][8] = tmp_coord_1_mid1;
							player_coords[1][8] = tmp_coord_2_mid1;
							player_coords[0][9] = coord_1_end_int;
							player_coords[1][9] = coord_2_end_int;
						}


						if (coord_1_beg_int == 0 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; }
						{
							if (coord_1_end_int == 0 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; }
							else if (coord_1_end_int == 0 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int == 0 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; };
						}

					}
					else
					{
						std::cout << "������� ������������ ����������" << std::endl;
						i--;
						break;
					}
				}

				else
				{
					std::cout << "������ ������" << std::endl;
					i--;
					break;
				}
				break;

			case 2:
				std::cout << "������� ����� ������ ��� ���������� ������ ������ 2-�� �������� ������� ����� " << i - 2 << ": ";
				std::cin >> coord_1_beg_str;
				std::cout << "������� ����� ������� ��� ���������� ������ ������ 2-�� �������� ������� ����� " << i - 2 << ": ";
				std::cin >> coord_2_beg_str;

				try
				{
					coord_1_beg_int = stoi(coord_1_beg_str);
					coord_2_beg_int = stoi(coord_2_beg_str);
				}

				catch (...)
				{
					std::cout << "������������ ����" << std::endl;
					i--;
					break;
				}

				if (!(coord_1_beg_int >= 0 && coord_1_beg_int < 10 && coord_2_beg_int >= 0 && coord_2_beg_int < 10))
				{
					std::cout << "������� ������������ ����������" << std::endl;
					i--;
					break;
				}

				std::cout << "������� ����� ������ ��� ���������� ������ ������ 2-�� �������� ������� ����� " << i - 2 << ": ";
				std::cin >> coord_1_end_str;
				std::cout << "������� ����� ������� ��� ���������� ������ ������ 2-�� �������� ������� ����� " << i - 2 << ": ";
				std::cin >> coord_2_end_str;

				try
				{
					coord_1_end_int = stoi(coord_1_end_str);
					coord_2_end_int = stoi(coord_2_end_str);
				}

				catch (...)
				{
					std::cout << "������������ ����" << std::endl;
					i--;
					break;
				}

				if ((coord_1_beg_int * 10 + coord_2_beg_int) > (coord_1_end_int * 10 + coord_2_end_int))
				{
					int coord_1_tmp = coord_1_beg_int;
					int coord_2_tmp = coord_2_beg_int;
					coord_1_beg_int = coord_1_end_int;
					coord_2_beg_int = coord_2_end_int;
					coord_1_end_int = coord_1_tmp;
					coord_2_end_int = coord_2_tmp;
				}

				if (free_cells[coord_1_beg_int * 10 + coord_2_beg_int] && free_cells[coord_1_end_int * 10 + coord_2_end_int]) {
					if (coord_1_end_int >= 0 && coord_1_end_int < 10 && coord_2_end_int >= 0 && coord_2_end_int < 10 && ((coord_1_end_int * 10 + coord_2_end_int) - (coord_1_beg_int * 10 + coord_2_beg_int) == 1 || (coord_1_end_int * 10 + coord_2_end_int) - (coord_1_beg_int * 10 + coord_2_beg_int) == 10))
					{
						if (i == 3)
						{
							player_coords[0][10] = coord_1_beg_int;
							player_coords[1][10] = coord_2_beg_int;
							player_coords[0][11] = coord_1_end_int;
							player_coords[1][11] = coord_2_end_int;
						}
						else if (i == 4)
						{
							player_coords[0][12] = coord_1_beg_int;
							player_coords[1][12] = coord_2_beg_int;
							player_coords[0][13] = coord_1_end_int;
							player_coords[1][13] = coord_2_end_int;
						}
						else
						{
							player_coords[0][14] = coord_1_beg_int;
							player_coords[1][14] = coord_2_beg_int;
							player_coords[0][15] = coord_1_end_int;
							player_coords[1][15] = coord_2_end_int;
						}

						if (coord_1_beg_int == 0 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; }
						{
							if (coord_1_end_int == 0 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; }
							else if (coord_1_end_int == 0 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int == 0 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; };
						}

					}
					else
					{
						std::cout << "������� ������������ ����������" << std::endl;
						i--;
						break;
					}
				}

				else
				{
					std::cout << "������ ������" << std::endl;
					i--;
					break;
				}
				break;

			case 1:
				//��� ������������ � ��������� ������ ���������� ������ ������, ��� ��� ����� ���������� ��� �������� ������ ���� �������)
				//� ��������� �� ����������.
				std::cout << "������� ����� ������ ��� ���������� 1 �������� ������� ����� " << i - 5 << ": ";
				std::cin >> coord_1_beg_str;
				std::cout << "������� ����� ������� ��� ���������� 1 �������� ������� ����� " << i - 5 << ": ";
				std::cin >> coord_2_beg_str;

				try
				{
					coord_1_beg_int = stoi(coord_1_beg_str);
					coord_2_beg_int = stoi(coord_2_beg_str);
				}

				catch (...)
				{
					std::cout << "������������ ����" << std::endl;
					i--;
					break;
				}

				if (free_cells[coord_1_beg_int * 10 + coord_2_beg_int]) {
					if (coord_1_beg_int >= 0 && coord_1_beg_int < 10 && coord_2_beg_int >= 0 && coord_2_beg_int < 10)
					{
						player_coords[0][i + 10] = coord_1_beg_int;
						player_coords[1][i + 10] = coord_2_beg_int;

						if (coord_1_beg_int == 0 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; };

					}
					else
					{
						std::cout << "������� ������������ ����������" << std::endl;
						i--;
						break;
					}
				}
				else
				{
					std::cout << "������ ������" << std::endl;
					i--;
					break;
				}

				break;
			}
		}





		system("pause");
		system("cls");
	}

}
*/