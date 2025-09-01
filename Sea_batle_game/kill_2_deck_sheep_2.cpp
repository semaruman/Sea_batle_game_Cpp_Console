#include <iostream>
#include "CONSTANTS.h"

bool kill_2_deck_sheep_2(int coords_matrix[2][SHEEP_SIZE]) {
    if (coords_matrix[0][12] == INT_MIN && coords_matrix[0][13] == INT_MIN) {
        return true;
    }
    return false;
}