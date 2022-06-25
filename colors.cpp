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

void print_colorful_scoreboard_sign()
{
    std::cout << hue::aqua << R"(
 ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄       ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄  
▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌ 
 ▀▀▀▀█░█▀▀▀▀ ▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀▀▀      ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌
     ▐░▌     ▐░▌       ▐░▌▐░▌               ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌
     ▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄      ▐░█▄▄▄▄▄▄▄▄▄ ▐░▌          ▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌
     ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌     ▐░░░░░░░░░░░▌▐░▌          ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌ ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌
     ▐░▌     ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀       ▀▀▀▀▀▀▀▀▀█░▌▐░▌          ▐░▌       ▐░▌▐░█▀▀▀▀█░█▀▀ ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀█░█▀▀ ▐░▌       ▐░▌
     ▐░▌     ▐░▌       ▐░▌▐░▌                         ▐░▌▐░▌          ▐░▌       ▐░▌▐░▌     ▐░▌  ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌     ▐░▌  ▐░▌       ▐░▌
     ▐░▌     ▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄▄▄       ▄▄▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░▌      ▐░▌ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░▌      ▐░▌ ▐░█▄▄▄▄▄▄▄█░▌
     ▐░▌     ▐░▌       ▐░▌▐░░░░░░░░░░░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░░░░░░░░░░▌ 
      ▀       ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀       ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀  
                                                                                                                                                                              
)" << hue::reset << '\n';
}

void print_the_winner(const std::string winner) {
    std::cout << hue::green << "The winner is " << winner << '\n' << hue::reset;
}

void enter_coordinates_attack_colored() {
    std::cout << hue::light_yellow << "Enter the coordinates of the attack: " << hue::reset;
}

void invalid_coordinates_colored() {
    std::cout << hue::light_red << "Invalid coordinates!\n" << hue::reset;
}

void you_missed_colored() {
    std::cout << hue::light_red << "You missed!\n" << hue::reset;
}

void you_already_attacked_this_cell_colored() {
    std::cout << hue::light_red << "You already attacked this cell!\n" << hue::reset;
}

void you_hit_a_carrier_colored() {
    std::cout << hue::light_green << "You hit a carrier!\n" << hue::reset;
}

void you_sunk_a_carrier_colored() {
    std::cout << hue::light_green << "You sunk a carrier!\n" << hue::reset;
}

void you_hit_a_battleship_colored() {
    std::cout << hue::light_green << "You hit a battleship!\n" << hue::reset;
}

void you_sunk_a_battleship_colored() {
    std::cout << hue::light_green << "You sunk a battleship!\n" << hue::reset;
}

void you_hit_a_submarine_colored() {
    std::cout << hue::light_green << "You hit a submarine!\n" << hue::reset;
}

void you_sunk_a_submarine_colored() {
    std::cout << hue::light_green << "You sunk a submarine!\n" << hue::reset;
}

void you_hit_a_destroyer_colored() {
    std::cout << hue::light_green << "You hit a destroyer!\n" << hue::reset;
}

void you_sunk_a_destroyer_colored() {
    std::cout << hue::light_green << "You sunk a destroyer!\n" << hue::reset;
}

void you_hit_a_patrol_colored() {
    std::cout << hue::light_green << "You hit a patrol boat!\n" << hue::reset;
}

void you_sunk_a_patrol_colored() {
    std::cout << hue::light_green << "You sunk a patrol boat!\n" << hue::reset;
}

void print_scoreboard_colored(std::vector<std::string> names1, std::vector<unsigned int> scores1, std::map<std::string, unsigned int> game_scoreboard1)
{
    for (unsigned int i = 0; i < scores1.size(); i++)
    {
        for (unsigned int j = 0; j < names1.size(); j++)
        {
            if (scores1[i] == game_scoreboard1[names1[j]])
            {
                std::cout << hue::light_yellow << names1[j] << ": " << scores1[i] << hue::reset << std::endl;
            }
        }
    }
}

void print_no_scores_yet_colored() {
    std::cout << hue::light_yellow << "No scores yet!\n" << hue::reset;
}


