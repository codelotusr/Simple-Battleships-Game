#ifndef RULES.H
#define RULES.H


class Vehicle
{
public:
    virtual void print_vehicle() = 0;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};


class AircraftCarrier : public Vehicle
{
public:
    void print_vehicle() override;
    double area() const override;
    double perimeter() const override;
};

//create a class for the battleship
class Battleship : public Vehicle
{
public:
    void print_vehicle() override;
    double area() const override;
    double perimeter() const override;
};

//create a class for the destroyer
class Destroyer : public Vehicle
{
public:
    void print_vehicle() override;
    double area() const override;
    double perimeter() const override;
};

//create a class for the submarine
class Submarine : public Vehicle
{
public:
    void print_vehicle() override;
    double area() const override;
    double perimeter() const override;
};

//create a class for the patrol boat
class PatrolBoat : public Vehicle
{
public:
    void print_vehicle() override;
    double area() const override;
    double perimeter() const override;
};








#endif