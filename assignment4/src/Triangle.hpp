#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.hpp"

class Triangle : public Shape
{
protected:
  int base;
  int height;
  
public:
  Triangle(int base, int height, std::string name, std::string description);

  // 5.
  double computeArea() const;

  // 6.
  virtual double computePerimeter() const = 0;

  // 7.
  virtual int computeScreenArea() const = 0;

  // 8.
  virtual int computeScreenPerimeter() const = 0;

  // 9.
  virtual void draw() const = 0;

  // 10.
  int getBoundingBoxHeight() const;

  // 11.
  int getBoundingBoxWidth() const;
  
};

#endif /* TRIANGLE_H */
