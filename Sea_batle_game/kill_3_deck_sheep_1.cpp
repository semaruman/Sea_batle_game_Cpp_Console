#include <iostream>
#include "CONSTANTS.h"


bool kill_3_deck_sheep_1(int coords_matrix[2][SHEEP_SIZE]) {
    if (coords_matrix[0][4] == INT_MIN && coords_matrix[0][5] == INT_MIN && coords_matrix[0][6] == INT_MIN) {
        return true;

    }
    return false;
}
