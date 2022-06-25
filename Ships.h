#ifndef SHIPS_H
#define SHIPS_H
#include "Game.h"
#include "GameBoard.h"


class Ships : public Game
{
public:
    Ships() = default;
    virtual ~Ships() {}
    void create_bot_ship(std::vector<std::vector<char>> &board, unsigned int ship_size, char ship_symbol);
};

class Carrier : public Ships
{
public:
    Carrier();
    void create_ship(std::vector<std::vector<char>> &board, std::string &is_error);
    void create_bot_ship(std::vector<std::vector<char>> &board);
protected:
    unsigned int ship_size;
    char ship_symbol;
    std::string ship_name;
};

class Battleship : public Ships
{
public:
    Battleship();
    void create_ship(std::vector<std::vector<char>> &board, std::string &is_error);
    void create_bot_ship(std::vector<std::vector<char>> &board);
protected:
    unsigned int ship_size;
    char ship_symbol;
    std::string ship_name;
};


class Destroyer : public Ships
{
public:
    Destroyer();
    void create_ship(std::vector<std::vector<char>> &board, std::string &is_error);
    void create_bot_ship(std::vector<std::vector<char>> &board);
protected:
    unsigned int ship_size;
    char ship_symbol;
    std::string ship_name;
};

class Submarine : public Ships
{
public:
    Submarine();
    void create_ship(std::vector<std::vector<char>> &board, std::string &is_error);
    void create_bot_ship(std::vector<std::vector<char>> &board);

protected:
    unsigned int ship_size;
    char ship_symbol;
    std::string ship_name;
};

class PatrolBoat : public Ships
{
public:
    PatrolBoat();
    void create_ship(std::vector<std::vector<char>> &board, std::string &is_error);
    void create_bot_ship(std::vector<std::vector<char>> &board);
protected:
    unsigned int ship_size;
    char ship_symbol;
    std::string ship_name;
};

#endif // SHIPS_H