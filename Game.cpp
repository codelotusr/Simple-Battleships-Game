#include "Game.h"
#include "GameBoard.h"
#include "colorsprint.h"
#include "Ships.h"



Game::Game()
    : rows(10), columns(10), player1_points(0), player2_points(0), bot_points(0), playing_status(true), choice(0) {}

Game::~Game() {}


void Game::main_menu()
{
    print_logo();
    print_menu();
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
        throw(GameException("Invalid choice. Please try again."));
        break;
    }
}




void Game::clear_screen()
{
    std::system("cls");
}

void Game::play_with_friend()
{
    usernames.clear();
    std::cout << "Please enter Player 1 username: ";
    std::cin >> player1;
    usernames.insert(player1);
    std::cout << "Please enter Player 2 username: ";
    std::cin >> player2;
    if (usernames.count(player2)) {
        clear_screen();
        throw(GameException("Username already exists. Please try again."));
    }
    else {
        usernames.insert(player2);
    }
    GameBoard gameboard;
    ++gameboard;
    gameboard.insert_player1_ships(player1);
    gameboard++;
    gameboard.insert_player2_ships(player2);
    printing_stuff printings;
    while (!is_over)
    {
        printings.print_the_colorful_board(player2, gameboard.player2_visible_board);
        printings.print_the_colorful_board(player1, gameboard.player1_board);
        std::cin.get();
        std::cin.get();
    }
}