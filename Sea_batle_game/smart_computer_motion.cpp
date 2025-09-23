#include <iostream>

int* smart_computer_motion(bool popal = false) {

	static int motion_counter = 0;

	int res_array[2];
	static int motion_array[2][100]{
		{0,1,2,3,4,5,6,7,8,9 ,9,8,7,6,5,4,3,2,1,0 ,0,0,0,0,0,0,0,0 ,1,1,1,1,1,1,1,1 ,2,2,2,2,2,2,2,2 ,3,3,3,3,3,3,3,3 ,4,4,4,4,4,4,4,4 ,5,5,5,5,5,5,5,5 ,6,6,6,6,6,6,6,6 ,7,7,7,7,7,7,7,7 ,8,8,8,8,8,8,8,8 ,9,9,9,9,9,9,9,9},
		{0,1,2,3,4,5,6,7,8,9 ,0,1,2,3,4,5,6,7,8,9 ,1,2,3,4,5,6,7,8 ,0,2,3,4,5,6,7,9 ,0,1,3,4,5,6,8,9 ,0,1,2,3,5,7,8,9 ,0,1,2,3,4,7,8,9 ,0,1,2,3,6,7,8,9 ,0,1,2,4,5,7,8,9 ,0,1,3,4,5,6,8,9 ,0,2,3,4,5,6,7,9 ,1,2,3,4,5,6,7,8}
	};

	static int motion_array_2[2][100]{
		{0,2,4,6,8 ,1,3,5,7,9 ,0,2,4,6,8 ,1,3,5,7,9 ,0,2,4,6,8 ,1,3,5,7,9 ,0,2,4,6,8 ,1,3,5,7,9 ,0,2,4,6,8 ,1,3,5,7,9, 1,3,5,7,9 ,0,2,4,6,8 ,1,3,5,7,9 ,0,2,4,6,8 ,1,3,5,7,9 ,0,2,4,6,8 ,1,3,5,7,9 ,0,2,4,6,8 ,1,3,5,7,9 ,0,2,4,6,8 },
		{0,0,0,0,0 ,1,1,1,1,1 ,2,2,2,2,2 ,3,3,3,3,3 ,4,4,4,4,4 ,5,5,5,5,5 ,6,6,6,6,6 ,7,7,7,7,7 ,8,8,8,8,8 ,9,9,9,9,9, 0,0,0,0,0 ,1,1,1,1,1 ,2,2,2,2,2 ,3,3,3,3,3 ,4,4,4,4,4 ,5,5,5,5,5 ,6,6,6,6,6 ,7,7,7,7,7 ,8,8,8,8,8 ,9,9,9,9,9}
	};

	static int array_counter = 0;
	static int array[2][4]{
		{-1, 1, 0, 0},
		{0, 0, -1, 1}
	};
	if (!popal && array_counter == 0) {
		res_array[0] = motion_array[0][motion_counter];
		res_array[1] = motion_array[1][motion_counter];
		motion_counter++;
	}
	else {
		if (array_counter > 3) {
			array_counter = 0;
			motion_counter++;
		}
		while (true) {
			if (
				motion_array[0][motion_counter] + array[0][array_counter] >= 0 &&
				motion_array[0][motion_counter] + array[0][array_counter] <= 9 &&
				motion_array[1][motion_counter] + array[1][array_counter] >= 0 &&
				motion_array[1][motion_counter] + array[1][array_counter] <= 9)
			{
				res_array[0] = motion_array[0][motion_counter] + array[0][array_counter];
				res_array[1] = motion_array[1][motion_counter] + array[1][array_counter];
				array_counter++;
				break;
			}
			else {
				array_counter++;
				motion_counter++;
			}
		}

	}


	return res_array;
}
/*

если (компьютер попал){
	то начинает обстреливать соседние координаты
	try{

	}
	1) [i-1][j]
	2) [i+1][j]
	3) [i][j-1]
	4) [i][j+1]
}


8
*/
