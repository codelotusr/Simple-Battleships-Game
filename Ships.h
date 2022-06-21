#ifndef SHIPS_H
#define SHIPS_H


class Ships
{
public:
    virtual ~Ships() {}
    virtual void create_ship() = 0;
};

class Carrier : public Ships
{
public:
    void create_ship();
};

class Battleship : public Ships
{
public:
    void create_ship();
};

class Destroyer : public Ships
{
public:
    void create_ship();
};

class Submarine : public Ships
{
public:
    void create_ship();
};

class PatrolBoat : public Ships
{
public:
    void create_ship();
};

#endif // SHIPS_H