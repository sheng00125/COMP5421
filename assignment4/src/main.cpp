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
  // std::cout << ace.toString() << std::endl;
  // or, equivalently:
  std::cout << ace << std::endl;

  AcuteTriangle at { 17 };
  std::cout << at << std::endl;

  /* equivalently:
     Shape *atptr = &at;
     std::cout << *atptr << std::endl;

     Shape &atref = at;
     std::cout << atref << std::endl;
  */

  RightTriangle rt {10, "Carpenter's square"};
  std::cout << rt << std::endl;

  ////////////////////////////////////////////////

  Grid aceBox = ace.draw('+', '.');
  std::cout << aceBox << std::endl;

  Grid rectBox = rect.draw('+', '.');
  std::cout << rectBox << std::endl;
  
  Grid atBox = at.draw('^');
  std::cout << atBox << std::endl;

  Grid rtBox = rt.draw('-');
  std::cout << rtBox << std::endl;

  rtBox = rt.draw('\\','o');
  std::cout << rtBox << std::endl;

  aceBox = ace.draw('o');
  std::cout << aceBox << std::endl;
  
  return 0;
}
