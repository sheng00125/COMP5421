#include "Rectangle.hpp"

Rectangle::Rectangle(int height, int width, std::string name, std::string description) : Shape(name, description)
{
  this->height = height;
  this->width = width;
  
}

// 5.
double Rectangle::computeArea() const
{
  return  height * width;
}

// 6.
double Rectangle::computePerimeter() const
{
  return 2 * (height + width);
}

// 7.
int Rectangle::computeScreenArea() const
{
  return height * width;
}

// 8.
int Rectangle::computeScreenPerimeter() const
{
  return 2 * (height + width) - 4;
}

// 9.
void Rectangle::draw() const
{
  
}

int Rectangle::getBoundingBoxHeight() const
{
  return height;
}

int Rectangle::getBoundingBoxWidth() const
{
  return width;
}
