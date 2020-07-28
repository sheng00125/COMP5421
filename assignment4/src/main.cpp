#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Rhombus.hpp"
#include "AcuteTriangle.hpp"
#include "RightTriangle.hpp"
int main(int argc, char *argv[])
{
  // Some Examples

  Rectangle rect{ 5, 7 };
  std::cout << rect.toString() << std::endl;
  // or equivalently
  // std::cout << rect << std::endl;

  Rhombus ace { 16, "Ace", "Ace of diamond" };
  std::cout << ace.toString() << std::endl;
  //std::cout << ace << std::endl;

  AcuteTriangle at { 17 };
  std::cout << at.toString() << std::endl; // temp

  /* equivalently:
     Shape *atptr = &at;
     std::cout << *atptr << std::endl;

     Shape &atref = at;
     std::cout << atref << std::endl;
   */

  RightTriangle rt {10, "Carpenter's square"};
  std::cout << rt.toString() << std::endl; // temp
  return 0;
}
