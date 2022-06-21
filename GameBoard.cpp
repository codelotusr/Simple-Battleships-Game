
#include "GameBoard.h"
#include "Player.h"

void GameBoard::operator++() //Creates the player1 gameboard
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            std::vector<char> v1;
            for (int j = 0; j < columns; j++) 
            {
                v1.push_back(water);
            }
            player1_board.push_back(v1);
        }
    }
}

void GameBoard::operator++(int) //Creates the player2 gameboard
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            std::vector<char> v2;
            for (int j = 0; j < columns; j++) 
            {
                v2.push_back(water);
            }
            player2_board.push_back(v2);
        }
    }
}



void GameBoard::print_board(std::string name, std::vector<std::vector<char>> vec) //Prints the gameboard
{
    std::cout << name << "'s board:\n";
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}