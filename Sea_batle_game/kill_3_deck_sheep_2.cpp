#include <iostream>
#include "CONSTANTS.h"


bool kill_3_deck_sheep_2(int coords_matrix[2][SHEEP_SIZE]) {
    if (coords_matrix[0][7] == INT_MIN && coords_matrix[0][8] == INT_MIN && coords_matrix[0][9] == INT_MIN) {
        return true;
    }
    return false;
}
