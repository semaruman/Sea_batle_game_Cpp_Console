#include <iostream>
#include "CONSTANTS.h"

namespace play {
	bool player_win(int computer_coords[coords][SHEEP_SIZE])
	{
		int counter = 0;

		for (int i = 0; i < coords; i++)
		{
			for (int j = 0; j < SHEEP_SIZE; j++)
			{
				if (computer_coords[i][j] == INT_MIN)
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