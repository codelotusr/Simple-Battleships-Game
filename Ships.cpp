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
    int yy = y - 'A';
    std::cout << "Which direction will the ship be placed?(1 - Vertical-down, 2 - Vertical-up, 3 - Horizontal-right, 4 - Horizontal-left): ";
    int direction;
    std::cin >> direction;
    if (direction == 1)
    {
        if (x + ship_size > rows)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x + i][yy] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x + i][yy] = ship_symbol;

        }
    }
    else if (direction == 2)
    {
        if (x - ship_size < 0)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x - i][yy] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x - i][yy] = ship_symbol;
 
        }
    }
    else if (direction == 3)
    {
        if (yy + ship_size > columns)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy + i] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy + i] = ship_symbol;
            if(board[x][yy + i - 1] == water) board[x][yy - i - 1] = '*';
            if(board[x][yy + i + 1] == water) board[x][yy - i + 1] = '*';
            if(board[x - 1][yy + i] == water) board[x - 1][yy - i] = '*';
            if(board[x + 1][yy + i] == water) board[x + 1][yy - i] = '*';
        }
    }
    else if (direction == 4)
    {
        if (yy - ship_size < 0)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy - i] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy - i] = ship_symbol;
            if(board[x][yy - i - 1] == water) board[x][yy - i - 1] = '*';
            if(board[x][yy - i + 1] == water) board[x][yy - i + 1] = '*';
            if(board[x - 1][yy - i] == water) board[x - 1][yy - i] = '*';
            if(board[x + 1][yy - i] == water) board[x + 1][yy - i] = '*';
        }
    }
    else
    {
        throw GameException("Invalid direction.");
    }
    
                  
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
    int yy = y - 'A';
    std::cout << "Which direction will the ship be placed?(1 - Vertical-down, 2 - Vertical-up, 3 - Horizontal-right, 4 - Horizontal-left): ";
    int direction;
    std::cin >> direction;

    if (direction == 1)
    {
        if (x + ship_size > rows)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x + i][yy] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x + i][yy] = ship_symbol;
        }
    }
    else if (direction == 2)
    {
        if (x - ship_size < 0)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x - i][yy] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x - i][yy] = ship_symbol;
        }
    }
    else if (direction == 3)
    {
        if (yy + ship_size > columns)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy + i] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy + i] = ship_symbol;
        }
    }
    else if (direction == 4)
    {
        if (yy - ship_size < 0)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy - i] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy - i] = ship_symbol;
        }
    }
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
    int yy = y - 'A';
    std::cout << "Which direction will the ship be placed?(1 - Vertical-down, 2 - Vertical-up, 3 - Horizontal-right, 4 - Horizontal-left): ";
    int direction;
    std::cin >> direction;
    if (direction == 1)
    {
        if (x + ship_size > rows)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x + i][yy] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x + i][yy] = ship_symbol;
        }
    }
    else if (direction == 2)
    {
        if (x - ship_size < 0)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x - i][yy] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x - i][yy] = ship_symbol;
        }
    }
    else if (direction == 3)
    {
        if (yy + ship_size > columns)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy + i] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy + i] = ship_symbol;
        }
    }
    else if (direction == 4)
    {
        if (yy - ship_size < 0)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy - i] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy - i] = ship_symbol;
        }
    }

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
    int yy = y - 'A';
    std::cout << "Which direction will the ship be placed?(1 - Vertical-down, 2 - Vertical-up, 3 - Horizontal-right, 4 - Horizontal-left): ";
    int direction;
    std::cin >> direction;
    if (direction == 1)
    {
        if (x + ship_size > rows)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x + i][yy] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x + i][yy] = ship_symbol;
        }
    }
    else if (direction == 2)
    {
        if (x - ship_size < 0)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x - i][yy] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x - i][yy] = ship_symbol;
        }
    }
    else if (direction == 3)
    {
        if (yy + ship_size > columns)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy + i] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy + i] = ship_symbol;
        }
    }
    else if (direction == 4)
    {
        if (yy - ship_size < 0)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy - i] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy - i] = ship_symbol;
        }
    }
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
    int yy = y - 'A';
    std::cout << "Which direction will the ship be placed?(1 - Vertical-down, 2 - Vertical-up, 3 - Horizontal-right, 4 - Horizontal-left): ";
    int direction;
    std::cin >> direction;
    if (direction == 1)
    {
        if (x + ship_size > rows)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x + i][yy] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x + i][yy] = ship_symbol;
        }
    }
    else if (direction == 2)
    {
        if (x - ship_size < 0)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x - i][yy] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x - i][yy] = ship_symbol;
        }
    }
    else if (direction == 3)
    {
        if (yy + ship_size > columns)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy + i] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy + i] = ship_symbol;
        }
    }
    else if (direction == 4)
    {
        if (yy - ship_size < 0)
        {
            throw GameException("The ship is too long to be placed in the specified direction.");
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy - i] != water)
            {
                throw GameException("The ship is too long to be placed in the specified direction.");
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy - i] = ship_symbol;
        }
    }
}