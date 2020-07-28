#include "Rhombus.hpp"

Rhombus::Rhombus(int diagonal, std::string name, std::string description) : Shape(name, description)
{
  this->diagonal = diagonal % 2 ? diagonal : diagonal + 1;
  
}

// 5.
double Rhombus::computeArea() const
{
  return pow(diagonal,2)/2;
}

// 6.
double Rhombus::computePerimeter() const
{
  return 2 * sqrt(2) * diagonal;
}


// 7.
int Rhombus::computeScreenArea() const
{
  int n { diagonal/2 };
  return 2*n*(n+1)+1;
}

// 8.
int Rhombus::computeScreenPerimeter() const
{
  return 2*(diagonal-1);
}

// 9.
void Rhombus::draw() const
{
  
}

int Rhombus::getBoundingBoxHeight() const
{
  return diagonal;
}

int Rhombus::getBoundingBoxWidth() const
{
  return diagonal;
}

