#include <iostream>
#include "CONSTANTS.h"


bool kill_2_deck_sheep_1(int coords_matrix[2][SHEEP_SIZE]) {
    if (coords_matrix[0][10] == INT_MIN && coords_matrix[0][11] == INT_MIN) {
        return true;
    }
    return false;
}
