#include "Ships.h"
#include <vector>




void Ships::print_ships(std::string player, std::vector<std::vector<char>> board)
{
    std::cout << player << "'s board:\n";
    std::cout << std::setw(3) << " A" << std::setw(2) << " B " << "C " << "D " << "E " << "F " << "G " << "H " << "I " << "J\n";
    for (unsigned int i = 0; i < rows; i++)
    {
        std::cout << i << " ";
        for (unsigned int j = 0; j < columns; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


Carrier::Carrier ()
{
    ship_size = 5;
    ship_symbol = 'C';
}

void Carrier::create_ship()
{
    unsigned int x; //x is the row coordinate
    unsigned char ch; //y is the column coordinate
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship(A - J): ";
    std::cin >> ch;
    unsigned int y = ch - 64; //Converts the column coordinate to a number
}

Battleship::Battleship ()
{
    ship_size = 4;
    ship_symbol = 'B';
}

void Battleship::create_ship ()
{
    unsigned int x; //x is the row coordinate
    unsigned char ch; //y is the column coordinate
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship: ";
    std::cin >> ch;
    unsigned int y = ch - 64; //Converts the column coordinate to a number
}

Destroyer::Destroyer ()
{
    ship_size = 3;
    ship_symbol = 'D';
}

void Destroyer::create_ship ()
{
    unsigned int x; //x is the row coordinate
    unsigned char ch; //y is the column coordinate
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship: ";
    std::cin >> ch;
    unsigned int y = ch - 64; //Converts the column coordinate to a number
}

Submarine::Submarine ()
{
    ship_size = 3;
    ship_symbol = 'S';
}

void Submarine::create_ship ()
{
    unsigned int x; //x is the row coordinate
    unsigned char ch; //y is the column coordinate
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship: ";
    std::cin >> ch;
    unsigned int y = ch - 64; //Converts the column coordinate to a number
}

PatrolBoat::PatrolBoat ()
{
    ship_size = 2;
    ship_symbol = 'P';
}

void PatrolBoat::create_ship ()
{
    unsigned int x; //x is the row coordinate
    unsigned char ch; //y is the column coordinate
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship: ";
    std::cin >> ch;
    unsigned int y = ch - 64; //Converts the column coordinate to a number
}