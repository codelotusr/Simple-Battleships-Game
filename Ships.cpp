#include "Ships.h"
#include "Game.h"
#include "colorsprint.h"
#include <vector>

Carrier::Carrier ()
{
    ship_size = 5;
    ship_symbol = 'C';
    ship_name = "Carrier";
}

void Carrier::create_ship(std::vector<std::vector<char>> &board)
{
    printing_stuff printingsssss;
    std::string cpb = "Current player";
    int x; //x is the row coordinate
    char y; //y is the column coordinate
    std::cout << "Creating the " << ship_name << " ship, that is " << ship_size << " squares long.\n";
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship(A - J): ";
    std::cin >> y;
    int yy = y - 'A';
    if (x < 0 || x > (rows - 1) || yy < 0 || yy > (columns - 1))
    {
        clear_screen();
        invalid_coordinates_colored();
        printingsssss.print_the_colorful_board(cpb, board);
        create_ship(board);
    }
    else
    {
    std::cout << "Which direction will the ship be placed?(1 - Vertical-down, 2 - Vertical-up, 3 - Horizontal-right, 4 - Horizontal-left): ";
    int direction;
    std::cin >> direction;
    if (direction == 1)
    {
        if (x + ship_size > rows)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x + i][yy] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x + i][yy] = ship_symbol;
            if ((board[x + i + 1][yy] == water) && ((x + i + 1) < rows)) board[x + i + 1][yy] = '*';
            if ((board[x + i][yy + 1] == water) && ((yy + 1) < columns)) board[x + i][yy + 1] = '*';
            if ((board[x + i][yy - 1] == water) && ((yy - 1) >= 0)) board[x + i][yy - 1] = '*';
            if ((board[x + i + 1][yy + 1] == water) && ((x + i + 1) < rows) && ((yy + 1) < columns)) board[x + i + 1][yy + 1] = '*';
            if ((board[x + i + 1][yy - 1] == water) && ((x + i + 1) < rows) && ((yy - 1) >= 0)) board[x + i + 1][yy - 1] = '*';
        }
        if (x != 0)
        {
            if (board[x - 1][yy] == water) board[x - 1][yy] = '*';
            if ((board[x - 1][yy + 1] == water) && ((yy + 1) < columns)) board[x - 1][yy + 1] = '*';
            if ((board[x - 1][yy - 1] == water) && ((yy - 1) >= 0)) board[x - 1][yy - 1] = '*';
        }
    }
    else if (direction == 2)
    {
        if (x - ship_size < 0)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x - i][yy] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x - i][yy] = ship_symbol;
            if ((board[x - i + 1][yy] == water) && ((x - i + 1) < rows)) board[x - i + 1][yy] = '*';
            if ((board[x - i][yy + 1] == water) && ((yy + 1) < columns)) board[x - i][yy + 1] = '*';
            if ((board[x - i][yy - 1] == water) && ((yy - 1) >= 0)) board[x - i][yy - 1] = '*';
            if ((board[x - i + 1][yy + 1] == water) && ((x - i + 1) < rows) && ((yy + 1) < columns)) board[x - i + 1][yy + 1] = '*';
            if ((board[x - i + 1][yy - 1] == water) && ((x - i + 1) < rows) && ((yy - 1) >= 0)) board[x - i + 1][yy - 1] = '*';
        }
        if (x != (ship_size - 1))
        {
            if ((board[x - ship_size][yy + 1] == water) && ((yy + 1) < columns)) board[x - ship_size][yy + 1] = '*';
            if ((board[x - ship_size][yy - 1] == water) && ((yy - 1) >= 0)) board[x - ship_size][yy - 1] = '*';
            if ((board[x - ship_size][yy] == water)) board[x - ship_size][yy] = '*';
        }
    }
    else if (direction == 3)
    {
        if (yy + ship_size > columns)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy + i] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy + i] = ship_symbol;
            if ((board[x + 1][yy + i] == water) && ((x + 1) < rows)) board[x + 1][yy + i] = '*';
            if (x != 0)
            {
                if ((board[x - 1][yy + i] == water)) board[x - 1][yy + i] = '*';
                if ((board[x - 1][yy + i + 1] == water) && ((yy + i + 1) < columns)) board[x - 1][yy + i + 1] = '*';
                if (yy != 0)
                {
                    if ((board[x - 1][yy + i - 1] == water)) board[x - 1][yy + i - 1] = '*';
                }
            }
            if ((board[x][yy + i + 1] == water) && ((yy + i + 1) < columns)) board[x][yy + i + 1] = '*';
            if (yy != 0)
            {
                if ((board[x][yy + i - 1] == water)) board[x][yy + i - 1] = '*';
                if ((board[x + 1][yy + i - 1] == water) && ((x + 1) < rows)) board[x + 1][yy + i - 1] = '*';
            }
            
            if ((board[x + 1][yy + i + 1] == water) && ((x + 1) < rows) && ((yy + i + 1) < columns)) board[x + 1][yy + i + 1] = '*';
        }
    }
    else if (direction == 4)
    {
        if (yy - ship_size < 0)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy - i] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy - i] = ship_symbol;
            if ((board[x + 1][yy - i] == water) && ((x + 1) < rows)) board[x + 1][yy - i] = '*';
            if ((board[x][yy - i + 1] == water) && ((yy - i + 1) < columns)) board[x][yy - i + 1] = '*';
            if ((board[x + 1][yy - i + 1] == water) && ((x + 1) < rows) && ((yy - i + 1) < columns)) board[x + 1][yy - i + 1] = '*';
            if (x != 0)
            {
                if ((board[x - 1][yy - i + 1] == water) && ((yy - i + 1) < columns)) board[x - 1][yy - i + 1] = '*';
                if (yy != 0)
                {
                    if ((board[x - 1][yy - i] == water)) board[x - 1][yy - i] = '*';
                }
            }
            if (yy - (ship_size - 1) != 0)
            {
                if ((board[x][yy - i - 1] == water)) board[x][yy - i - 1] = '*';
                if ((board[x + 1][yy - i - 1] == water)) board[x + 1][yy - i - 1] = '*';
                if (x != 0)
                {
                    if ((board[x - 1][yy - i - 1] == water)) board[x - 1][yy - i - 1] = '*';
                }
            }

        }
    }
    else
    {
        clear_screen();
        print_invalid_direction_colored();
        printingsssss.print_the_colorful_board(cpb, board);
        create_ship(board);
    }
    }              
}

