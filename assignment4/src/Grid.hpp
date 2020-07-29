#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>

using Grid = std::vector<std::vector<char>>;
std::ostream& operator<<(std::ostream& os, const Grid& grid);

#endif /* GRID_H */


