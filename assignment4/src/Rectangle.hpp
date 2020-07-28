#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.hpp"

class Rectangle : public Shape
{
  int height;
  int width;
  
public:
  Rectangle(int height, int width, std::string name = "Rectangle", std::string description = "Four right angles");

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

#endif /* RECTANGLE_H */
