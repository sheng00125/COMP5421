#ifndef ACUTETRIANGLE_H
#define ACUTETRIANGLE_H

#include "Triangle.hpp"

class AcuteTriangle : public Triangle
{
public:
  AcuteTriangle(int base, std::string name = "Wedge", std::string description = "Three acute angles");

  // 6.
  double computePerimeter() const;
  
  // 7.
  int computeScreenArea() const;
  
  // 8.
  int computeScreenPerimeter() const;

  // 9.
  Grid draw(char fChar = '*', char bChar = ' ') const;

};


#endif /* ACUTETRIANGLE_H */
