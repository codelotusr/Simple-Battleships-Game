
#include "GameBoard.h"
#include "Player.h"
#include "Ships.h"
#include "colorsprint.h"

void GameBoard::operator++() //Creates the player1 gameboard
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            std::vector<char> v1;
            for (int j = 0; j < columns; j++) 
            {
                v1.push_back(water);
            }
            player1_board.push_back(v1);
        }
    }
    player1_visible_board = player1_board;
}

void GameBoard::operator++(int) //Creates the player2 gameboard
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            std::vector<char> v2;
            for (int j = 0; j < columns; j++) 
            {
                v2.push_back(water);
            }
            player2_board.push_back(v2);
        }
    }
    player2_visible_board = player2_board;
}

void GameBoard::insert_player1_ships(std::string p1)
{
    Ships s1;
    Carrier carrier;
    Battleship battle;
    Destroyer destroyer;
    Submarine sub;
    PatrolBoat pboat;
    printing_stuff printing;
    printing.print_the_colorful_board(p1, player1_board);
    carrier.create_ship(player1_board);
    clear_screen();
    printing.print_the_colorful_board(p1, player1_board);
    battle.create_ship(player1_board);
    clear_screen();
    printing.print_the_colorful_board(p1, player1_board);
    destroyer.create_ship(player1_board);
    clear_screen();
    printing.print_the_colorful_board(p1, player1_board);
    sub.create_ship(player1_board);
    clear_screen();
    printing.print_the_colorful_board(p1, player1_board);
    pboat.create_ship(player1_board);
    clear_screen();
    printing.print_the_colorful_board(p1, player1_board);
    print_press_enter();
    clear_screen();

}

void GameBoard::insert_player2_ships(std::string p2)
{
    Ships s2;
    Carrier carrier;
    Battleship battle;
    Destroyer destroyer;
    Submarine sub;
    PatrolBoat pboat;
    printing_stuff printing;
    printing.print_the_colorful_board(p2, player2_board);
    carrier.create_ship(player2_board);
    clear_screen();
    printing.print_the_colorful_board(p2, player2_board);
    battle.create_ship(player2_board);
    clear_screen();
    printing.print_the_colorful_board(p2, player2_board);
    destroyer.create_ship(player2_board);
    clear_screen();
    printing.print_the_colorful_board(p2, player2_board);
    sub.create_ship(player2_board);
    clear_screen();
    printing.print_the_colorful_board(p2, player2_board);
    pboat.create_ship(player2_board);
    clear_screen();
    printing.print_the_colorful_board(p2, player2_board);
    print_press_enter();
    clear_screen();
}
