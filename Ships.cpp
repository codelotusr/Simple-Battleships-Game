#include "Ships.h"
#include "Game.h"
#include <vector>




void Ships::print_ships(std::string player, std::vector<std::vector<char>> &board)
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
    ship_name = "Carrier";
}

void Carrier::create_ship(std::vector<std::vector<char>> &board)
{
    unsigned int x; //x is the row coordinate
    unsigned char y; //y is the column coordinate
    std::cout << "Creating the " << ship_name << " ship, that is " << ship_size << " squares long.\n";
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship(A - J): ";
    std::cin >> y;
    board[x][y - 65] = ship_symbol;
}

Battleship::Battleship ()
{
    ship_size = 4;
    ship_symbol = 'B';
    ship_name = "Battleship";
}

void Battleship::create_ship (std::vector<std::vector<char>> &board)
{
    unsigned int x; //x is the row coordinate
    unsigned char y; //y is the column coordinate
    std::cout << "Creating the " << ship_name << " ship, that is " << ship_size << " squares long.\n";
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship(A - J): ";
    std::cin >> y;
    board[x][y - 65] = ship_symbol;
}

Destroyer::Destroyer ()
{
    ship_size = 3;
    ship_symbol = 'D';
    ship_name = "Destroyer";
}

void Destroyer::create_ship (std::vector<std::vector<char>> &board)
{
    unsigned int x; //x is the row coordinate
    unsigned char y; //y is the column coordinate
    std::cout << "Creating the " << ship_name << " ship, that is " << ship_size << " squares long.\n";
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship(A - J): ";
    std::cin >> y;
    board[x][y - 65] = ship_symbol;

}

Submarine::Submarine ()
{
    ship_size = 3;
    ship_symbol = 'S';
    ship_name = "Submarine";
}

void Submarine::create_ship (std::vector<std::vector<char>> &board)
{
    unsigned int x; //x is the row coordinate
    unsigned char y; //y is the column coordinate
    std::cout << "Creating the " << ship_name << " ship, that is " << ship_size << " squares long.\n";
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship(A - J): ";
    std::cin >> y;
    board[x][y - 65] = ship_symbol;
}

PatrolBoat::PatrolBoat ()
{
    ship_size = 2;
    ship_symbol = 'P';
    ship_name = "Patrol Boat";
}

void PatrolBoat::create_ship (std::vector<std::vector<char>> &board)
{
    unsigned int x; //x is the row coordinate
    unsigned char y; //y is the column coordinate
    std::cout << "Creating the " << ship_name << " ship, that is " << ship_size << " squares long.\n";
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship(A - J): ";
    std::cin >> y;
    board[x][y - 65] = ship_symbol;
}