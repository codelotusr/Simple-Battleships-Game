#ifndef GAME_BOARD_H
#define GAME_BOARD_H
#include "Game.h"
#include <vector>
#include <string>

class GameBoard : public Game
{
public:
    void operator++(); //Creates the player1 gameboard
    void operator++(int); //Creates the player2 gameboard
    void operator--(); //Creates the bot gameboard
    void print_board(std::string, std::vector<std::vector<char>>); //Prints the gameboard
protected:
    std::vector<int> row_coordinates = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<char> column_coordinates = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
};

#endif // GAME_BOARD_H