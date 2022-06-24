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

class printing_stuff : public Game
{
public:
    void print_the_colorful_board(std::string, std::vector<std::vector<char>>);
};

#endif