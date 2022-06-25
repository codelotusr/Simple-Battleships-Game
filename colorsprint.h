#ifndef colorsprint_h
#define colorsprint_h
#include <cstdlib>
#include "Game.h"

void clr_screen();
void print_logo();
void print_menu();
void error_message(const std::string message);
void print_first_launch();
void print_press_enter();
void print_colorful_scoreboard_sign();
void print_the_winner(const std::string);
void enter_coordinates_attack_colored();
void invalid_coordinates_colored();
void you_sunk_colored();
void you_missed_colored();
void you_already_attacked_this_cell_colored();
void you_hit_a_carrier_colored();
void you_sunk_a_carrier_colored();
void you_hit_a_battleship_colored();
void you_sunk_a_battleship_colored();
void you_hit_a_destroyer_colored();
void you_sunk_a_destroyer_colored();
void you_hit_a_submarine_colored();
void you_sunk_a_submarine_colored();
void you_hit_a_patrol_colored();
void you_sunk_a_patrol_colored();
void print_scoreboard_colored(std::vector<std::string> names1, std::vector<unsigned int> scores1, std::map<std::string, unsigned int> game_scoreboard1);
void print_no_scores_yet_colored();
void print_too_long_colord();
void print_invalid_direction_colored();

class printing_stuff : public Game
{
public:
    void print_the_colorful_board(std::string, std::vector<std::vector<char>>);
};

#endif