#include <iostream>
#include "CONSTANTS.h"

namespace coord {

	// ������� ��� ��������, ����� �� ����� �� ������� ��� ���
	// ��� �������� ���: ���� ���������� ���� ��������� � ������� �� ��������� ������� ����������,
	// �� ����� ����� => return true; ����� (���� �� �����) => return false;
	bool coord_in(int* coords, int computer_sheep_coords[2][SHEEP_SIZE]) { 
		
		bool flag = false;
		for (int i = 0;i < SHEEP_SIZE;i++) {
			if (coords[0] == computer_sheep_coords[0][i] && coords[1] == computer_sheep_coords[1][i]) {
				flag = true;
				computer_sheep_coords[0][i] = INT_MIN; // ���������� ���������� X �� ������
				computer_sheep_coords[1][i] = INT_MIN; // ���������� ���������� Y �� ������
				break;
			}
		}
		return flag;
	}
}