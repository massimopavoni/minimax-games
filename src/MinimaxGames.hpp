/*
minimax-games
Copyright (C) 2022  Massimo Pavoni

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <algorithm>
#include <iostream>

#ifndef TicTacToe_H
#define TicTacToe_H

class TicTacToe
{
private:
    uint16_t board;
    uint16_t mask;
    int8_t player;
    int8_t currentPlayer;
    int8_t scoreValue;
    int8_t explorationOrder[9] = {0, 2, 6, 8, 4, 1, 3, 5, 7};

    bool CheckBoard(uint16_t board);
    int8_t EvaluateBoard(uint16_t board, uint16_t mask);
    int8_t Minimax(uint16_t board, uint16_t mask, bool isMax, int8_t alpha, int8_t beta, int8_t depth);

public:
    TicTacToe(int8_t player);

    int8_t Player();
    int8_t CurrentPlayer();
    void PrintBoard();
    int8_t Move(int8_t position, int8_t player);
    int8_t BestMove();
};

#endif
