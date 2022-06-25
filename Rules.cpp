#include "Rules.h"
#include <iostream>

Wectangle::Wectangle(double length, double width)
    : length(length), width(width) {}

Wectangle::~Wectangle() {}

void Wectangle::draw() const
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << "*";
        }
        std::cout << '\n';
    }
}

double Wectangle::area() const
{
    return length * width;
}

double Wectangle::perimeter() const
{
    return 2 * (length + width);
}

std::string Wectangle::get_name() const
{
    return name;
}

double Wectangle::get_length() const
{
    return length;
}

double Wectangle::get_width() const
{
    return width;
}

Triangle::Triangle(double base, double height)
    : base(base), height(height) {}

Triangle::~Triangle() {}

//make a function that draws a right triangle based on the base and height
void Triangle::draw() const
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << "*";
        }
        std::cout << '\n';
    }
}

double Triangle::area() const
{
    return (base * height) / 2;
}

double Triangle::perimeter() const
{
    return base + height + sqrt(pow(base, 2) + pow(height, 2));
}

std::string Triangle::get_name() const
{
    return name;
}

double Triangle::get_base() const
{
    return base;
}

double Triangle::get_height() const
{
    return height;
}




