#include <iostream>
#include "CONSTANTS.h"

bool kill_1_deck_sheep_2(int coords_matrix[2][SHEEP_SIZE]) {
    return coords_matrix[0][17] == INT_MIN;
}