
#include "GameBoard.h"
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

void GameBoard::operator--() //Creates the bot gameboard
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            std::vector<char> v3;
            for (int j = 0; j < columns; j++) 
            {
                v3.push_back(water);
            }
            bot_board.push_back(v3);
        }
    }
    bot_visible_board = bot_board;
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

void GameBoard::insert_bot_ships()
{
    unsigned int direction;
    unsigned int x, y;
    Ships s3;
    Carrier carrier;
    Battleship battle;
    Destroyer destroyer;
    Submarine sub;
    PatrolBoat pboat;
    printing_stuff printing;
    printing.print_the_colorful_board("Bot", bot_board);
    carrier.create_bot_ship(x, y, direction, bot_board);
    clear_screen();
    printing.print_the_colorful_board("Bot", bot_board);
    print_press_enter();
    clear_screen();
}

void GameBoard::attack(std::vector<std::vector<char>> &board, std::vector<std::vector<char>> &visible_board, std::vector<std::vector<char>> &board2, std::vector<std::vector<char>> &visible_board2, std::map<std::string, unsigned int> &ship_life, bool &win, std::string name1, std::string name2, std::map<std::string, unsigned int> &game_scoreboard)
{
    printing_stuff printingss;
    int x;
    char y;
    if (ship_life["C"] == 0 && ship_life["B"] == 0 && ship_life["D"] == 0 && ship_life["S"] == 0 && ship_life["P"] == 0)
    {
        win = true;
        std::string winner = name1;
        game_scoreboard[winner]++;
        clear_screen();
        print_the_winner(winner);
    }
    if (!win)
    {
    enter_coordinates_attack_colored();
    std::cin >> x >> y;
    int yy = y - 'A';
    if (x < 0 || x > rows || yy < 0 || yy > columns)
    {
        invalid_coordinates_colored();
        attack(board, visible_board, board2, visible_board2, ship_life, win, name1, name2, game_scoreboard);
    }
    else if (board[x][yy] == water)
    {
        you_missed_colored();
        visible_board[x][yy] = miss;
        board[x][yy] = miss;
    }
    else if (board[x][yy] == miss)
    {
        you_already_attacked_this_cell_colored();
        attack(board, visible_board, board2, visible_board2, ship_life, win, name1, name2, game_scoreboard);
    }
    else if (board[x][yy] == 'C')
    {
        
        visible_board[x][yy] = hit;
        board[x][yy] = hit;
        ship_life["C"]--;
        clear_screen();
        you_hit_a_carrier_colored();
        if (ship_life["C"] == 0)
        {
            you_sunk_a_carrier_colored();
        }
        printingss.print_the_colorful_board(name2, visible_board);
        printingss.print_the_colorful_board(name1, board2);
        attack(board, visible_board, board2, visible_board2, ship_life, win, name1, name2, game_scoreboard);
    }
    else if (board[x][yy] == 'B')
    {
        visible_board[x][yy] = hit;
        board[x][yy] = hit;
        ship_life["B"]--;
        clear_screen();
        you_hit_a_battleship_colored();
        if (ship_life["B"] == 0)
        {
            you_sunk_a_battleship_colored();
        }
        printingss.print_the_colorful_board(name2, visible_board);
        printingss.print_the_colorful_board(name1, board2);
        attack(board, visible_board, board2, visible_board2, ship_life, win, name1, name2, game_scoreboard);
    }
    else if (board[x][yy] == 'D')
    {
        visible_board[x][yy] = hit;
        board[x][yy] = hit;
        ship_life["D"]--;
        clear_screen();
        you_hit_a_destroyer_colored();
        if (ship_life["D"] == 0)
        {
            you_sunk_a_destroyer_colored();
        }
        printingss.print_the_colorful_board(name2, visible_board);
        printingss.print_the_colorful_board(name1, board2);
        attack(board, visible_board, board2, visible_board2, ship_life, win, name1, name2, game_scoreboard);
    }
    else if (board[x][yy] == 'S')
    {
        visible_board[x][yy] = hit;
        board[x][yy] = hit;
        ship_life["S"]--;
        clear_screen();
        you_hit_a_submarine_colored();
        if (ship_life["S"] == 0)
        {
            you_sunk_a_submarine_colored();
        }
        printingss.print_the_colorful_board(name2, visible_board);
        printingss.print_the_colorful_board(name1, board2);
        attack(board, visible_board, board2, visible_board2, ship_life, win, name1, name2, game_scoreboard);
    }
    else if (board[x][yy] == 'P')
    {
        visible_board[x][yy] = hit;
        board[x][yy] = hit;
        ship_life["P"]--;
        clear_screen();
        you_hit_a_patrol_colored();
        if (ship_life["P"] == 0)
        {
            you_sunk_a_patrol_colored();
        }
        printingss.print_the_colorful_board(name2, visible_board);
        printingss.print_the_colorful_board(name1, board2);
        attack(board, visible_board, board2, visible_board2, ship_life, win, name1, name2, game_scoreboard);
    }
}
    

}
