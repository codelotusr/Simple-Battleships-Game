#ifndef RULES_H
#define RULES_H
#include <cmath>
#include <string>

class Shape
{
public:
    virtual void draw() const = 0;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Wectangle : public Shape
{
public:
    Wectangle(double length, double width);
    ~Wectangle();
    void draw() const override;
    double area() const override;
    double perimeter() const override;
    std::string get_name() const;
    double get_length() const;
    double get_width() const;
private:
    double length;
    double width;
    std::string name = "Rectangle";
};

class Triangle : public Shape
{
public:
    Triangle(double base, double height);
    ~Triangle();
    void draw() const override;
    double area() const override;
    double perimeter() const override;
    std::string get_name() const;
    double get_base() const;
    double get_height() const;
private:
    double base;
    double height;
    std::string name = "Triangle";
};



#endif