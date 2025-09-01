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
#include "print_poles.h"

// временная функция для вывода полей
void temp_print_poles(char PL_POLE[FIELD_SIZE][FIELD_SIZE], char COMP_POLE[FIELD_SIZE][FIELD_SIZE]) {
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
	const char* play_stuped_computer() {

		//Создание поля для проверки его работоспособности
		char PL_POLE[FIELD_SIZE][FIELD_SIZE] = {
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
		char COMP_POLE[FIELD_SIZE][FIELD_SIZE] = {
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
		int seconds = 0;

		// Суммарно клеток во всех кораблях=20 (у одного игрока)
		int PLAYER_HP = SHEEP_SIZE, COMPUTER_HP = SHEEP_SIZE; // распределение клеток игроку и компьютеру
		int hit_counter; // счётчик ходов


		int player_sheeps[2][SHEEP_SIZE]; play::player_ship_place(player_sheeps); // расстановка кораблей игрока и запись всех координат в переменную
		int computer_sheeps[2][SHEEP_SIZE]; play::computer_ship_place(computer_sheeps); // расстановка кораблей компьютера и запись всех координат в переменную


		while (PLAYER_HP > 0 && COMPUTER_HP > 0) {

			hit_counter = COUNT_MOTIONS;
			while (hit_counter > 0) {

				//pole::print_poles(); // вывод поля //-----------TEMP-------------
				//temp_print_poles(PL_POLE, COMP_POLE);

				draw_count_ships(player_sheeps, computer_sheeps);
				std::cout << std::endl;

				hit_counter -= COUNT_MOTIONS; // -1
				int* temp_array = play::player_motion(); // ход игрока

				if (coord::coord_in(temp_array,computer_sheeps)) { //если игрок попал, 
					//то количество ходов прибавляется и координата отмечается крестиком на поле компьютера
					hit_counter += COUNT_MOTIONS;

					//COMPUTER_POLE.POLE[temp_array[0]][temp_array[1]] = 'X'; //-----------TEMP-------------
					//pole::print_poles(); // вывод поля

					COMP_POLE[temp_array[0]][temp_array[1]] = 'X';
					temp_print_poles(PL_POLE, COMP_POLE);

					COMPUTER_HP -= 1;

					

					draw_count_ships(player_sheeps, computer_sheeps);
					std::cout << std::endl;
				}
				else { //иначе, если не попал, координата отмечается ноликом

					//COMPUTER_POLE.POLE[temp_array[0]][temp_array[1]] = '0'; //-----------TEMP-------------
					//pole::print_poles(); // вывод поля

					COMP_POLE[temp_array[0]][temp_array[1]] = '0';
					temp_print_poles(PL_POLE, COMP_POLE);

					draw_count_ships(player_sheeps, computer_sheeps);
					std::cout << std::endl;
				}

				//Проверка, победил ли игрок
				if (player_win(computer_sheeps)) {
					const char* res = "Игрок победил!";
					add_to_database(res);
					return res;
				}
			}

			hit_counter = COUNT_MOTIONS;
			while (hit_counter > 0) {
				hit_counter -= COUNT_MOTIONS; // -1
				int* temp_array = play::computer_motion(); // ход компьютера

				if (coord::coord_in(temp_array, player_sheeps)) { //если компьютер попал, то количество ходов прибавляется
					hit_counter += COUNT_MOTIONS;
					PLAYER_HP -= 1;

					//PLAYER_POLE.POLE[temp_array[0]][temp_array[1]] = 'X'; //-----------TEMP-------------
					//pole::print_poles(); // вывод поля

					PL_POLE[temp_array[0]][temp_array[1]] = 'X';
					temp_print_poles(PL_POLE, COMP_POLE);

					draw_count_ships(player_sheeps, computer_sheeps);
					std::cout << std::endl;
				}
				else {

					//PLAYER_POLE.POLE[temp_array[0]][temp_array[1]] = '0'; //-----------TEMP-------------
					//pole::print_poles(); // вывод поля

					PL_POLE[temp_array[0]][temp_array[1]] = '0';
					temp_print_poles(PL_POLE, COMP_POLE);

					draw_count_ships(player_sheeps, computer_sheeps);
					std::cout << std::endl;
				}

				if (computer_win(player_sheeps)) {
					const char* res = "Компьютер победил!";
					add_to_database(res);
					return res;
				}
			}

		}
	}
}