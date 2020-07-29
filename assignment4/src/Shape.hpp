#ifndef SHAPE_H

#define SHAPE_H

#include <string>
#include <vector>

#include <iostream>
#include <sstream>
#include <iomanip>

#include <typeinfo>

#include <cmath>

#include "Grid.hpp"

class Shape
{
  static int count;
  
  int id;
  std::string name;
  std::string description;
  
public:

  // 1. A constructor that accepts and sets the initial value of the shape's name and description.
  Shape(std::string name, std::string description);

  // 2.
  int getId() const;
  std::string getName() const;
  std::string getDescription() const;

  // 3.
  void setName(std::string name);
  void setDescription(std::string description);

  // 4.
  std::string toString() const;

  // 5.
  virtual double computeArea() const = 0;

  // 6.
  virtual double computePerimeter() const = 0;

  // 7.
  virtual int computeScreenArea() const = 0;

  // 8.
  virtual int computeScreenPerimeter() const = 0;

  // 9.
  virtual Grid draw(char fChar = '*', char bChar = ' ') const = 0;

  // 10.
  virtual int getBoundingBoxHeight() const = 0 ;

  // 11.
  virtual int getBoundingBoxWidth() const = 0;

  // allow '<< obj', instead of '<< obj.toString()'
  friend std::ostream& operator<<(std::ostream&  os, const Shape& shape);
};

#endif /* SHAPE_H
 */
