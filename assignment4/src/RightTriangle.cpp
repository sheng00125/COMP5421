#include "RightTriangle.hpp"

RightTriangle::RightTriangle(int base, std::string name , std::string description ) : Triangle(base, base, name, description)
{
  
}

// 6.
double RightTriangle::computePerimeter() const
{
  return (2 + sqrt(2)) * height;
}

// 7.
int RightTriangle::computeScreenArea() const
{
  return height * ( height + 1 ) / 2;
}

//8.
int RightTriangle::computeScreenPerimeter() const
{
  return 3 * (height - 1);
}

//9.
Grid RightTriangle::draw(char fChar, char bChar) const
{
  Grid ascii_art;

  for (int i = 0; i < getBoundingBoxHeight(); ++i)
    {
      std::vector<char> row;
      
      for (int j = 0; j < getBoundingBoxWidth(); ++j) {
	if (j <= i)
	  row.push_back(fChar);
	else
	  row.push_back(bChar);
      }
      ascii_art.push_back(row);
    }
  
  return ascii_art;
}
