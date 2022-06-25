#include "Game.h"
#include "GameBoard.h"
#include "colorsprint.h"
#include "Ships.h"
#include "Scoreboard.h"
#include "Rules.h"
#include <iostream>


Game::Game()
    : rows(10), columns(10), playing_status(true), choice(0) {}

Game::~Game() { }


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
        play_with_bot();
        break;
    case 3:
        //rules
        clear_screen();
        game_rules();
        break;
    case 4:
        //scoreboard
        clear_screen();
        scoreboard();
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
    if (game_scoreboard.find(player1) == game_scoreboard.end()) 
    {
        game_scoreboard[player1] = 0;
    }
    if (game_scoreboard.find(player2) == game_scoreboard.end())
    {
        game_scoreboard[player2] = 0;
    }
    GameBoard gameboard;
    ++gameboard;
    gameboard.insert_player1_ships(player1);
    gameboard++;
    gameboard.insert_player2_ships(player2);
    player1_ships.clear();
    player2_ships.clear();
    player1_ships = {{"C", 5}, {"B", 4}, {"D", 3}, {"S", 3}, {"P", 2}};
    player2_ships = {{"C", 5}, {"B", 4}, {"D", 3}, {"S", 3}, {"P", 2}};
    is_over = false;
    printing_stuff printings;
    while (!is_over)
    {
        printings.print_the_colorful_board(player2, gameboard.player2_visible_board);
        printings.print_the_colorful_board(player1, gameboard.player1_board);
        gameboard.attack(gameboard.player2_board, gameboard.player2_visible_board, gameboard.player1_board, gameboard.player1_visible_board, player2_ships, is_over, player1, player2, game_scoreboard);
        print_press_enter();
        clear_screen();
        printings.print_the_colorful_board(player1, gameboard.player1_visible_board);
        printings.print_the_colorful_board(player2, gameboard.player2_board);
        gameboard.attack(gameboard.player1_board, gameboard.player1_visible_board, gameboard.player2_board, gameboard.player2_visible_board, player1_ships, is_over, player2, player1, game_scoreboard);
        print_press_enter();
        clear_screen();
    }
}

void Game::scoreboard()
{
    Scoreboard scoreboard;
    scoreboard.print_scoreboard(game_scoreboard);
}

void Game::game_rules()
{
    int ch = (rand() % 2);
    std::cout << "To get your brain up and working, we will start of with a simple math game.\n";
    std::cout << "You will be given a shape and its sides and you must answer what its area and perimeter is:)\n";
    if (ch == 0)
    {
        int answ;
        Wectangle wectangle(10, 10);
        std::cout << "The shape is a " << wectangle.get_name() << " with " << wectangle.get_length() << " length and, " << wectangle.get_width() << " width.\n";
        wectangle.draw();
        std::cout << "What is the perimeter of this shape? ";
        std::cin >> answ;
        if (answ == wectangle.perimeter())
        {
            std::cout << "Correct! Your brain is ready to read the rules\n";
        }
        else
        {
            std::cout << "The answer is " << wectangle.perimeter() << ".\n";
            std::cout << "Wrong! better luck next time!\n";
        }
    }
    else
    {
        int answ;
        Triangle triangle(10, 10);
        std::cout << "The shape is a " << triangle.get_name() << " with " << triangle.get_base() << " base and, " << triangle.get_height() << " height.\n";
        triangle.draw();
        std::cout << "What is the area of this shape? (assume it is a right triangle) ";
        std::cin >> answ;
        if (answ == triangle.area())
        {
            std::cout << "Correct! Your brain is ready to read the rules\n";
        }
        else
        {
            std::cout << "The answer is " << triangle.area() << ".\n";
            std::cout << "Wrong! better luck next time!\n";
        }
    }
    print_press_enter();
    clear_screen();
    print_the_colorful_rules();
    print_press_enter();
    
}

void Game::play_with_bot()
{
    usernames.clear();
    std::cout << "Please enter username: ";
    std::cin >> player1;
    usernames.insert(player1);
    std::cout << "Please enter the bot's username: ";
    std::cin >> player2;
    if (usernames.count(player2)) {
        clear_screen();
        throw(GameException("Username already exists. Please try again."));
    }
    else {
        usernames.insert(player2);
    }
    if (game_scoreboard.find(player1) == game_scoreboard.end())
    {
        game_scoreboard[player1] = 0;
    }
    if (game_scoreboard.find(player2) == game_scoreboard.end())
    {
        game_scoreboard[player2] = 0;
    }
    GameBoard gameboard;
    --gameboard;
    gameboard.insert_bot_ships(player2);
    ++gameboard;
    gameboard.insert_player1_ships(player1);
    player1_ships.clear();
    bot_ships.clear();
    player1_ships = {{"C", 5}, {"B", 4}, {"D", 3}, {"S", 3}, {"P", 2}};
    bot_ships = {{"C", 5}, {"B", 4}, {"D", 3}, {"S", 3}, {"P", 2}};
    is_over = false;
    printing_stuff printings;
    while (!is_over)
    {
        printings.print_the_colorful_board(player2, gameboard.bot_visible_board);
        printings.print_the_colorful_board(player1, gameboard.player1_board);
        gameboard.attack(gameboard.bot_board, gameboard.bot_visible_board, gameboard.player1_board, gameboard.player1_visible_board, bot_ships, is_over, player1, player2, game_scoreboard);
        print_press_enter();
        clear_screen();
        gameboard.bot_attack(gameboard.player1_board, gameboard.player1_visible_board, gameboard.player2_board, gameboard.player2_visible_board, player1_ships, is_over, player2, player1, game_scoreboard);
        clear_screen();
    }


}

