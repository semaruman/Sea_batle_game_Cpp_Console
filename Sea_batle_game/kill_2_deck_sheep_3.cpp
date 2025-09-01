#include <iostream>
#include "CONSTANTS.h"


bool kill_2_deck_sheep_3(int coords_matrix[2][SHEEP_SIZE]) {
    if (coords_matrix[0][14] == INT_MIN && coords_matrix[0][15] == INT_MIN) {
        return true;
    }
    return false;
}
