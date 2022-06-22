#ifndef SHIPS_H
#define SHIPS_H


class Ships
{
public:
    virtual ~Ships() {}
    virtual void create_ship() = 0;
    virtual int return_size() = 0;
    virtual char return_symbol() = 0;
};

class Carrier : public Ships
{
public:
    void create_ship();
    int return_size() const;
    char return_symbol() const;
protected:
    unsigned int ship_size = 5;
    char ship_symbol = 'C';
};

class Battleship : public Ships
{
public:
    void create_ship();
protected:
    unsigned int ship_size = 4;
    char ship_symbol = 'B';
};


class Destroyer : public Ships
{
public:
    void create_ship();
protected:
    unsigned int ship_size = 3;
    char ship_symbol = 'D';
};

class Submarine : public Ships
{
public:
    void create_ship();
protected:
    unsigned int ship_size = 3;
    char ship_symbol = 'S';
};

class PatrolBoat : public Ships
{
public:
    void create_ship();
protected:
    unsigned int ship_size = 2;
    char ship_symbol = 'P';
};

#endif // SHIPS_H