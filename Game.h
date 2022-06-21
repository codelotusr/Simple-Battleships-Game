#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>

class Game
{
public:
    Game();
    virtual ~Game();
    void main_menu();
    inline bool get_playing_status() const { return this->playing_status; }
    void clear_screen();
    void play_with_friend();

protected:
    const unsigned int rows;
    const unsigned int columns;
    unsigned int player1_points;
    unsigned int player2_points;
    unsigned int bot_points;
    bool playing_status;
    unsigned int choice;
    unsigned int player1_scoreboard_points;
    unsigned int player2_scoreboard_points;
    unsigned int bot_scoreboard_points;
    char water{'~'};
    char ship{'S'};
    char hit{'X'};
    char miss{'O'};
    std::string player1;
    std::string player2;
    std::vector<std::vector<char>> player1_board;
    std::vector<std::vector<char>> player2_board;
    std::vector<std::vector<char>> bot_board;
    std::vector<std::vector<char>> bot_visible_board;

};


#endif // GAME_H