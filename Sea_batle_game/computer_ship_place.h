#pragma once

#ifndef COMPUTER_SHIP_PLACE_H
#define COMPUTER_SHIP_PLACE_H

#include <iostream>
#include <cstdlib>  // ��� rand() � srand()
#include <ctime>    // ��� time()
#include "CONSTANTS.h"

namespace play {


    // ��������, ���� �� ��������� ���������� ��� � ������ ������� ������
    inline bool is_coord_in_list(const int coords[2][SHEEP_SIZE], int size, int x, int y) {
        for (int i = 0; i < size; i++) {
            if (coords[0][i] == x && coords[1][i] == y) {
                return true; // ���������� ��� ���� � ������
            }
        }
        return false; // ��� � ������
    }

    // ��������, ��������� �� ����� ������ ������ ����
    inline bool is_within_field(int x, int y) {
        return x >= 0 && x < FIELD_SIZE && y >= 0 && y < FIELD_SIZE;
    }

    // ��������, �������� �� ������ (�� ������ ��� ������������ ���������)
    inline bool is_cell_free(int x, int y, const int occupied[2][SHEEP_SIZE * 10], int occupied_count) {
        for (int i = 0; i < occupied_count; i++) {
            if (occupied[0][i] == x && occupied[1][i] == y) {
                return false; // ������ ������
            }
        }
        return true; // ������ ��������
    }

    // ��������, ����� �� ���������� ������� �������� ����� � ��������� ������� � ����������
    inline bool can_place_ship(const int occupied[2][SHEEP_SIZE * 10], int occupied_count, int x, int y, int dir, int size) {
        // ���������� ������ ������ �������� �������
        for (int i = 0; i < size; i++) {
            int cx = x + (dir == 0 ? i : 0); // �������� �� �����������
            int cy = y + (dir == 1 ? i : 0); // �������� �� ���������

            if (!is_within_field(cx, cy))
                return false; // ���� ������ ��� ����, ���������� ����������

            // ��������� ��� �������� ������ ������ ������� ������
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = cx + dx; // ���������� �������� ������ �� X
                    int ny = cy + dy; // ���������� �������� ������ �� Y
                    if (is_within_field(nx, ny)) {
                        // ���� �������� ������ ������ ��� ������ � ������������ �������
                        if (!is_cell_free(nx, ny, occupied, occupied_count)) {
                            // ���������, ������ �� ��� ������ � ������� ������� �������
                            bool is_part_of_ship = false;
                            for (int j = 0; j < size; j++) {
                                int sx = x + (dir == 0 ? j : 0);
                                int sy = y + (dir == 1 ? j : 0);
                                if (sx == nx && sy == ny) {
                                    is_part_of_ship = true; // ��� ����� �������� �������
                                    break;
                                }
                            }
                            if (!is_part_of_ship)
                                return false; // �������� ������ ������ ����� �������� ��� � ����
                        }
                    }
                }
            }
        }
        return true; // ��� �������� ��������, ���������� ��������
    }

    // �������� ������� ���������� �������� �����������
    inline void computer_ship_place(int coords[2][SHEEP_SIZE]) {
        // ������������� ������� ��������� - ��� ������ �� ��������� -1 (���)
        for (int i = 0; i < SHEEP_SIZE; i++) {
            coords[0][i] = -1; // X
            coords[1][i] = -1; // Y
        }

        // ������ ��� ������������ ������� ������ (��� �������)
        int occupied[2][SHEEP_SIZE * 10]; // �������� ������ ��� ���� ��������
        int occupied_count = 0; // ������� ������� ������

        // ������� �������� � ���� (�� ��������: 1 ���������������, 3 ������������, 3 ������������, 4 ������������)
        int ship_sizes[] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
        // ���������� �������� ������� �������
        int ship_counts[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        int total_ships = 10; // ����� ����� ��������

        int index = 0; // ������ ��� ���������� ������� coords

        // ������������� ���������� ��������� �����
        std::srand(std::time(nullptr));

        // �������� �� ������� ���� �������
        for (int s = 0; s < total_ships; s++) {
            int size = ship_sizes[s]; // ������ �������� �������
            int count = ship_counts[s]; // ���������� �������� ����� �������

            // ��������� ��������� ���������� ��������
            for (int c = 0; c < count; c++) {
                bool placed = false; // ���� ��������� ����������
                int attempts = 0; // ���������� ������� ����������

                // �������� ���������� �������, ���� �� ��������� ��� �� ��������� ����� �������
                while (attempts < 200 && !placed) {
                    int x = std::rand() % FIELD_SIZE; // ��������� ������� X
                    int y = std::rand() % FIELD_SIZE; // ��������� ������� Y
                    int dir = std::rand() % 2; // ����������: 0 � �������������, 1 � �����������

                    // �������� ����������� ���������� ������� � ��������� �������
                    if (can_place_ship(occupied, occupied_count, x, y, dir, size)) {
                        // ������� ������ ����� ������ ��� �������� �������
                        int new_cells[2][SHEEP_SIZE];
                        for (int i = 0; i < size; i++) {
                            int cx = x + (dir == 0 ? i : 0);
                            int cy = y + (dir == 1 ? i : 0);
                            new_cells[0][i] = cx;
                            new_cells[1][i] = cy;
                        }
                        // ��������� ������ ��������� � ��������� ������� ������
                        for (int i = 0; i < size; i++) {
                            int x_cell = new_cells[0][i];
                            int y_cell = new_cells[1][i];

                            // ��������� ����������, ���� � ��� ���
                            if (!is_coord_in_list(coords, index, x_cell, y_cell)) {
                                coords[0][index] = x_cell;
                                coords[1][index] = y_cell;
                                index++;
                            }
                            // ��������� ������ ������� ������
                            occupied[0][occupied_count] = x_cell;
                            occupied[1][occupied_count] = y_cell;
                            occupied_count++;
                        }
                        placed = true; // ������� ���������� �������
                    }
                    else {
                        attempts++; // �� �������, ����������� ������� �������
                    }
                }

                // ���� �� ������� ���������� ������� �� ����� �������
                if (!placed) {
                    std::cerr << "�� ������� ���������� ������� ������ " << size << std::endl;
                }
            }
        }
    }

    // ������� ��� ������ ��������� ��������
    inline void print_coords(const int coords[2][SHEEP_SIZE]) {
        std::cout << "���������� ��������:\n";
        for (int i = 0; i < SHEEP_SIZE; i++) {
            if (coords[0][i] == -1 && coords[1][i] == -1) continue; // ���������� ������������� ������
            std::cout << "(" << coords[0][i] << ", " << coords[1][i] << ")\n";
        }
    }

} // namespace computer_ship_place

#endif // COMPUTER_SHIP_PLACE_H