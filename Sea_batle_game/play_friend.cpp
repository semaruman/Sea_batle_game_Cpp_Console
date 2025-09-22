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

// временная функция для вывода полей
void friend_print_poles(char PL_POLE[FIELD_SIZE][FIELD_SIZE], char COMP_POLE[FIELD_SIZE][FIELD_SIZE]) {
	//----- Вывод верхней строки числовых обозначений
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


	//----- Вывод двух полей одновременно
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

		//Создание поля для проверки его работоспособности
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

		// Суммарно клеток во всех кораблях = 20 (у каждого игрока)
		int PLAYER_HP = SHEEP_SIZE, COMPUTER_HP = SHEEP_SIZE; // распределение клеток игроку и компьютеру
		int hit_counter; // счётчик ходов

		std::cout << "Игрок 1:" << std::endl;
		int player_sheeps[2][SHEEP_SIZE]; play::player_ship_place(player_sheeps); // расстановка кораблей игрока 1 и запись всех координат в переменную
		console_clear();
		std::cout << "Игрок 2:" << std::endl;
		
		int second_player_sheeps[2][SHEEP_SIZE]; play::player_ship_place(second_player_sheeps); // расстановка кораблей игрока 2 и запись всех координат в переменную


		while (PLAYER_HP > 0 && COMPUTER_HP > 0) {

			hit_counter = COUNT_MOTIONS;
			while (hit_counter > 0) {
				std::cout << "Ход игрока 1:" << std::endl;

				hit_counter -= COUNT_MOTIONS; // -1
				int* temp_array = play::player_motion(); // ход игрока

				if (coord::coord_in(temp_array, second_player_sheeps)) { //если игрок попал, 
					//то количество ходов прибавляется и координата отмечается крестиком на поле компьютера
					hit_counter += COUNT_MOTIONS;

					SECOND_PLAYER_POLE[temp_array[0]][temp_array[1]] = 'X';

					console_clear();
					friend_print_poles(FIRST_PLAYER_POLE, SECOND_PLAYER_POLE);

					COMPUTER_HP -= 1;


					draw_count_ships(player_sheeps, second_player_sheeps);
					std::cout << std::endl;
					std::cout << "GOOOOOOOOOOOOOOOOOOOOOOOOOOOOl!!!" << std::endl;
				}
				else { //иначе, если не попал, координата отмечается ноликом

					SECOND_PLAYER_POLE[temp_array[0]][temp_array[1]] = '0';

					console_clear();
					friend_print_poles(FIRST_PLAYER_POLE, SECOND_PLAYER_POLE);

					draw_count_ships(player_sheeps, second_player_sheeps);
					std::cout << std::endl;
					
				}


				//Проверка, победил ли игрок
				if (player_win(second_player_sheeps)) {
					const char* res = "Игрок 1 победил игрока 2!";
					add_to_database(res);
					return res;
				}
			}

			hit_counter = COUNT_MOTIONS;
			while (hit_counter > 0) {
				std::cout << "Ход игрока 2:" << std::endl;
				hit_counter -= COUNT_MOTIONS; // -1
				int* temp_array = play::player_motion(); // ход компьютера

				if (coord::coord_in(temp_array, player_sheeps)) { //если компьютер попал, то количество ходов прибавляется
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
					const char* res = "Ирок 2 победил игрока 1!";
					add_to_database(res);
					return res;
				}
			}

		}
	}
}