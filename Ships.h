#ifndef SHIPS_H
#define SHIPS_H
#include "Game.h"
#include "GameBoard.h"


class Ships : public Game
{
public:
    Ships() = default;
    virtual ~Ships() {}
    void print_ships(std::string, std::vector<std::vector<char>>);
};

class Carrier : public Ships
{
public:
    Carrier();
    void create_ship();
    int return_size() const;
    char return_symbol() const;
protected:
    unsigned int ship_size;
    char ship_symbol;
};

class Battleship : public Ships
{
public:
    Battleship();
    void create_ship();
    int return_size() const;
    char return_symbol() const;
protected:
    unsigned int ship_size;
    char ship_symbol;
};


class Destroyer : public Ships
{
public:
    Destroyer();
    void create_ship();
    int return_size() const;
    char return_symbol() const;
protected:
    unsigned int ship_size;
    char ship_symbol;
};

class Submarine : public Ships
{
public:
    Submarine();
    void create_ship();
    int return_size() const;
    char return_symbol() const;

protected:
    unsigned int ship_size;
    char ship_symbol;
};

class PatrolBoat : public Ships
{
public:
    PatrolBoat();
    void create_ship();
    int return_size() const;
    char return_symbol() const;
protected:
    unsigned int ship_size;
    char ship_symbol;
};

#endif // SHIPS_H