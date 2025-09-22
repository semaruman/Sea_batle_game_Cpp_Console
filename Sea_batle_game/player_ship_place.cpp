#include <iostream>
#include <conio.h>
#include <string>
#define MESSAGE "Некорректное расположение корабля!!!"

#define SIZE_FIELD 10
#define SHEEP_SIZE 20

namespace play {
	char transform_char(int symbol)
	{
		if (symbol == 0) return char(32);
		else if (symbol == 1) return char(176);
		else if (symbol == 2) return char(177);
	}

	void reset_array(int arr[])
	{
		for (int i = 0; i < 100; i++)
		{
			arr[i] = 0;
		}
	}

	void copy_array(int arr_1[], int arr_2[])
	{
		for (int i = 0; i < 100; i++) arr_1[i] = arr_2[i];
	}

	void print_toplane()
	{
		std::cout << char(218);
		for (int i = 0; i < 9; i++)
		{
			std::cout << char(196) << char(196) << char(196) << char(194);
		}
		std::cout << char(196) << char(196) << char(196) << char(191) << std::endl;
	}

	void print_divideline()
	{
		std::cout << char(195);
		for (int i = 0; i < 9; i++)
		{
			std::cout << char(196) << char(196) << char(196) << char(197);
		}
		std::cout << char(196) << char(196) << char(196) << char(180) << std::endl;
	}

	void print_cellline()
	{
		std::cout << char(179);
	}

	void print_bottomline()
	{
		std::cout << char(192);
		for (int i = 0; i < 9; i++)
		{
			std::cout << char(196) << char(196) << char(196) << char(193);
		}
		std::cout << char(196) << char(196) << char(196) << char(217) << std::endl;
	}

	void print_col_name()
	{
		setlocale(LC_ALL, "rus");
		std::string name_col = "АБВГДЕЖЗИК";

		for (int i = 0; i < SIZE_FIELD; i++)
		{
			std::cout << char(32) << char(32) << name_col[i] << char(32);
		}
		std::cout << std::endl;
		setlocale(LC_ALL, "C");
	}

	void control_panel()
	{
		setlocale(LC_ALL, "rus");
		std::cout << "\n\nУправление:\n";
		std::cout << "\tW - сместить корабль вверх\n";
		std::cout << "\tS - сместить корабль вниз\n";
		std::cout << "\tA - сместить корабль влево\n";
		std::cout << "\tD - сместить корабль вправо\n";
		std::cout << "\tR - развернуть корабль\n";
		std::cout << "\tF - подтвердить расположение корабля\n";
	}

	void print_field(int tmp_field[])
	{
		setlocale(LC_ALL, "rus");
		std::cout << "\n\n\tРасставьте ваши корабли\n\n";
		setlocale(LC_ALL, "C");

		int count{ 0 };
		print_col_name();
		print_toplane();

		for (int i = 1; i <= SIZE_FIELD; i++)
		{
			if (i < SIZE_FIELD)
			{
				for (int k = 1; k <= SIZE_FIELD; k++)
				{

					print_cellline();
					std::cout << char(32) << transform_char(tmp_field[count++]) << char(32);

				}
				print_cellline();
				std::cout << char(32) << i << std::endl;
				print_divideline();
			}

			else
			{
				for (int k = 1; k <= SIZE_FIELD; k++)
				{

					print_cellline();
					std::cout << char(32) << transform_char(tmp_field[count++]) << char(32);

				}
				print_cellline();
				std::cout << char(32) << i << std::endl;
			}
		}
		print_bottomline();
		control_panel();
	}

	void print_ship_place(int player_coords[2][SHEEP_SIZE])
	{
		for (int i = 0; i < SHEEP_SIZE; i++)
		{
			std::cout << player_coords[0][i] << "\t" << player_coords[1][i] << std::endl;
		}
	}

