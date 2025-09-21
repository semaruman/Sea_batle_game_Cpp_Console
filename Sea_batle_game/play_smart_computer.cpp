#include <iostream>
#include "CONSTANTS.h"
/*
#include "player_motion.h"
#include "computer_motion.h"
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
*/

namespace play {
	void play_smart_computer() {
		
		char SMART_PL_POLE[FIELD_SIZE][FIELD_SIZE] = {
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

		char SMART_COMP_POLE[FIELD_SIZE][FIELD_SIZE] = {
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

		int SMART_PLAYER_HP = SHEEP_SIZE, SMART_COMPUTER_HP = SHEEP_SIZE; // распределение клеток игроку и компьютеру
		int smart_hit_counter; // счётчик ходов

		while (SMART_PLAYER_HP > 0 && SMART_COMPUTER_HP > 0) {

			smart_hit_counter = COUNT_MOTIONS;

			while (smart_hit_counter > 0) {

				smart_hit_counter -= COUNT_MOTIONS; // -1
				//int* smart_temp_array = play::player_motion(); // ход игрока
			}
		}
	}
}