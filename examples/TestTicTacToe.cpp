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

#include <chrono>
#include "../src/MinimaxGames.hpp"

int main()
{
    int8_t player;
    int8_t score = 2;
    int8_t bestMove;
    uint16_t position;
    std::cout << "Player: ";
    std::cin >> player;
    player = player == 'X';
    TicTacToe game = TicTacToe(player);
    while (score == 2)
    {
        game.PrintBoard();
        std::cout << std::endl;
        if (game.CurrentPlayer() == player)
        {
            do
            {
                std::cout << std::endl
                          << "Your move: ";
                std::cin >> position;
                score = game.Move(position - 1, player);
            } while (score == 4);
        }
        else
        {
            auto start = std::chrono::steady_clock::now();
            bestMove = game.BestMove();
            auto end = std::chrono::steady_clock::now();

            std::cout << std::endl
                      << "Best move: " << bestMove + 1 << " ("
                      << (float)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000
                      << "μs)" << std::endl;

            score = game.Move(bestMove, game.CurrentPlayer());
        }
    }
    game.PrintBoard();
    std::cout << std::endl
              << std::endl;
    if (score == -1)
        std::cout << "You win." << std::endl;
    else if (score == 1)
        std::cout << "You lose." << std::endl;
    else
        std::cout << "Draw." << std::endl;
    return 0;
}