	void add_occup_cell(int occup_cells[], int cell)
	{
		if (cell == 0)
		{
			occup_cells[cell] = 1;
			occup_cells[cell + 1] = 1;
			occup_cells[cell + 10] = 1;
			occup_cells[cell + 11] = 1;
		}

		else if (cell > 0 && cell < 9)
		{
			occup_cells[cell] = 1;
			occup_cells[cell + 1] = 1;
			occup_cells[cell - 1] = 1;
			occup_cells[cell + 10] = 1;
			occup_cells[cell + 11] = 1;
			occup_cells[cell + 9] = 1;
		}

		else if (cell == 9)
		{
			occup_cells[cell] = 1;
			occup_cells[cell - 1] = 1;
			occup_cells[cell + 10] = 1;
			occup_cells[cell + 9] = 1;
		}

		else if (cell > 0 && cell < 90 && cell % 10 == 0)
		{
			occup_cells[cell] = 1;
			occup_cells[cell - 10] = 1;
			occup_cells[cell - 9] = 1;
			occup_cells[cell + 1] = 1;
			occup_cells[cell + 10] = 1;
			occup_cells[cell + 11] = 1;
		}

		else if (cell > 9 && cell < 90 && cell % 10 == 9)
		{
			occup_cells[cell] = 1;
			occup_cells[cell - 10] = 1;
			occup_cells[cell - 11] = 1;
			occup_cells[cell - 1] = 1;
			occup_cells[cell + 9] = 1;
			occup_cells[cell + 10] = 1;
		}

		else if (cell == 90)
		{
			occup_cells[cell] = 1;
			occup_cells[cell - 10] = 1;
			occup_cells[cell - 9] = 1;
			occup_cells[cell + 1] = 1;
		}

		else if (cell > 90 && cell < 99)
		{
			occup_cells[cell] = 1;
			occup_cells[cell - 1] = 1;
			occup_cells[cell - 11] = 1;
			occup_cells[cell - 10] = 1;
			occup_cells[cell - 9] = 1;
			occup_cells[cell + 1] = 1;
		}

		else if (cell == 99)
		{
			occup_cells[cell] = 1;
			occup_cells[cell - 10] = 1;
			occup_cells[cell - 11] = 1;
			occup_cells[cell - 1] = 1;
		}

		else
		{
			occup_cells[cell] = 1;
			occup_cells[cell - 11] = 1;
			occup_cells[cell - 10] = 1;
			occup_cells[cell - 9] = 1;
			occup_cells[cell - 1] = 1;
			occup_cells[cell + 1] = 1;
			occup_cells[cell + 9] = 1;
			occup_cells[cell + 10] = 1;
			occup_cells[cell + 11] = 1;
		}
	}

	bool check_occup_cells(int occup_cells[], int tmp_ship_place[])
	{
		bool status_cell = true;

		for (int i = 0; i < 100; i++)
		{
			if (tmp_ship_place[i] == 1)
			{
				if (occup_cells[i]) status_cell = false;
			}
		}

		return status_cell;
	}

	void change_tmp_field(int tmp_field[], int complite_field[], int tmp_ship_place[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			tmp_ship_place[i] = 1;
		}

		for (int i = 0; i < 100; i++)
		{
			tmp_field[i] = complite_field[i] + tmp_ship_place[i];
		}
	}


