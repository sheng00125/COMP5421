#include "RightTriangle.hpp"

RightTriangle::RightTriangle(int base, std::string name , std::string description ) : Triangle(base, base, name, description)
{
  
}

// 6.
double RightTriangle::computePerimeter() const
{
  return (2 + sqrt(2)) * height;
}

// 7.
int RightTriangle::computeScreenArea() const
{
  return height * ( height + 1 ) / 2;
}

//8.
int RightTriangle::computeScreenPerimeter() const
{
  return 3 * (height - 1);
}

//9.
void RightTriangle::draw() const
{
  
}
