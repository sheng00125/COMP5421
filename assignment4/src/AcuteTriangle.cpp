#include "AcuteTriangle.hpp"

AcuteTriangle::AcuteTriangle(int base, std::string name, std::string description) : Triangle(base % 2 ? base : base + 1, (base + 1)/2, name, description)
{
  std::cout << "Constructing";
}

// 6.
double AcuteTriangle::computePerimeter() const
{
  //return 0;
  return base + sqrt( pow(base,2) + 4 * pow(height,2) );
}

// 7.
int AcuteTriangle::computeScreenArea() const
{
  return pow(height, 2);
}

//8.
int AcuteTriangle::computeScreenPerimeter() const
{
  return 4 * ( height - 1);
}

//9.
void AcuteTriangle::draw() const
{
  

}
