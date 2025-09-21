#include <iostream>
#include "CONSTANTS.h"

namespace play {
	bool computer_win(int player_coords[coords][SHEEP_SIZE]) // функция проверяет, победил ли компьютер
	{
		int counter = 0;

		for (int i = 0; i < coords; i++)
		{
			for (int j = 0; j < SHEEP_SIZE; j++)
			{
				if (player_coords[i][j] == INT_MIN)
				{
					counter++;
				}
			}
		}

		if (counter == (coords * SHEEP_SIZE))
		{
			return true;
		}

		return false;
	}
}