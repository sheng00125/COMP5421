#include "Triangle.hpp"

Triangle::Triangle(int base, int height, std::string name, std::string description) : Shape(name, description)
{
  this->base = base;
  this->height = height;
}

// 5.
double Triangle::computeArea() const
{
  return height * base / 2.0;

}

// 10.
int Triangle::getBoundingBoxHeight() const
{
  return height;
}

// 11.
int Triangle::getBoundingBoxWidth() const
{
  return base;
}