//createa function that randomly generates the bot ship placement
void Carrier::create_bot_ship(unsigned int &bot_x, unsigned int &bot_y, unsigned int &direction, std::vector<std::vector<char>> &board)
{
    unsigned int rows = board.size();
    unsigned int columns = board[0].size();
    unsigned int random_x = rand() % rows;
    unsigned int random_y = rand() % columns;
    unsigned int random_direction = rand() % 4;
    if (random_direction == 0)
    {
        if (random_x + ship_size > rows)
        {
            create_bot_ship(bot_x, bot_y, direction, board);
        }
        else
        {
            bot_x = random_x;
            bot_y = random_y;
            direction = random_direction;
        }
    }
    else if (random_direction == 1)
    {
        if (random_y + ship_size > columns)
        {
            create_bot_ship(bot_x, bot_y, direction, board);
        }
        else
        {
            bot_x = random_x;
            bot_y = random_y;
            direction = random_direction;
        }
    }
    else if (random_direction == 2)
    {
        if (random_x - ship_size < 0)
        {
            create_bot_ship(bot_x, bot_y, direction, board);
        }
        else
        {
            bot_x = random_x;
            bot_y = random_y;
            direction = random_direction;
        }
    }
    else if (random_direction == 3)
    {
        if (random_y - ship_size < 0)
        {
            create_bot_ship(bot_x, bot_y, direction, board);
        }
        else
        {
            bot_x = random_x;
            bot_y = random_y;
            direction = random_direction;
        }
    }
    else
    {
        clear_screen();
        print_invalid_direction_colored();
        create_ship(board);
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
    printing_stuff printingsssss;
    std::string cpb = "Current player";
    unsigned int x; //x is the row coordinate
    unsigned char y; //y is the column coordinate
    std::cout << "Creating the " << ship_name << " ship, that is " << ship_size << " squares long.\n";
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship(A - J): ";
    std::cin >> y;
    int yy = y - 'A';
    if (x < 0 || x > (rows - 1) || yy < 0 || yy > (columns - 1))
    {
        clear_screen();
        invalid_coordinates_colored();
        printingsssss.print_the_colorful_board(cpb, board);
        create_ship(board);
    }
    else
    {
    std::cout << "Which direction will the ship be placed?(1 - Vertical-down, 2 - Vertical-up, 3 - Horizontal-right, 4 - Horizontal-left): ";
    int direction;
    std::cin >> direction;

    if (direction == 1)
    {
        if (x + ship_size > rows)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x + i][yy] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x + i][yy] = ship_symbol;
            if ((board[x + i + 1][yy] == water) && ((x + i + 1) < rows)) board[x + i + 1][yy] = '*';
            if ((board[x + i][yy + 1] == water) && ((yy + 1) < columns)) board[x + i][yy + 1] = '*';
            if ((board[x + i][yy - 1] == water) && ((yy - 1) >= 0)) board[x + i][yy - 1] = '*';
            if ((board[x + i + 1][yy + 1] == water) && ((x + i + 1) < rows) && ((yy + 1) < columns)) board[x + i + 1][yy + 1] = '*';
            if ((board[x + i + 1][yy - 1] == water) && ((x + i + 1) < rows) && ((yy - 1) >= 0)) board[x + i + 1][yy - 1] = '*';
        }
        if (x != 0)
        {
            if (board[x - 1][yy] == water) board[x - 1][yy] = '*';
            if ((board[x - 1][yy + 1] == water) && ((yy + 1) < columns)) board[x - 1][yy + 1] = '*';
            if ((board[x - 1][yy - 1] == water) && ((yy - 1) >= 0)) board[x - 1][yy - 1] = '*';
        }
    }
    else if (direction == 2)
    {
        if (x - ship_size < 0)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x - i][yy] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x - i][yy] = ship_symbol;
            if ((board[x - i + 1][yy] == water) && ((x - i + 1) < rows)) board[x - i + 1][yy] = '*';
            if ((board[x - i][yy + 1] == water) && ((yy + 1) < columns)) board[x - i][yy + 1] = '*';
            if ((board[x - i][yy - 1] == water) && ((yy - 1) >= 0)) board[x - i][yy - 1] = '*';
            if ((board[x - i + 1][yy + 1] == water) && ((x - i + 1) < rows) && ((yy + 1) < columns)) board[x - i + 1][yy + 1] = '*';
            if ((board[x - i + 1][yy - 1] == water) && ((x - i + 1) < rows) && ((yy - 1) >= 0)) board[x - i + 1][yy - 1] = '*';
        }
        if (x != (ship_size - 1))
        {
            if ((board[x - ship_size][yy + 1] == water) && ((yy + 1) < columns)) board[x - ship_size][yy + 1] = '*';
            if ((board[x - ship_size][yy - 1] == water) && ((yy - 1) >= 0)) board[x - ship_size][yy - 1] = '*';
            if ((board[x - ship_size][yy] == water)) board[x - ship_size][yy] = '*';
        }
    }
    else if (direction == 3)
    {
        if (yy + ship_size > columns)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy + i] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy + i] = ship_symbol;
            if ((board[x + 1][yy + i] == water) && ((x + 1) < rows)) board[x + 1][yy + i] = '*';
            if (x != 0)
            {
                if ((board[x - 1][yy + i] == water)) board[x - 1][yy + i] = '*';
                if ((board[x - 1][yy + i + 1] == water) && ((yy + i + 1) < columns)) board[x - 1][yy + i + 1] = '*';
                if (yy != 0)
                {
                    if ((board[x - 1][yy + i - 1] == water)) board[x - 1][yy + i - 1] = '*';
                }
            }
            if ((board[x][yy + i + 1] == water) && ((yy + i + 1) < columns)) board[x][yy + i + 1] = '*';
            if (yy != 0)
            {
                if ((board[x][yy + i - 1] == water)) board[x][yy + i - 1] = '*';
                if ((board[x + 1][yy + i - 1] == water) && ((x + 1) < rows)) board[x + 1][yy + i - 1] = '*';
            }
            
            if ((board[x + 1][yy + i + 1] == water) && ((x + 1) < rows) && ((yy + i + 1) < columns)) board[x + 1][yy + i + 1] = '*';
        }
    }
    else if (direction == 4)
    {
        if (yy - ship_size < 0)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy - i] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy - i] = ship_symbol;
            if ((board[x + 1][yy - i] == water) && ((x + 1) < rows)) board[x + 1][yy - i] = '*';
            if ((board[x][yy - i + 1] == water) && ((yy - i + 1) < columns)) board[x][yy - i + 1] = '*';
            if ((board[x + 1][yy - i + 1] == water) && ((x + 1) < rows) && ((yy - i + 1) < columns)) board[x + 1][yy - i + 1] = '*';
            if (x != 0)
            {
                if ((board[x - 1][yy - i + 1] == water) && ((yy - i + 1) < columns)) board[x - 1][yy - i + 1] = '*';
                if (yy != 0)
                {
                    if ((board[x - 1][yy - i] == water)) board[x - 1][yy - i] = '*';
                }
            }
            if (yy - (ship_size - 1) != 0)
            {
                if ((board[x][yy - i - 1] == water)) board[x][yy - i - 1] = '*';
                if ((board[x + 1][yy - i - 1] == water)) board[x + 1][yy - i - 1] = '*';
                if (x != 0)
                {
                    if ((board[x - 1][yy - i - 1] == water)) board[x - 1][yy - i - 1] = '*';
                }
            }

        }
    }
    else
    {
        clear_screen();
        print_invalid_direction_colored();
        printingsssss.print_the_colorful_board(cpb, board);
        create_ship(board);
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
    printing_stuff printingsssss;
    std::string cpb = "Current player";
    unsigned int x; //x is the row coordinate
    unsigned char y; //y is the column coordinate
    std::cout << "Creating the " << ship_name << " ship, that is " << ship_size << " squares long.\n";
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship(A - J): ";
    std::cin >> y;
    int yy = y - 'A';
    if (x < 0 || x > (rows - 1) || yy < 0 || yy > (columns - 1))
    {
        clear_screen();
        invalid_coordinates_colored();
        printingsssss.print_the_colorful_board(cpb, board);
        create_ship(board);
    }
    else
    {
    std::cout << "Which direction will the ship be placed?(1 - Vertical-down, 2 - Vertical-up, 3 - Horizontal-right, 4 - Horizontal-left): ";
    int direction;
    std::cin >> direction;
    if (direction == 1)
    {
        if (x + ship_size > rows)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x + i][yy] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x + i][yy] = ship_symbol;
            if ((board[x + i + 1][yy] == water) && ((x + i + 1) < rows)) board[x + i + 1][yy] = '*';
            if ((board[x + i][yy + 1] == water) && ((yy + 1) < columns)) board[x + i][yy + 1] = '*';
            if ((board[x + i][yy - 1] == water) && ((yy - 1) >= 0)) board[x + i][yy - 1] = '*';
            if ((board[x + i + 1][yy + 1] == water) && ((x + i + 1) < rows) && ((yy + 1) < columns)) board[x + i + 1][yy + 1] = '*';
            if ((board[x + i + 1][yy - 1] == water) && ((x + i + 1) < rows) && ((yy - 1) >= 0)) board[x + i + 1][yy - 1] = '*';
        }
        if (x != 0)
        {
            if (board[x - 1][yy] == water) board[x - 1][yy] = '*';
            if ((board[x - 1][yy + 1] == water) && ((yy + 1) < columns)) board[x - 1][yy + 1] = '*';
            if ((board[x - 1][yy - 1] == water) && ((yy - 1) >= 0)) board[x - 1][yy - 1] = '*';
        }
    }
    else if (direction == 2)
    {
        if (x - ship_size < 0)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x - i][yy] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x - i][yy] = ship_symbol;
            if ((board[x - i + 1][yy] == water) && ((x - i + 1) < rows)) board[x - i + 1][yy] = '*';
            if ((board[x - i][yy + 1] == water) && ((yy + 1) < columns)) board[x - i][yy + 1] = '*';
            if ((board[x - i][yy - 1] == water) && ((yy - 1) >= 0)) board[x - i][yy - 1] = '*';
            if ((board[x - i + 1][yy + 1] == water) && ((x - i + 1) < rows) && ((yy + 1) < columns)) board[x - i + 1][yy + 1] = '*';
            if ((board[x - i + 1][yy - 1] == water) && ((x - i + 1) < rows) && ((yy - 1) >= 0)) board[x - i + 1][yy - 1] = '*';
        }
        if (x != (ship_size - 1))
        {
            if ((board[x - ship_size][yy + 1] == water) && ((yy + 1) < columns)) board[x - ship_size][yy + 1] = '*';
            if ((board[x - ship_size][yy - 1] == water) && ((yy - 1) >= 0)) board[x - ship_size][yy - 1] = '*';
            if ((board[x - ship_size][yy] == water)) board[x - ship_size][yy] = '*';
        }
    }
    else if (direction == 3)
    {
        if (yy + ship_size > columns)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy + i] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy + i] = ship_symbol;
            if ((board[x + 1][yy + i] == water) && ((x + 1) < rows)) board[x + 1][yy + i] = '*';
            if (x != 0)
            {
                if ((board[x - 1][yy + i] == water)) board[x - 1][yy + i] = '*';
                if ((board[x - 1][yy + i + 1] == water) && ((yy + i + 1) < columns)) board[x - 1][yy + i + 1] = '*';
                if (yy != 0)
                {
                    if ((board[x - 1][yy + i - 1] == water)) board[x - 1][yy + i - 1] = '*';
                }
            }
            if ((board[x][yy + i + 1] == water) && ((yy + i + 1) < columns)) board[x][yy + i + 1] = '*';
            if (yy != 0)
            {
                if ((board[x][yy + i - 1] == water)) board[x][yy + i - 1] = '*';
                if ((board[x + 1][yy + i - 1] == water) && ((x + 1) < rows)) board[x + 1][yy + i - 1] = '*';
            }
            
            if ((board[x + 1][yy + i + 1] == water) && ((x + 1) < rows) && ((yy + i + 1) < columns)) board[x + 1][yy + i + 1] = '*';
        }
    }
    else if (direction == 4)
    {
        if (yy - ship_size < 0)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy - i] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy - i] = ship_symbol;
            if ((board[x + 1][yy - i] == water) && ((x + 1) < rows)) board[x + 1][yy - i] = '*';
            if ((board[x][yy - i + 1] == water) && ((yy - i + 1) < columns)) board[x][yy - i + 1] = '*';
            if ((board[x + 1][yy - i + 1] == water) && ((x + 1) < rows) && ((yy - i + 1) < columns)) board[x + 1][yy - i + 1] = '*';
            if (x != 0)
            {
                if ((board[x - 1][yy - i + 1] == water) && ((yy - i + 1) < columns)) board[x - 1][yy - i + 1] = '*';
                if (yy != 0)
                {
                    if ((board[x - 1][yy - i] == water)) board[x - 1][yy - i] = '*';
                }
            }
            if (yy - (ship_size - 1) != 0)
            {
                if ((board[x][yy - i - 1] == water)) board[x][yy - i - 1] = '*';
                if ((board[x + 1][yy - i - 1] == water)) board[x + 1][yy - i - 1] = '*';
                if (x != 0)
                {
                    if ((board[x - 1][yy - i - 1] == water)) board[x - 1][yy - i - 1] = '*';
                }
            }

        }
    }
    else
    {
        clear_screen();
        print_invalid_direction_colored();
        printingsssss.print_the_colorful_board(cpb, board);
        create_ship(board);
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
    printing_stuff printingsssss;
    std::string cpb = "Current player";
    unsigned int x; //x is the row coordinate
    unsigned char y; //y is the column coordinate
    std::cout << "Creating the " << ship_name << " ship, that is " << ship_size << " squares long.\n";
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship(A - J): ";
    std::cin >> y;
    int yy = y - 'A';
    if (x < 0 || x > (rows - 1) || yy < 0 || yy > (columns - 1))
    {
        clear_screen();
        invalid_coordinates_colored();
        printingsssss.print_the_colorful_board(cpb, board);
        create_ship(board);
    }
    else
    {
    std::cout << "Which direction will the ship be placed?(1 - Vertical-down, 2 - Vertical-up, 3 - Horizontal-right, 4 - Horizontal-left): ";
    int direction;
    std::cin >> direction;
    if (direction == 1)
    {
        if (x + ship_size > rows)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x + i][yy] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x + i][yy] = ship_symbol;
            if ((board[x + i + 1][yy] == water) && ((x + i + 1) < rows)) board[x + i + 1][yy] = '*';
            if ((board[x + i][yy + 1] == water) && ((yy + 1) < columns)) board[x + i][yy + 1] = '*';
            if ((board[x + i][yy - 1] == water) && ((yy - 1) >= 0)) board[x + i][yy - 1] = '*';
            if ((board[x + i + 1][yy + 1] == water) && ((x + i + 1) < rows) && ((yy + 1) < columns)) board[x + i + 1][yy + 1] = '*';
            if ((board[x + i + 1][yy - 1] == water) && ((x + i + 1) < rows) && ((yy - 1) >= 0)) board[x + i + 1][yy - 1] = '*';
        }
        if (x != 0)
        {
            if (board[x - 1][yy] == water) board[x - 1][yy] = '*';
            if ((board[x - 1][yy + 1] == water) && ((yy + 1) < columns)) board[x - 1][yy + 1] = '*';
            if ((board[x - 1][yy - 1] == water) && ((yy - 1) >= 0)) board[x - 1][yy - 1] = '*';
        }
    }
    else if (direction == 2)
    {
        if (x - ship_size < 0)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x - i][yy] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x - i][yy] = ship_symbol;
            if ((board[x - i + 1][yy] == water) && ((x - i + 1) < rows)) board[x - i + 1][yy] = '*';
            if ((board[x - i][yy + 1] == water) && ((yy + 1) < columns)) board[x - i][yy + 1] = '*';
            if ((board[x - i][yy - 1] == water) && ((yy - 1) >= 0)) board[x - i][yy - 1] = '*';
            if ((board[x - i + 1][yy + 1] == water) && ((x - i + 1) < rows) && ((yy + 1) < columns)) board[x - i + 1][yy + 1] = '*';
            if ((board[x - i + 1][yy - 1] == water) && ((x - i + 1) < rows) && ((yy - 1) >= 0)) board[x - i + 1][yy - 1] = '*';
        }
        if (x != (ship_size - 1))
        {
            if ((board[x - ship_size][yy + 1] == water) && ((yy + 1) < columns)) board[x - ship_size][yy + 1] = '*';
            if ((board[x - ship_size][yy - 1] == water) && ((yy - 1) >= 0)) board[x - ship_size][yy - 1] = '*';
            if ((board[x - ship_size][yy] == water)) board[x - ship_size][yy] = '*';
        }
    }
    else if (direction == 3)
    {
        if (yy + ship_size > columns)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy + i] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy + i] = ship_symbol;
            if ((board[x + 1][yy + i] == water) && ((x + 1) < rows)) board[x + 1][yy + i] = '*';
            if (x != 0)
            {
                if ((board[x - 1][yy + i] == water)) board[x - 1][yy + i] = '*';
                if ((board[x - 1][yy + i + 1] == water) && ((yy + i + 1) < columns)) board[x - 1][yy + i + 1] = '*';
                if (yy != 0)
                {
                    if ((board[x - 1][yy + i - 1] == water)) board[x - 1][yy + i - 1] = '*';
                }
            }
            if ((board[x][yy + i + 1] == water) && ((yy + i + 1) < columns)) board[x][yy + i + 1] = '*';
            if (yy != 0)
            {
                if ((board[x][yy + i - 1] == water)) board[x][yy + i - 1] = '*';
                if ((board[x + 1][yy + i - 1] == water) && ((x + 1) < rows)) board[x + 1][yy + i - 1] = '*';
            }
            
            if ((board[x + 1][yy + i + 1] == water) && ((x + 1) < rows) && ((yy + i + 1) < columns)) board[x + 1][yy + i + 1] = '*';
        }
    }
    else if (direction == 4)
    {
        if (yy - ship_size < 0)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy - i] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy - i] = ship_symbol;
            if ((board[x + 1][yy - i] == water) && ((x + 1) < rows)) board[x + 1][yy - i] = '*';
            if ((board[x][yy - i + 1] == water) && ((yy - i + 1) < columns)) board[x][yy - i + 1] = '*';
            if ((board[x + 1][yy - i + 1] == water) && ((x + 1) < rows) && ((yy - i + 1) < columns)) board[x + 1][yy - i + 1] = '*';
            if (x != 0)
            {
                if ((board[x - 1][yy - i + 1] == water) && ((yy - i + 1) < columns)) board[x - 1][yy - i + 1] = '*';
                if (yy != 0)
                {
                    if ((board[x - 1][yy - i] == water)) board[x - 1][yy - i] = '*';
                }
            }
            if (yy - (ship_size - 1) != 0)
            {
                if ((board[x][yy - i - 1] == water)) board[x][yy - i - 1] = '*';
                if ((board[x + 1][yy - i - 1] == water)) board[x + 1][yy - i - 1] = '*';
                if (x != 0)
                {
                    if ((board[x - 1][yy - i - 1] == water)) board[x - 1][yy - i - 1] = '*';
                }
            }

        }
    }
    else
    {
        clear_screen();
        print_invalid_direction_colored();
        printingsssss.print_the_colorful_board(cpb, board);
        create_ship(board);
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
    printing_stuff printingsssss;
    std::string cpb = "Current player";
    unsigned int x; //x is the row coordinate
    unsigned char y; //y is the column coordinate
    std::cout << "Creating the " << ship_name << " ship, that is " << ship_size << " squares long.\n";
    std::cout << "Enter the row coordinate of the first cell of the ship(0 - 9): ";
    std::cin >> x;
    std::cout << "Enter the column coordinate of the first cell of the ship(A - J): ";
    std::cin >> y;
    int yy = y - 'A';
    if (x < 0 || x > (rows - 1) || yy < 0 || yy > (columns - 1))
    {
        clear_screen();
        invalid_coordinates_colored();
        printingsssss.print_the_colorful_board(cpb, board);
        create_ship(board);
    }
    else
    {
    std::cout << "Which direction will the ship be placed?(1 - Vertical-down, 2 - Vertical-up, 3 - Horizontal-right, 4 - Horizontal-left): ";
    int direction;
    std::cin >> direction;
    if (direction == 1)
    {
        if (x + ship_size > rows)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x + i][yy] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x + i][yy] = ship_symbol;
            if ((board[x + i + 1][yy] == water) && ((x + i + 1) < rows)) board[x + i + 1][yy] = '*';
            if ((board[x + i][yy + 1] == water) && ((yy + 1) < columns)) board[x + i][yy + 1] = '*';
            if ((board[x + i][yy - 1] == water) && ((yy - 1) >= 0)) board[x + i][yy - 1] = '*';
            if ((board[x + i + 1][yy + 1] == water) && ((x + i + 1) < rows) && ((yy + 1) < columns)) board[x + i + 1][yy + 1] = '*';
            if ((board[x + i + 1][yy - 1] == water) && ((x + i + 1) < rows) && ((yy - 1) >= 0)) board[x + i + 1][yy - 1] = '*';
        }
        if (x != 0)
        {
            if (board[x - 1][yy] == water) board[x - 1][yy] = '*';
            if ((board[x - 1][yy + 1] == water) && ((yy + 1) < columns)) board[x - 1][yy + 1] = '*';
            if ((board[x - 1][yy - 1] == water) && ((yy - 1) >= 0)) board[x - 1][yy - 1] = '*';
        }
    }
    else if (direction == 2)
    {
        if (x - ship_size < 0)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x - i][yy] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x - i][yy] = ship_symbol;
            if ((board[x - i + 1][yy] == water) && ((x - i + 1) < rows)) board[x - i + 1][yy] = '*';
            if ((board[x - i][yy + 1] == water) && ((yy + 1) < columns)) board[x - i][yy + 1] = '*';
            if ((board[x - i][yy - 1] == water) && ((yy - 1) >= 0)) board[x - i][yy - 1] = '*';
            if ((board[x - i + 1][yy + 1] == water) && ((x - i + 1) < rows) && ((yy + 1) < columns)) board[x - i + 1][yy + 1] = '*';
            if ((board[x - i + 1][yy - 1] == water) && ((x - i + 1) < rows) && ((yy - 1) >= 0)) board[x - i + 1][yy - 1] = '*';
        }
        if (x != (ship_size - 1))
        {
            if ((board[x - ship_size][yy + 1] == water) && ((yy + 1) < columns)) board[x - ship_size][yy + 1] = '*';
            if ((board[x - ship_size][yy - 1] == water) && ((yy - 1) >= 0)) board[x - ship_size][yy - 1] = '*';
            if ((board[x - ship_size][yy] == water)) board[x - ship_size][yy] = '*';
        }
    }
    else if (direction == 3)
    {
        if (yy + ship_size > columns)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy + i] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy + i] = ship_symbol;
            if ((board[x + 1][yy + i] == water) && ((x + 1) < rows)) board[x + 1][yy + i] = '*';
            if (x != 0)
            {
                if ((board[x - 1][yy + i] == water)) board[x - 1][yy + i] = '*';
                if ((board[x - 1][yy + i + 1] == water) && ((yy + i + 1) < columns)) board[x - 1][yy + i + 1] = '*';
                if (yy != 0)
                {
                    if ((board[x - 1][yy + i - 1] == water)) board[x - 1][yy + i - 1] = '*';
                }
            }
            if ((board[x][yy + i + 1] == water) && ((yy + i + 1) < columns)) board[x][yy + i + 1] = '*';
            if (yy != 0)
            {
                if ((board[x][yy + i - 1] == water)) board[x][yy + i - 1] = '*';
                if ((board[x + 1][yy + i - 1] == water) && ((x + 1) < rows)) board[x + 1][yy + i - 1] = '*';
            }
            
            if ((board[x + 1][yy + i + 1] == water) && ((x + 1) < rows) && ((yy + i + 1) < columns)) board[x + 1][yy + i + 1] = '*';
        }
    }
    else if (direction == 4)
    {
        if (yy - ship_size < 0)
        {
            clear_screen();
            print_too_long_colord();
            printingsssss.print_the_colorful_board(cpb, board);
            create_ship(board);
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            if (board[x][yy - i] != water)
            {
                clear_screen();
                print_too_long_colord();
                printingsssss.print_the_colorful_board(cpb, board);
                create_ship(board);
            }
        }
        for (unsigned int i = 0; i < ship_size; i++)
        {
            board[x][yy - i] = ship_symbol;
            if ((board[x + 1][yy - i] == water) && ((x + 1) < rows)) board[x + 1][yy - i] = '*';
            if ((board[x][yy - i + 1] == water) && ((yy - i + 1) < columns)) board[x][yy - i + 1] = '*';
            if ((board[x + 1][yy - i + 1] == water) && ((x + 1) < rows) && ((yy - i + 1) < columns)) board[x + 1][yy - i + 1] = '*';
            if (x != 0)
            {
                if ((board[x - 1][yy - i + 1] == water) && ((yy - i + 1) < columns)) board[x - 1][yy - i + 1] = '*';
                if (yy != 0)
                {
                    if ((board[x - 1][yy - i] == water)) board[x - 1][yy - i] = '*';
                }
            }
            if (yy - (ship_size - 1) != 0)
            {
                if ((board[x][yy - i - 1] == water)) board[x][yy - i - 1] = '*';
                if ((board[x + 1][yy - i - 1] == water)) board[x + 1][yy - i - 1] = '*';
                if (x != 0)
                {
                    if ((board[x - 1][yy - i - 1] == water)) board[x - 1][yy - i - 1] = '*';
                }
            }

        }
    }
    else
    {
        clear_screen();
        print_invalid_direction_colored();
        printingsssss.print_the_colorful_board(cpb, board);
        create_ship(board);
    }
    }
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            if (board[i][j] == '*')
            {
                board[i][j] = water;
            }
        }
    }
}