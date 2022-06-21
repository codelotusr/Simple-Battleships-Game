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
    std::cout << hue::bright_white << "Welcome to the game of Battleships!\n" << hue::reset;
    std::cout << hue::bright_white << "Please select an option:\n" << hue::reset;
    std::cout << hue::bright_white << "1. Play against a friend\n" << hue::reset;
    std::cout << hue::bright_white << "2. Play against the computer\n" << hue::reset;
    std::cout << hue::bright_white << "3. Rules\n" << hue::reset;
    std::cout << hue::bright_white << "4. Scoreboard\n" << hue::reset;
    std::cout << hue::bright_white << "5. Quit\n" << hue::reset;
    std::cout << hue::bright_white << "Enter your choice: " << hue::reset;
}

void error_message(const std::string message)
{
    std::cout << hue::red << message << hue::reset << '\n';
}