	void change_tmp_field(int choice, int tmp_field[], int complite_field[], int tmp_ship_place[], int len)
	{
		int tmp_array[100]{ 0 };

		reset_array(tmp_field);

		if (choice == 119 || choice == 230)//w
		{
			for (int i = 0; i < 100; i++)
			{
				if (tmp_ship_place[i] == 1)
				{
					if (tmp_ship_place[i + 1] != 1 && i > 9) {
						for (int k = 0; k < len; k++)
						{
							tmp_array[(i + (k * 10)) - 10] = 1;
						}
						break;
					}
					else if (tmp_ship_place[i + 1] == 1 && i > 9)
					{
						for (int k = 0; k < len; k++)
						{
							tmp_array[(i + k) - 10] = 1;
						}
						break;
					}
					else
					{
						copy_array(tmp_array, tmp_ship_place);
						break;
					}
				}
			}
			reset_array(tmp_ship_place);
			copy_array(tmp_ship_place, tmp_array);
			for (int i = 0; i < 100; i++)
			{
				tmp_field[i] = complite_field[i] + tmp_ship_place[i];
			}
			reset_array(tmp_array);
		}
		else if (choice == 115 || choice == 235)//s
		{
			for (int i = 0; i < 100; i++)
			{
				if (tmp_ship_place[i] == 1)
				{
					if (tmp_ship_place[i + 1] != 1 && i < (100 - (len * 10)))
					{
						for (int k = 0; k < len; k++)
						{
							tmp_array[(i + (k * 10)) + 10] = 1;
						}
						break;
					}
					else if (tmp_ship_place[i + 1] == 1 && i < 90)
					{
						for (int k = 0; k < len; k++)
						{
							tmp_array[(i + k) + 10] = 1;
						}
						break;
					}
					else
					{
						copy_array(tmp_array, tmp_ship_place);
						break;
					}
				}
			}
			reset_array(tmp_ship_place);
			copy_array(tmp_ship_place, tmp_array);
			for (int i = 0; i < 100; i++)
			{
				tmp_field[i] = complite_field[i] + tmp_ship_place[i];
			}
			reset_array(tmp_array);
		}
		else if (choice == 97 || choice == 228)//a
		{
			for (int i = 0; i < 100; i++)
			{
				if (tmp_ship_place[i] == 1)
				{
					if (tmp_ship_place[i + 1] != 1 && i % 10 != 0) {
						for (int k = 0; k < len; k++)
						{
							tmp_array[(i + (k * 10)) - 1] = 1;
						}
						break;
					}
					else if (tmp_ship_place[i + 1] == 1 && i % 10 != 0)
					{
						for (int k = 0; k < len; k++)
						{
							tmp_array[(i + k) - 1] = 1;
						}
						break;
					}
					else
					{
						copy_array(tmp_array, tmp_ship_place);
						break;
					}
				}
			}
			reset_array(tmp_ship_place);
			copy_array(tmp_ship_place, tmp_array);
			for (int i = 0; i < 100; i++)
			{
				tmp_field[i] = complite_field[i] + tmp_ship_place[i];
			}
			reset_array(tmp_array);
		}
		else if (choice == 100 || choice == 162)//d
		{
			for (int i = 0; i < 100; i++)
			{
				if (tmp_ship_place[i] == 1)
				{
					if (tmp_ship_place[i + 1] != 1 && i % 10 != 9) {
						for (int k = 0; k < len; k++)
						{
							tmp_array[(i + (k * 10)) + 1] = 1;
						}
						break;
					}
					else if (tmp_ship_place[i + 1] == 1 && (i + (len - 1)) % 10 != 9)
					{
						for (int k = 0; k < len; k++)
						{
							tmp_array[(i + k) + 1] = 1;
						}
						break;
					}
					else
					{
						copy_array(tmp_array, tmp_ship_place);
						break;
					}
				}
			}
			reset_array(tmp_ship_place);
			copy_array(tmp_ship_place, tmp_array);
			for (int i = 0; i < 100; i++)
			{
				tmp_field[i] = complite_field[i] + tmp_ship_place[i];
			}
			reset_array(tmp_array);
		}
		else if (choice == 114 || choice == 170)//r
		{
			for (int i = 0; i < 100; i++)
			{
				if (tmp_ship_place[i] == 1)
				{
					if (tmp_ship_place[i + 1] == 1 && i < (100 - ((len - 1) * 10)))
					{
						for (int k = 0; k < len; k++)
						{
							tmp_array[i + (k * 10)] = 1;
						}
						break;
					}
					else if (tmp_ship_place[i + 1] != 1 && (i % 10) < (10 - (len - 1)))
					{
						for (int k = 0; k < len; k++)
						{
							tmp_array[i + k] = 1;
						}
						break;
					}
					else
					{
						copy_array(tmp_array, tmp_ship_place);
						break;
					}
				}
			}
			reset_array(tmp_ship_place);
			copy_array(tmp_ship_place, tmp_array);
			for (int i = 0; i < 100; i++)
			{
				tmp_field[i] = complite_field[i] + tmp_ship_place[i];
			}
			reset_array(tmp_array);
		}
		else
		{
			copy_array(tmp_array, tmp_ship_place);
			reset_array(tmp_ship_place);
			copy_array(tmp_ship_place, tmp_array);
			for (int i = 0; i < 100; i++)
			{
				tmp_field[i] = complite_field[i] + tmp_ship_place[i];
			}
			reset_array(tmp_array);
		}
	}

	void confirm_place(int complite_field[], int tmp_ship_place[], int player_coords[2][SHEEP_SIZE], int occup_cells[])
	{
		static int count{ 0 };

		for (int i = 0; i < 100; i++)
		{
			if (tmp_ship_place[i] != 0) complite_field[i] = tmp_ship_place[i];
		}

		for (int i = 0; i < 100; i++)
		{
			if (tmp_ship_place[i] == 1)
			{
				player_coords[0][count] = i / 10;
				player_coords[1][count++] = i % 10;
				add_occup_cell(occup_cells, i);
			}
		}
		if (count == 20) count = 0;

		reset_array(tmp_ship_place);

	}

	void player_ship_place(int player_coords[2][SHEEP_SIZE])
	{
		setlocale(LC_ALL, "C");

		int tmp_field[100]{ 0 };
		int complite_field[100]{ 0 };
		int tmp_ship_place[100]{ 0 };
		int occup_cells[100]{ 0 };
		int ships[10]{ 4,3,3,2,2,2,1,1,1,1 };
		int choice;

		for (int i = 0; i < (SHEEP_SIZE / 2); i++)
		{
			bool flag{ false };
			change_tmp_field(tmp_field, complite_field, tmp_ship_place, ships[i]);
			do {
				system("cls");
				print_field(tmp_field);
				choice = _getch();
				change_tmp_field(choice, tmp_field, complite_field, tmp_ship_place, ships[i]);
				if (choice == 102 || choice == 160)
				{
					if (check_occup_cells(occup_cells, tmp_ship_place))
					{
						flag = true;
						confirm_place(complite_field, tmp_ship_place, player_coords, occup_cells);
					}
					else
					{
						std::cout << std::endl << MESSAGE << std::endl;
						system("pause");
					}
				}

			} while (!flag);

		}


		setlocale(LC_ALL, "rus");
	}
}



