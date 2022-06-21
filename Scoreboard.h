#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include "Game.h"
#include "Player.h"
#include <string>

class Scoreboard : public Player
{
public:
    virtual void add_score(std::string name, unsigned int points);
    void print_scoreboard();
    void clear_scoreboard();
    void sort_scoreboard();
};


#endif // SCOREBOARD_H