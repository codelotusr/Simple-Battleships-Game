#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include "Game.h"
#include <string>

class Scoreboard : public Game
{
public:
    void print_scoreboard(std::map<std::string, unsigned int> &game_scoreboard); //Prints the scoreboard
};


#endif // SCOREBOARD_H