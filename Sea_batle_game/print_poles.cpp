#include <iostream>
#include "CONSTANTS.h"
#include "player_pole.h"
#include "computer_pole.h"

namespace pole { 

	void print_poles() { // Функция отвечает за вывод игровых полей игрока и компьютера

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
				std::cout << PLAYER_POLE.POLE[i][j] << " ";
			}
			std::cout << "\t | \t";

			std::cout << i << " ";
			for (int j = 0;j < FIELD_SIZE; j++) {
				std::cout << COMPUTER_POLE.POLE[i][j] << " ";
			}
			std::cout << std::endl;
		}

	}
}