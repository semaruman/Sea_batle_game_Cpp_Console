/*

#include <iostream>
#include "CONSTANTS.h"
#include <string>



namespace play {
	void player_ship_place(int player_coords[2][SHEEP_SIZE])
	{
		//Задумка следующая:
		//Я задаю массив list_ships со списком размеров кораблей.
		//Цикл for идёт по этому массиву и в зависимости от значения элемента я буду попадать в 4 разных блока
		//инструкций, которые соответствуют размерности кораблей. Реализовано это через switch.
		//Внутри инструкции для конкретной размерности, в зависимости от порядкового номера текущего корабля,
		//я буду записывать введённые координаты в нужные столбцы массива player_coords.
		//Например, внутрь блока двухъярусных по моему массиву list_ships мы попадаем на итерациях i=3,4,5.
		//А координаты в массив player_coords нужно записать по столбцам с 10 по 15.
		//Поэтому внутри блока двухъярусных я задаю if(i==3), else if(i==4) и тд,
		//где обращаюсь к конкретным строкам и столбцам.

		//А вот для определения занятых и свободных клеток (включая дистанцию между кораблями)
		//я решил использовать отдельный массив free_cells, в который алгоритм обращается для проверки
		//введённых координат, прежде чем записать их в главный массив player_coords.
		//Изначально массив свободных клеток заполнен единицами (1 - клетка свободна, 0 - клетка занята), и по мере заполнения
		//поля кораблями, массив свободных клеток будет заполняться нулями.

		int list_ships[10]{ 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };//массив хранит все корабли по значению их ярусности
		int free_cells[100];//массив клеток поля для проверки свободны/заняты.

		//использую цикл для заполнения массива клеток единицами. Изначально поле пустое, а значит все свободно.
		for (int i = 0; i < 100; i++)
		{
			free_cells[i] = 1;
		}

		//главный цикл, которые проходит поочерёдно по 10 кораблям
		for (int i = 0; i < 10; i++)
		{
			std::string coord_1_beg_str, coord_2_beg_str, coord_1_end_str, coord_2_end_str;
			int coord_1_beg_int, coord_2_beg_int, coord_1_end_int, coord_2_end_int, tmp_coord_1_mid1, tmp_coord_2_mid1, tmp_coord_1_mid2, tmp_coord_2_mid2;

			//переменные прописываю вначале цикла, чтобы они пересоздавались вновь на каждой итерации
			//По условию, с клавиатуры вводятся только начало и конец корабля.
			//Для защиты от дурака я должен принимать эти значения в строковом виде, а потом переводить в тип инт с последующим отловом ошибок ввода.
			//Назначения переменных:
			//coord_1_beg_str, coord_1_beg_int - координата строки первой палубы корабля в строковом и интовом типе данных соответственно.
			//coord_2_beg_str, coord_2_beg_int - координата столбца первой палубы корабля в строковом и интовом типе данных соответственно.
			//coord_1_end_str, coord_1_end_int - координата строки последней палубы корабля в строковом и интовом типе данных соответственно.
			//coord_2_end_str, coord_2_end_int - координата столбца последней палубы корабля в строковом и интовом типе данных соответственно.
			//tmp_coord_1_mid1, tmp_coord_2_mid1 - не задаются с клавиатуры а лишь высчитываются, исходя из введённых координат первой/последней полуб, для записи одной промежуточной палубы.
			//tmp_coord_1_mid2, tmp_coord_2_mid2 - высчитываются алгоритмически для записи дополнительной палубы на основе введённых координат первой/последней. Используются в паре с предыдущими для описания четырёхъярусного.

			//использую свич для перебора размерностей корабля. case 4 - четырёхъярусный, case 3 - трёх и тд.
			switch (list_ships[i])
			{
			case 4:

				//по взаимодействию с пользователем в тз особо ничего не сказано, поэтому решил выводить в консоль сообщение о том, что сейчас нужно ввести.
				//ставлю в паузу и очищаю консоль только в самом конце работы функции, когда все корабли уже описаны.
				std::cout << "Введите номер строки для размещения первой палубы 4-х ярусного корабля: ";
				std::cin >> coord_1_beg_str;
				std::cout << "Введите номер столбца для размещения первой палубы 4-х ярусного корабля: ";
				std::cin >> coord_2_beg_str;

				//блок перевода в тип инт. Далее работаем только с переменными инт, которым присваивается значение введённых координат.
				try
				{
					coord_1_beg_int = stoi(coord_1_beg_str);
					coord_2_beg_int = stoi(coord_2_beg_str);
				}

				//если были буквы, то выводится сообщение об ошибке и нас откидывает на одну итерацию назад, где мы вновь попадаем в этот кейс, вводя координаты повторно.
				catch (...)
				{
					std::cout << "Некорректный ввод" << std::endl;
					i--;
					break;
				}

				//блок проверяет, чтобы значения координат были в диапазоне от 0 до 9. Иначе нас откидывает на одну итерацию назад.
				if (!(coord_1_beg_int >= 0 && coord_1_beg_int < 10 && coord_2_beg_int >= 0 && coord_2_beg_int < 10))
				{
					std::cout << "Введены некорректные координаты" << std::endl;
					i--;
					break;
				}

				//вводим координаты последней палубы с аналогичными проверками.
				std::cout << "Введите номер строки для размещения последней палубы 4-х ярусного корабля: ";
				std::cin >> coord_1_end_str;
				std::cout << "Введите номер столбца для размещения последней палубы 4-х ярусного корабля: ";
				std::cin >> coord_2_end_str;

				try
				{
					coord_1_end_int = stoi(coord_1_end_str);
					coord_2_end_int = stoi(coord_2_end_str);
				}

				catch (...)
				{
					std::cout << "Некорректный ввод" << std::endl;
					i--;
					break;
				}

				//тут я перестраховался и добавил блок, меняющий координаты первой и последней палубы на случай, если пользователь ввёл их в обратном порядке.
				if ((coord_1_beg_int * 10 + coord_2_beg_int) > (coord_1_end_int * 10 + coord_2_end_int))
				{
					int coord_1_tmp = coord_1_beg_int;
					int coord_2_tmp = coord_2_beg_int;
					coord_1_beg_int = coord_1_end_int;
					coord_2_beg_int = coord_2_end_int;
					coord_1_end_int = coord_1_tmp;
					coord_2_end_int = coord_2_tmp;
				}

				//тут мы проверяем свободны ли клетки начала и конца корабля из моего массива свободных клеток.
				//Если одна из палуб попадает на занятую клетку, то мы получаем сообщение об ошибке и нас отбрасывает на одну итерацию, где мы вновь вводим координаты.
				//Можно резонно заметить, что на момент описывания четырёхъярусного, всё поле ещё свободно и эта проверка излишня.
				//И это один из тех неоптимизированных моментов, о которых я упоминал в начале. Дело в том, что я описывал функцию снизу вверх,
				//начиная от однопалубных, где я копировал уже готовый кусок из кейса ниже и дополнял его проверками и условиями, необходимыми для корабля побольше.
				//Более того, код писался короткими сессиями на протяжении всех прошедших дней. И возвращаясь к написанию, бывало трудно разобраться в этом обилии условий.
				//К тому же, код получился трудночитаемым. Поэтому я старался не лезть туда, где всё работает, а просто оставлял готовые куски)
				if (free_cells[coord_1_beg_int * 10 + coord_2_beg_int] && free_cells[coord_1_end_int * 10 + coord_2_end_int]) {

					//тут проверка на расстояние между крайними клетками. Для удобства я перевожу координаты палуб в номера клеток по формуле (строка*10+столбец), где мы, например, при вводе (0, 1) (0, 4) получаем 1 и 4 клетки.
					//Для четырёхъярусного разница должна быть либо 3 клетки при горизонтальном расположении, либо 30 при вертикальном.
					//Если вдруг разница иная, то мы получаем сообщение об ошибке и, как мы уже привыкли, возвращаемся на итерацию назад.
					if (coord_1_end_int >= 0 && coord_1_end_int < 10 && coord_2_end_int >= 0 && coord_2_end_int < 10 && ((coord_1_end_int * 10 + coord_2_end_int) - (coord_1_beg_int * 10 + coord_2_beg_int) == 3 || (coord_1_end_int * 10 + coord_2_end_int) - (coord_1_beg_int * 10 + coord_2_beg_int) == 30))
					{
						//здесь нам нужно получить координаты 2 и 3 палуб.
						//Если координаты строки начала и конца одинаковы, то корабль горизонтален. И наоборот.
						//При горизонтальном у 2 и 3 палуб строка будет равна строке начала, а столбец +1 и +2 от начала соответственно. И наоборот.
						if (coord_1_beg_int == coord_1_end_int)
						{
							tmp_coord_1_mid1 = coord_1_beg_int;
							tmp_coord_1_mid2 = coord_1_beg_int;
							tmp_coord_2_mid1 = coord_2_beg_int + 1;
							tmp_coord_2_mid2 = coord_2_beg_int + 2;
						}
						else
						{
							tmp_coord_1_mid1 = coord_1_beg_int + 1;
							tmp_coord_1_mid2 = coord_1_beg_int + 2;
							tmp_coord_2_mid1 = coord_2_beg_int;
							tmp_coord_2_mid2 = coord_2_beg_int;
						}

						//все проверки на корректность были пройдены и тут мы записываем наконец все координаты в главный массив player_coords.
						player_coords[0][0] = coord_1_beg_int;
						player_coords[1][0] = coord_2_beg_int;
						player_coords[0][1] = tmp_coord_1_mid1;
						player_coords[1][1] = tmp_coord_2_mid1;
						player_coords[0][2] = tmp_coord_1_mid2;
						player_coords[1][2] = tmp_coord_2_mid2;
						player_coords[0][3] = coord_1_end_int;
						player_coords[1][3] = coord_2_end_int;


						//Но нужно ещё занятые клетки указать в массиве клеток free_cells. И это ужасный блок. Я постарался в целях экономии места написать в строку каждый блок if.
						//Получилось контринтуитивно и монструозно. Но удалось сэкономить строк 80 на каждой такой конструкции.
						//Клетка может быть расположена в 9 различных позициях на поле, при которых её окружает разное количество пустых клеток рядом. А как только мы что-то ставим на поле, все окружающие клетки становятся нам недоступны.
						//Необходимо обработать 4 угла, четыре грани поля, исключая углы, и все в диапазоне 1-8 для строк/столбцов (грубо говоря, центр поля).
						//В случае четырёхпалубных, я проставляю нули вокруг крайних палуб, что снимает необходимость делать то же и для 2-3 палуб.
						//А вот в случаях 2-х и 3-х палубных, Я использую идентичный алгоритм, который проходится повторно по одним и тем же клеткам. Что не влияет на результат, но не является оптимальным.
						if (coord_1_beg_int == 0 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; }
						{
							if (coord_1_end_int == 0 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; }
							else if (coord_1_end_int == 0 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int == 0 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; };
						}

					}
					else
					{
						std::cout << "Введены некорректные координаты" << std::endl;
						i--;
						break;
					}
				}

				else
				{
					std::cout << "Клетка занята" << std::endl;
					i--;
					break;
				}
				break;

			case 3:
				//Для 2-х и 3-х палубных всё выполнено практически идентично с 4-х, так что не вижу смысла всё повторно описывать.
				std::cout << "Введите номер строки для размещения первой палубы 3-х ярусного корабля номер " << i << ": ";
				std::cin >> coord_1_beg_str;
				std::cout << "Введите номер столбца для размещения первой палубы 3-х ярусного корабля номер " << i << ": ";
				std::cin >> coord_2_beg_str;

				try
				{
					coord_1_beg_int = stoi(coord_1_beg_str);
					coord_2_beg_int = stoi(coord_2_beg_str);
				}

				catch (...)
				{
					std::cout << "Некорректный ввод" << std::endl;
					i--;
					break;
				}

				if (!(coord_1_beg_int >= 0 && coord_1_beg_int < 10 && coord_2_beg_int >= 0 && coord_2_beg_int < 10))
				{
					std::cout << "Введены некорректные координаты" << std::endl;
					i--;
					break;
				}

				std::cout << "Введите номер строки для размещения последней палубы 3-х ярусного корабля номер " << i << ": ";
				std::cin >> coord_1_end_str;
				std::cout << "Введите номер столбца для размещения последней палубы 3-х ярусного корабля номер " << i << ": ";
				std::cin >> coord_2_end_str;

				try
				{
					coord_1_end_int = stoi(coord_1_end_str);
					coord_2_end_int = stoi(coord_2_end_str);
				}

				catch (...)
				{
					std::cout << "Некорректный ввод" << std::endl;
					i--;
					break;
				}

				if ((coord_1_beg_int * 10 + coord_2_beg_int) > (coord_1_end_int * 10 + coord_2_end_int))
				{
					int coord_1_tmp = coord_1_beg_int;
					int coord_2_tmp = coord_2_beg_int;
					coord_1_beg_int = coord_1_end_int;
					coord_2_beg_int = coord_2_end_int;
					coord_1_end_int = coord_1_tmp;
					coord_2_end_int = coord_2_tmp;
				}

				if (free_cells[coord_1_beg_int * 10 + coord_2_beg_int] && free_cells[coord_1_end_int * 10 + coord_2_end_int]) {
					if (coord_1_end_int >= 0 && coord_1_end_int < 10 && coord_2_end_int >= 0 && coord_2_end_int < 10 && ((coord_1_end_int * 10 + coord_2_end_int) - (coord_1_beg_int * 10 + coord_2_beg_int) == 2 || (coord_1_end_int * 10 + coord_2_end_int) - (coord_1_beg_int * 10 + coord_2_beg_int) == 20))
					{
						if (coord_1_beg_int == coord_1_end_int)
						{
							tmp_coord_1_mid1 = coord_1_beg_int;
							tmp_coord_2_mid1 = coord_2_end_int - 1;
						}
						else
						{
							tmp_coord_1_mid1 = coord_1_end_int - 1;
							tmp_coord_2_mid1 = coord_2_beg_int;
						}

						if (i == 1)
						{
							player_coords[0][4] = coord_1_beg_int;
							player_coords[1][4] = coord_2_beg_int;
							player_coords[0][5] = tmp_coord_1_mid1;
							player_coords[1][5] = tmp_coord_2_mid1;
							player_coords[0][6] = coord_1_end_int;
							player_coords[1][6] = coord_2_end_int;
						}
						else if (i == 2)
						{
							player_coords[0][7] = coord_1_beg_int;
							player_coords[1][7] = coord_2_beg_int;
							player_coords[0][8] = tmp_coord_1_mid1;
							player_coords[1][8] = tmp_coord_2_mid1;
							player_coords[0][9] = coord_1_end_int;
							player_coords[1][9] = coord_2_end_int;
						}


						if (coord_1_beg_int == 0 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; }
						{
							if (coord_1_end_int == 0 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; }
							else if (coord_1_end_int == 0 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int == 0 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; };
						}

					}
					else
					{
						std::cout << "Введены некорректные координаты" << std::endl;
						i--;
						break;
					}
				}

				else
				{
					std::cout << "Клетка занята" << std::endl;
					i--;
					break;
				}
				break;

			case 2:
				std::cout << "Введите номер строки для размещения первой палубы 2-ух ярусного корабля номер " << i - 2 << ": ";
				std::cin >> coord_1_beg_str;
				std::cout << "Введите номер столбца для размещения первой палубы 2-ух ярусного корабля номер " << i - 2 << ": ";
				std::cin >> coord_2_beg_str;

				try
				{
					coord_1_beg_int = stoi(coord_1_beg_str);
					coord_2_beg_int = stoi(coord_2_beg_str);
				}

				catch (...)
				{
					std::cout << "Некорректный ввод" << std::endl;
					i--;
					break;
				}

				if (!(coord_1_beg_int >= 0 && coord_1_beg_int < 10 && coord_2_beg_int >= 0 && coord_2_beg_int < 10))
				{
					std::cout << "Введены некорректные координаты" << std::endl;
					i--;
					break;
				}

				std::cout << "Введите номер строки для размещения второй палубы 2-ух ярусного корабля номер " << i - 2 << ": ";
				std::cin >> coord_1_end_str;
				std::cout << "Введите номер столбца для размещения второй палубы 2-ух ярусного корабля номер " << i - 2 << ": ";
				std::cin >> coord_2_end_str;

				try
				{
					coord_1_end_int = stoi(coord_1_end_str);
					coord_2_end_int = stoi(coord_2_end_str);
				}

				catch (...)
				{
					std::cout << "Некорректный ввод" << std::endl;
					i--;
					break;
				}

				if ((coord_1_beg_int * 10 + coord_2_beg_int) > (coord_1_end_int * 10 + coord_2_end_int))
				{
					int coord_1_tmp = coord_1_beg_int;
					int coord_2_tmp = coord_2_beg_int;
					coord_1_beg_int = coord_1_end_int;
					coord_2_beg_int = coord_2_end_int;
					coord_1_end_int = coord_1_tmp;
					coord_2_end_int = coord_2_tmp;
				}

				if (free_cells[coord_1_beg_int * 10 + coord_2_beg_int] && free_cells[coord_1_end_int * 10 + coord_2_end_int]) {
					if (coord_1_end_int >= 0 && coord_1_end_int < 10 && coord_2_end_int >= 0 && coord_2_end_int < 10 && ((coord_1_end_int * 10 + coord_2_end_int) - (coord_1_beg_int * 10 + coord_2_beg_int) == 1 || (coord_1_end_int * 10 + coord_2_end_int) - (coord_1_beg_int * 10 + coord_2_beg_int) == 10))
					{
						if (i == 3)
						{
							player_coords[0][10] = coord_1_beg_int;
							player_coords[1][10] = coord_2_beg_int;
							player_coords[0][11] = coord_1_end_int;
							player_coords[1][11] = coord_2_end_int;
						}
						else if (i == 4)
						{
							player_coords[0][12] = coord_1_beg_int;
							player_coords[1][12] = coord_2_beg_int;
							player_coords[0][13] = coord_1_end_int;
							player_coords[1][13] = coord_2_end_int;
						}
						else
						{
							player_coords[0][14] = coord_1_beg_int;
							player_coords[1][14] = coord_2_beg_int;
							player_coords[0][15] = coord_1_end_int;
							player_coords[1][15] = coord_2_end_int;
						}

						if (coord_1_beg_int == 0 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; }
						{
							if (coord_1_end_int == 0 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; }
							else if (coord_1_end_int == 0 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int == 0 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int > 0 && coord_1_end_int < 9 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 10 - 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int > 0 && coord_2_end_int < 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int == 0) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int + 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 + 1)] = 0; }
							else if (coord_1_end_int == 9 && coord_2_end_int == 9) { free_cells[coord_1_end_int * 10 + coord_2_end_int] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 1)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10)] = 0; free_cells[coord_1_end_int * 10 + (coord_2_end_int - 10 - 1)] = 0; };
						}

					}
					else
					{
						std::cout << "Введены некорректные координаты" << std::endl;
						i--;
						break;
					}
				}

				else
				{
					std::cout << "Клетка занята" << std::endl;
					i--;
					break;
				}
				break;

			case 1:
				//Для однопалубных я использую только переменные первой клетки, так как этого достаточно для описания такого типа корабля)
				//В остальном всё аналогично.
				std::cout << "Введите номер строки для размещения 1 ярусного корабля номер " << i - 5 << ": ";
				std::cin >> coord_1_beg_str;
				std::cout << "Введите номер столбца для размещения 1 ярусного корабля номер " << i - 5 << ": ";
				std::cin >> coord_2_beg_str;

				try
				{
					coord_1_beg_int = stoi(coord_1_beg_str);
					coord_2_beg_int = stoi(coord_2_beg_str);
				}

				catch (...)
				{
					std::cout << "Некорректный ввод" << std::endl;
					i--;
					break;
				}

				if (free_cells[coord_1_beg_int * 10 + coord_2_beg_int]) {
					if (coord_1_beg_int >= 0 && coord_1_beg_int < 10 && coord_2_beg_int >= 0 && coord_2_beg_int < 10)
					{
						player_coords[0][i + 10] = coord_1_beg_int;
						player_coords[1][i + 10] = coord_2_beg_int;

						if (coord_1_beg_int == 0 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 0 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int > 0 && coord_1_beg_int < 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int > 0 && coord_2_beg_int < 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 0) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int + 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 + 1)] = 0; }
						else if (coord_1_beg_int == 9 && coord_2_beg_int == 9) { free_cells[coord_1_beg_int * 10 + coord_2_beg_int] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 1)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10)] = 0; free_cells[coord_1_beg_int * 10 + (coord_2_beg_int - 10 - 1)] = 0; };

					}
					else
					{
						std::cout << "Введены некорректные координаты" << std::endl;
						i--;
						break;
					}
				}
				else
				{
					std::cout << "Клетка занята" << std::endl;
					i--;
					break;
				}

				break;
			}
		}





		system("pause");
		system("cls");
	}

}
*/