#pragma once
#include <iostream>

inline void console_clear() {
	char temp[255];
	std::cout << "������� ���-������ ��� ������� �������..." << std::endl;
	std::cin >> temp;
	system("cls");
}