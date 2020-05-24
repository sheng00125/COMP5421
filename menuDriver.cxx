#include <iostream>
#include "Menu.h"

void demoMenu();

int main(int argc, char *argv[])
{
  //std::cout << "begin main.\n";
  demoMenu();
  return 0;
  
}

void demoMenu(){

  Menu menu;

  std::cout << menu << std::endl;


  int choice = 0;
  
  while( (choice = menu.read_option_number()) <= 0  )
    {
      std::cout << "You must enter a valid integer.\n" ;
    }

  std::cout << "you entered: " << choice << std::endl;

}
