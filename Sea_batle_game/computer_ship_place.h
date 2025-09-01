#pragma once

#ifndef COMPUTER_SHIP_PLACE_H
#define COMPUTER_SHIP_PLACE_H

#include <iostream>
#include <cstdlib>  // для rand() и srand()
#include <ctime>    // для time()
#include "CONSTANTS.h"

namespace play {


    // Проверка, есть ли указанные координаты уже в списке занятых клеток
    inline bool is_coord_in_list(const int coords[2][SHEEP_SIZE], int size, int x, int y) {
        for (int i = 0; i < size; i++) {
            if (coords[0][i] == x && coords[1][i] == y) {
                return true; // Координаты уже есть в списке
            }
        }
        return false; // Нет в списке
    }

    // Проверка, находится ли точка внутри границ поля
    inline bool is_within_field(int x, int y) {
        return x >= 0 && x < FIELD_SIZE && y >= 0 && y < FIELD_SIZE;
    }

    // Проверка, свободна ли клетка (не занята уже размещенными кораблями)
    inline bool is_cell_free(int x, int y, const int occupied[2][SHEEP_SIZE * 10], int occupied_count) {
        for (int i = 0; i < occupied_count; i++) {
            if (occupied[0][i] == x && occupied[1][i] == y) {
                return false; // Клетка занята
            }
        }
        return true; // Клетка свободна
    }

    // Проверка, можно ли разместить корабль заданной длины в указанной позиции и ориентации
    inline bool can_place_ship(const int occupied[2][SHEEP_SIZE * 10], int occupied_count, int x, int y, int dir, int size) {
        // Перебираем каждую клетку будущего корабля
        for (int i = 0; i < size; i++) {
            int cx = x + (dir == 0 ? i : 0); // Смещение по горизонтали
            int cy = y + (dir == 1 ? i : 0); // Смещение по вертикали

            if (!is_within_field(cx, cy))
                return false; // Если клетка вне поля, размещение невозможно

            // Проверяем все соседние клетки вокруг текущей клетки
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = cx + dx; // Координаты соседней клетки по X
                    int ny = cy + dy; // Координаты соседней клетки по Y
                    if (is_within_field(nx, ny)) {
                        // Если соседняя клетка занята или входит в существующий корабль
                        if (!is_cell_free(nx, ny, occupied, occupied_count)) {
                            // Проверяем, входит ли эта клетка в текущий будущий корабль
                            bool is_part_of_ship = false;
                            for (int j = 0; j < size; j++) {
                                int sx = x + (dir == 0 ? j : 0);
                                int sy = y + (dir == 1 ? j : 0);
                                if (sx == nx && sy == ny) {
                                    is_part_of_ship = true; // Это часть текущего корабля
                                    break;
                                }
                            }
                            if (!is_part_of_ship)
                                return false; // Соседняя клетка занята чужим кораблем или в зоне
                        }
                    }
                }
            }
        }
        return true; // Все проверки пройдены, размещение возможно
    }

    // Основная функция размещения кораблей компьютером
    inline void computer_ship_place(int coords[2][SHEEP_SIZE]) {
        // Инициализация массива координат - все клетки по умолчанию -1 (нет)
        for (int i = 0; i < SHEEP_SIZE; i++) {
            coords[0][i] = -1; // X
            coords[1][i] = -1; // Y
        }

        // Массив для отслеживания занятых клеток (все корабли)
        int occupied[2][SHEEP_SIZE * 10]; // Максимум клеток для всех кораблей
        int occupied_count = 0; // Счетчик занятых клеток

        // Размеры кораблей в игре (по классике: 1 четырехпалубный, 3 трехпалубных, 3 двухпалубных, 4 однопалубных)
        int ship_sizes[] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
        // Количество кораблей каждого размера
        int ship_counts[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        int total_ships = 10; // Общее число кораблей

        int index = 0; // Индекс для заполнения массива coords

        // Инициализация генератора случайных чисел
        std::srand(std::time(nullptr));

        // Проходим по каждому типу корабля
        for (int s = 0; s < total_ships; s++) {
            int size = ship_sizes[s]; // Размер текущего корабля
            int count = ship_counts[s]; // Количество кораблей этого размера

            // Размещаем требуемое количество кораблей
            for (int c = 0; c < count; c++) {
                bool placed = false; // Флаг успешного размещения
                int attempts = 0; // Количество попыток размещения

                // Пытаемся разместить корабль, пока не получится или не исчерпаем лимит попыток
                while (attempts < 200 && !placed) {
                    int x = std::rand() % FIELD_SIZE; // Случайная позиция X
                    int y = std::rand() % FIELD_SIZE; // Случайная позиция Y
                    int dir = std::rand() % 2; // Ориентация: 0 — горизонтально, 1 — вертикально

                    // Проверка возможности разместить корабль в выбранной позиции
                    if (can_place_ship(occupied, occupied_count, x, y, dir, size)) {
                        // Создаем массив новых клеток для текущего корабля
                        int new_cells[2][SHEEP_SIZE];
                        for (int i = 0; i < size; i++) {
                            int cx = x + (dir == 0 ? i : 0);
                            int cy = y + (dir == 1 ? i : 0);
                            new_cells[0][i] = cx;
                            new_cells[1][i] = cy;
                        }
                        // Заполняем список координат и обновляем занятые клетки
                        for (int i = 0; i < size; i++) {
                            int x_cell = new_cells[0][i];
                            int y_cell = new_cells[1][i];

                            // Добавляем координату, если её еще нет
                            if (!is_coord_in_list(coords, index, x_cell, y_cell)) {
                                coords[0][index] = x_cell;
                                coords[1][index] = y_cell;
                                index++;
                            }
                            // Обновляем список занятых клеток
                            occupied[0][occupied_count] = x_cell;
                            occupied[1][occupied_count] = y_cell;
                            occupied_count++;
                        }
                        placed = true; // Успешно разместили корабль
                    }
                    else {
                        attempts++; // Не удалось, увеличиваем счетчик попыток
                    }
                }

                // Если не удалось разместить корабль за лимит попыток
                if (!placed) {
                    std::cerr << "Не удалось разместить корабль длиной " << size << std::endl;
                }
            }
        }
    }

    // Функция для вывода координат кораблей
    inline void print_coords(const int coords[2][SHEEP_SIZE]) {
        std::cout << "Координаты кораблей:\n";
        for (int i = 0; i < SHEEP_SIZE; i++) {
            if (coords[0][i] == -1 && coords[1][i] == -1) continue; // Пропускаем незаполненные клетки
            std::cout << "(" << coords[0][i] << ", " << coords[1][i] << ")\n";
        }
    }

} // namespace computer_ship_place

#endif // COMPUTER_SHIP_PLACE_H