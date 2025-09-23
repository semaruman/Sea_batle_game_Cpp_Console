#pragma once
inline void print_array(int motion_array[2][100]) {

	for (int i = 0; i < 100; i++) {
		std::cout << "X=" <<motion_array[0][i] << ", " << motion_array[1][i] << std::endl;
	}
} 