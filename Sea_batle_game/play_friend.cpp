#include <iostream>
#include "player_motion.h"
#include "computer_motion.h"
#include "CONSTANTS.h"
#include "coord_in.h"
#include "player_ship_place.h"
#include "player_win.h"
#include "computer_win.h"
#include "computer_ship_place.h"
#include "computer_pole.h"
#include "player_pole.h"
#include "print_poles.h"
#include "database.h"
#include "draw_count_ships.h"
#include "console_clear.h"

// ��������� ������� ��� ������ �����
void friend_print_poles(char PL_POLE[FIELD_SIZE][FIELD_SIZE], char COMP_POLE[FIELD_SIZE][FIELD_SIZE]) {
	//----- ����� ������� ������ �������� �����������
	std::cout << "  ";
	for (int i = 0;i < FIELD_SIZE;i++) {
		std::cout << i << " ";
	}
	std::cout << "\t | \t";
	std::cout << "  ";
	for (int i = 0;i < FIELD_SIZE;i++) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	//-----


	//----- ����� ���� ����� ������������
	for (int i = 0; i < FIELD_SIZE; i++) {

		std::cout << i << " ";
		for (int j = 0;j < FIELD_SIZE; j++) {
			std::cout << PL_POLE[i][j] << " ";
		}
		std::cout << "\t | \t";

		std::cout << i << " ";
		for (int j = 0;j < FIELD_SIZE; j++) {
			std::cout << COMP_POLE[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

namespace play {
	const char* play_friend() {

		//�������� ���� ��� �������� ��� �����������������
		char FIRST_PLAYER_POLE[FIELD_SIZE][FIELD_SIZE] = {
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
		};
		char SECOND_PLAYER_POLE[FIELD_SIZE][FIELD_SIZE] = {
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
		};
		//-------------------------------------

		// �������� ������ �� ���� �������� = 20 (� ������� ������)
		int PLAYER_HP = SHEEP_SIZE, COMPUTER_HP = SHEEP_SIZE; // ������������� ������ ������ � ����������
		int hit_counter; // ������� �����

		std::cout << "����� 1:" << std::endl;
		int player_sheeps[2][SHEEP_SIZE]; play::player_ship_place(player_sheeps); // ����������� �������� ������ 1 � ������ ���� ��������� � ����������
		console_clear();
		std::cout << "����� 2:" << std::endl;
		
		int second_player_sheeps[2][SHEEP_SIZE]; play::player_ship_place(second_player_sheeps); // ����������� �������� ������ 2 � ������ ���� ��������� � ����������


		while (PLAYER_HP > 0 && COMPUTER_HP > 0) {

			hit_counter = COUNT_MOTIONS;
			while (hit_counter > 0) {
				std::cout << "��� ������ 1:" << std::endl;

				hit_counter -= COUNT_MOTIONS; // -1
				int* temp_array = play::player_motion(); // ��� ������

				if (coord::coord_in(temp_array, second_player_sheeps)) { //���� ����� �����, 
					//�� ���������� ����� ������������ � ���������� ���������� ��������� �� ���� ����������
					hit_counter += COUNT_MOTIONS;

					SECOND_PLAYER_POLE[temp_array[0]][temp_array[1]] = 'X';

					console_clear();
					friend_print_poles(FIRST_PLAYER_POLE, SECOND_PLAYER_POLE);

					COMPUTER_HP -= 1;


					draw_count_ships(player_sheeps, second_player_sheeps);
					std::cout << std::endl;
					std::cout << "GOOOOOOOOOOOOOOOOOOOOOOOOOOOOl!!!" << std::endl;
				}
				else { //�����, ���� �� �����, ���������� ���������� �������

					SECOND_PLAYER_POLE[temp_array[0]][temp_array[1]] = '0';

					console_clear();
					friend_print_poles(FIRST_PLAYER_POLE, SECOND_PLAYER_POLE);

					draw_count_ships(player_sheeps, second_player_sheeps);
					std::cout << std::endl;
					
				}


				//��������, ������� �� �����
				if (player_win(second_player_sheeps)) {
					const char* res = "����� 1 ������� ������ 2!";
					add_to_database(res);
					return res;
				}
			}

			hit_counter = COUNT_MOTIONS;
			while (hit_counter > 0) {
				std::cout << "��� ������ 2:" << std::endl;
				hit_counter -= COUNT_MOTIONS; // -1
				int* temp_array = play::player_motion(); // ��� ����������

				if (coord::coord_in(temp_array, player_sheeps)) { //���� ��������� �����, �� ���������� ����� ������������
					hit_counter += COUNT_MOTIONS;
					PLAYER_HP -= 1;

					FIRST_PLAYER_POLE[temp_array[0]][temp_array[1]] = 'X';

					console_clear();
					friend_print_poles(FIRST_PLAYER_POLE, SECOND_PLAYER_POLE);
					draw_count_ships(player_sheeps, second_player_sheeps);
					std::cout << std::endl;
				}
				else {

					FIRST_PLAYER_POLE[temp_array[0]][temp_array[1]] = '0';
					console_clear();
					friend_print_poles(FIRST_PLAYER_POLE, SECOND_PLAYER_POLE);
					draw_count_ships(player_sheeps, second_player_sheeps);
					std::cout << std::endl;
				}


				if (computer_win(player_sheeps)) {
					const char* res = "���� 2 ������� ������ 1!";
					add_to_database(res);
					return res;
				}
			}

		}
	}
}