#include <iostream>
#include "CONSTANTS.h"
#include "kill_1_deck_sheep_1.h"
#include "kill_1_deck_sheep_2.h"
#include "kill_1_deck_sheep_3.h"
#include "kill_1_deck_sheep_4.h"
#include "kill_2_deck_sheep_1.h"
#include "kill_2_deck_sheep_2.h"
#include "kill_2_deck_sheep_3.h"
#include "kill_3_deck_sheep_1.h"
#include "kill_3_deck_sheep_2.h"
#include "kill_linkor_sheep.h"


void draw_count_ships(int first_coords_matrix[2][SHEEP_SIZE], int second_coords_matrix[2][SHEEP_SIZE])
{
	int count_first{ 0 }, count_second{ 0 };

	std::cout << "������� ������ 1:" << "\t������� ������ 2:" << std::endl;

	if (!kill_1_deck_sheep_1(first_coords_matrix)) count_first++;
	if (!kill_1_deck_sheep_2(first_coords_matrix)) count_first++;
	if (!kill_1_deck_sheep_3(first_coords_matrix)) count_first++;
	if (!kill_1_deck_sheep_4(first_coords_matrix)) count_first++;
	if (!kill_1_deck_sheep_1(second_coords_matrix)) count_second++;
	if (!kill_1_deck_sheep_2(second_coords_matrix)) count_second++;
	if (!kill_1_deck_sheep_3(second_coords_matrix)) count_second++;
	if (!kill_1_deck_sheep_4(second_coords_matrix)) count_second++;
	std::cout << "������������: " << count_first << "\t\t������������: " << count_second << std::endl;
	count_first = 0;
	count_second = 0;

	if (!kill_2_deck_sheep_1(first_coords_matrix)) count_first++;
	if (!kill_2_deck_sheep_2(first_coords_matrix)) count_first++;
	if (!kill_2_deck_sheep_3(first_coords_matrix)) count_first++;
	if (!kill_2_deck_sheep_1(second_coords_matrix)) count_second++;
	if (!kill_2_deck_sheep_2(second_coords_matrix)) count_second++;
	if (!kill_2_deck_sheep_3(second_coords_matrix)) count_second++;
	std::cout << "������������: " << count_first << "\t\t������������: " << count_second << std::endl;
	count_first = 0;
	count_second = 0;

	if (!kill_3_deck_sheep_1(first_coords_matrix)) count_first++;
	if (!kill_3_deck_sheep_2(first_coords_matrix)) count_first++;
	if (!kill_3_deck_sheep_1(second_coords_matrix)) count_second++;
	if (!kill_3_deck_sheep_2(second_coords_matrix)) count_second++;
	std::cout << "������������: " << count_first << "\t\t������������: " << count_second << std::endl;
	count_first = 0;
	count_second = 0;

	if (!kill_linkor_sheep(first_coords_matrix)) count_first++;
	if (!kill_linkor_sheep(second_coords_matrix)) count_second++;
	std::cout << "���������������: " << count_first << "\t���������������: " << count_second << std::endl;
}
