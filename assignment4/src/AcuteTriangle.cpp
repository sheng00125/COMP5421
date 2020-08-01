#include "AcuteTriangle.hpp"

AcuteTriangle::AcuteTriangle(int base, std::string name, std::string description) : Triangle(base % 2 ? base : base + 1, base % 2 ? (base / 2) + 1 : ((base + 1) / 2) + 1, name, description)
{
  
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
Grid AcuteTriangle::draw(char fChar, char bChar) const
{
  Grid ascii_art;

  for ( int i = 0; i < getBoundingBoxHeight(); ++i)
    {
      std::vector<char> row;
      
      for (int j = 0; j < getBoundingBoxWidth(); ++j)
	{
	  if ( j < base - ( base - 1 - i*2 ) / 2 && j >= ( base - 1 - i*2 ) / 2 )
	    row.push_back(fChar);
	  else
	    row.push_back(bChar);
	}
      ascii_art.push_back(row);
    }

  return ascii_art;
}
