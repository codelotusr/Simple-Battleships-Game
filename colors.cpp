#include <iostream>
#include "color.hpp"


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