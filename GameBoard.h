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
};

#endif // GAME_BOARD_H