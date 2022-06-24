#ifndef PLAYER_H
#define PLAYER_H
#include "Game.h"

class Player : Game
{
public:
    void attack(std::string, std::vector<std::vector<char>>, std::vector<std::vector<char>>);

};

#endif // PLAYER_H