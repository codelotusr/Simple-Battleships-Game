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
    void insert_player1_ships(std::string); //Inserts the player1 ships
    void insert_player2_ships(std::string); //Inserts the player2 ships
    void insert_bot_ships(); //Inserts the bot ships
    void attack(std::vector<std::vector<char>> &board, std::vector<std::vector<char>> &visible_board, std::vector<std::vector<char>> &board2, std::vector<std::vector<char>> &visible_board2, std::map<std::string, unsigned int> &ship_life, bool &win, std::string name1, std::string name2, std::map<std::string, unsigned int> &game_scoreboard); //Attacks the board
protected:
    std::vector<int> row_coordinates = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<char> column_coordinates = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
};

#endif // GAME_BOARD_H