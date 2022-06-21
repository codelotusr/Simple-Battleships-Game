#include "Game.h"
#include "GameBoard.h"


Game::Game()
    : rows(10), columns(10), player1_points(0), player2_points(0), bot_points(0), playing_status(true), choice(0) {}

Game::~Game()
{
}



void Game::main_menu()
{
    std::cout << R"(
██████╗ ██████╗ ██╗███████╗    ██████╗  ██╗    ██╗██████╗     ██████╗  █████╗ ████████╗████████╗██╗     ███████╗███████╗██╗  ██╗██╗██████╗ ███████╗
██╔══██╗██╔══██╗██║██╔════╝    ╚════██╗███║   ██╔╝╚════██╗    ██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝██╔════╝██║  ██║██║██╔══██╗██╔════╝
██████╔╝██████╔╝██║█████╗█████╗ █████╔╝╚██║  ██╔╝  █████╔╝    ██████╔╝███████║   ██║      ██║   ██║     █████╗  ███████╗███████║██║██████╔╝███████╗
██╔═══╝ ██╔══██╗██║██╔══╝╚════╝██╔═══╝  ██║ ██╔╝  ██╔═══╝     ██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝  ╚════██║██╔══██║██║██╔═══╝ ╚════██║
██║     ██║  ██║██║██║         ███████╗ ██║██╔╝   ███████╗    ██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗███████║██║  ██║██║██║     ███████║
╚═╝     ╚═╝  ╚═╝╚═╝╚═╝         ╚══════╝ ╚═╝╚═╝    ╚══════╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝╚═╝     ╚══════╝
)" << '\n';
    std::cout << "Welcome to the game of Battleships!\n";
    std::cout << "Please select an option:\n";
    std::cout << "1. Play against a friend\n";
    std::cout << "2. Play against the computer\n";
    std::cout << "3. Rules\n";
    std::cout << "4. Scoreboard\n";
    std::cout << "5. Quit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        //play against a friend
        clear_screen();
        play_with_friend();
        break;
    case 2:
        //play against the computer
        clear_screen();
        //play_with_bot();
        break;
    case 3:
        //rules
        clear_screen();
        //rules();
        break;
    case 4:
        //scoreboard
        clear_screen();
        //scoreboard();
        break;
    case 5:
        //quit
        clear_screen();
        playing_status = false;
        break;
    default:
        clear_screen();
        std::cout << "Invalid choice. Please try again.\n";
        break;
    }
}




void Game::clear_screen()
{
    std::system("cls");
}

void Game::play_with_friend()
{
    int starting_x, starting_y;
    std::cout << "Please enter Player 1 username: ";
    std::cin >> player1;
    std::cout << "Please enter Player 2 username: ";
    std::cin >> player2;
    if (player1 == player2)
    {
        throw("Usernames cannot be the same. Please try again.");
    }
    GameBoard gameboard;
    ++gameboard;
    gameboard.print_board(player1, gameboard.player1_board);
    gameboard++;
    gameboard.print_board(player2, gameboard.player2_board);
    std::cin >> starting_x >> starting_y;

}