#include <iostream>
#include "player_menu.h"
#include "CONSTANTS.h"

int main() {
	// ----- Подключение важных для программы вещей -----
	system("cls");
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	// -----*****-----

	// ----- Непосредственно игра -----
	menu::menu();
	
}