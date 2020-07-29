#include "Grid.hpp"

std::ostream& operator<<(std::ostream& os, const Grid& grid)
{
  for (const auto& row : grid)
    {
      for (const auto& element : row )
      {
	os << element;
      }
      os << std::endl;
    }
  return os;
}
