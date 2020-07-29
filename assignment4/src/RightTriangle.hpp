#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Triangle.hpp"

class RightTriangle : public Triangle
{
public:
  RightTriangle(int base, std::string name = "Ladder", std::string description = "One right and two acute angles");

  // 6.
  double computePerimeter() const;
  
  // 7.
  int computeScreenArea() const;
  
  // 8.
  int computeScreenPerimeter() const;

  // 9.
  Grid draw(char fChar = '*', char bChar = ' ') const;

};


#endif /* RIGHTTRIANGLE_H */
