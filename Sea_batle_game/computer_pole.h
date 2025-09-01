#pragma once

#include <iostream>
#include "CONSTANTS.h"

namespace pole {
	struct computer_pole
	{

		char POLE[FIELD_SIZE][FIELD_SIZE] = {
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

		void draw_computer_pole() {
			for (int i = 0; i < FIELD_SIZE; i++) {
				for (int j = 0; j < FIELD_SIZE; j++) {
					std::cout << POLE[i][j] << " ";
				}
				std::cout << std::endl;
			}
		}
	};
}

static pole::computer_pole COMPUTER_POLE;