#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <windows.h>


class Game
{
public:
    Game();
    virtual ~Game();
    void main_menu();
    inline bool get_playing_status() const { return this->playing_status; }
    void game_rules();
    void clear_screen();
    void play_with_friend();
    void play_with_bot();
    void scoreboard();

protected:
    const unsigned int rows;
    const unsigned int columns;
    bool playing_status;
    unsigned int choice;
    unsigned int player1_scoreboard_points;
    unsigned int player2_scoreboard_points;
    unsigned int bot_scoreboard_points;
    char water{'~'};
    char hit{'X'};
    char miss{'O'};
    std::string player1;
    std::string player2;
    std::vector<std::vector<char>> player1_board;
    std::vector<std::vector<char>> player2_board;
    std::vector<std::vector<char>> player1_visible_board;
    std::vector<std::vector<char>> player2_visible_board;
    std::vector<std::vector<char>> bot_board;
    std::vector<std::vector<char>> bot_visible_board;
    std::set<std::string> usernames;
    bool is_over = false;
    std::map<std::string, unsigned int> player1_ships = {{"C", 5}, {"B", 4}, {"D", 3}, {"S", 3}, {"P", 2}};
    std::map<std::string, unsigned int> player2_ships = {{"C", 5}, {"B", 4}, {"D", 3}, {"S", 3}, {"P", 2}};
    std::map<std::string, unsigned int> bot_ships = {{"C", 5}, {"B", 4}, {"D", 3}, {"S", 3}, {"P", 2}};
    std::map<std::string, unsigned int> game_scoreboard;

};

//Create an exception class for the game
class GameException : public std::exception
{
public:
    GameException(std::string message) : message(message) {}
    virtual const char* what() const throw()
    {
        return message.c_str();
    }
private:
    std::string message;
};


#endif // GAME_H