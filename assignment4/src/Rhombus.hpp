#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Shape.hpp"

class Rhombus : public Shape
{
  int diagonal;
  
public:
  Rhombus(int diagonal, std::string name = "Diamond", std::string description = "Parallelogam with equal sides");

  // 5.
  double computeArea() const;

  // 6.
  double computePerimeter() const;

  // 7.
  int computeScreenArea() const;

  // 8.
  int computeScreenPerimeter() const;

  // 9.
  void draw() const;

  // 10.
  int getBoundingBoxHeight() const;

  // 11.
  int getBoundingBoxWidth() const;
  
};

#endif /* RHOMBUS_H */
