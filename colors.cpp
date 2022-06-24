#include <iostream>
#include "color.hpp"
#include "colorsprint.h"
#include "Game.h"

void clr_screen()
{
    system("cls");
}

void print_logo()
{
std::cout << hue::aqua << R"(
██████╗ ██████╗ ██╗███████╗    ██████╗  ██╗    ██╗██████╗     ██████╗  █████╗ ████████╗████████╗██╗     ███████╗███████╗██╗  ██╗██╗██████╗ ███████╗
██╔══██╗██╔══██╗██║██╔════╝    ╚════██╗███║   ██╔╝╚════██╗    ██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝██╔════╝██║  ██║██║██╔══██╗██╔════╝
██████╔╝██████╔╝██║█████╗█████╗ █████╔╝╚██║  ██╔╝  █████╔╝    ██████╔╝███████║   ██║      ██║   ██║     █████╗  ███████╗███████║██║██████╔╝███████╗
██╔═══╝ ██╔══██╗██║██╔══╝╚════╝██╔═══╝  ██║ ██╔╝  ██╔═══╝     ██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝  ╚════██║██╔══██║██║██╔═══╝ ╚════██║
██║     ██║  ██║██║██║         ███████╗ ██║██╔╝   ███████╗    ██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗███████║██║  ██║██║██║     ███████║
╚═╝     ╚═╝  ╚═╝╚═╝╚═╝         ╚══════╝ ╚═╝╚═╝    ╚══════╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝╚═╝     ╚══════╝
)" << hue::reset << '\n';
}

void print_menu()
{
    std::cout << hue::light_yellow << "Welcome to the game of Battleships!\n" << hue::reset;
    std::cout << hue::light_yellow << "Please select an option:\n" << hue::reset;
    std::cout << hue::light_yellow << "1. Play against a friend\n" << hue::reset;
    std::cout << hue::light_yellow << "2. Play against the computer\n" << hue::reset;
    std::cout << hue::light_yellow << "3. Rules\n" << hue::reset;
    std::cout << hue::light_yellow << "4. Scoreboard\n" << hue::reset;
    std::cout << hue::light_yellow << "5. Quit\n" << hue::reset;
    std::cout << hue::light_yellow << "Enter your choice: " << hue::reset;
}

void error_message(const std::string message)
{
    std::cout << hue::red << message << hue::reset << '\n';
}

void print_first_launch()
{
    clr_screen();
    std::cout << hue::light_purple << "Welcome to the game of Battleships! PLEASE READ THE RULES BEFORE PLAYING!!!!!!!!!!!!\n" << hue::reset;
}

void print_press_enter()
{
    std::cout << hue::light_purple << "Press enter to continue..." << hue::reset;
    std::cin.get();
    std::cin.get();
}

void printing_stuff::print_the_colorful_board(std::string name, std::vector<std::vector<char>> vec) //Prints the gameboard
{
    std::vector<int> row_coordinates = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << hue::light_yellow << name << "'s board:\n" << hue::reset;
    std::cout << hue::bright_white << std::setw(3) << " A" << std::setw(2) << " B " << "C " << "D " << "E " << "F " << "G " << "H " << "I " << "J\n" << hue::reset;
    for (unsigned int i = 0; i < rows; i++)
    {
        std::cout << hue::bright_white << row_coordinates[i] << " " << hue::reset;
        for (unsigned int j = 0; j < columns; j++)
        {
            if (vec[i][j] == 'X' || vec[i][j] == '*')
            {
                std::cout << hue::light_red << vec[i][j] << hue::reset << " ";
            }
            else if (vec[i][j] == '~')
            {
                std::cout << hue::light_blue << vec[i][j] << hue::reset << " ";
            }
            else if (vec[i][j] == 'O')
            {
                std::cout << hue::light_aqua << vec[i][j] << hue::reset << " ";
            }
            else
            {
                std::cout << hue::light_green << vec[i][j] << hue::reset << " ";
            }   
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
