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

  menu.push_back("Pepsi");
  menu.push_back("Apple Juice");
  menu.push_back("Root Beer");
  menu.push_back("Root Beer");
  menu.push_back("Root Beer");
  menu.push_back("Root Beer");
  menu.insert(1, "testinsert");
  std::cout << menu.size() << std::endl;
  menu.pop_back();
  std::cout << menu.size() << std::endl;
  menu.push_back("newitem");
  std::cout << menu.size() << std::endl;

  
  std::cout << menu.toString() << std::endl;


  int choice = 0;
  
  while( (choice = menu.read_option_number()) <= 0 || choice > menu.size())
    {
	  std::cout << "Invalid choice " << choice << ". It must be in the range [1, " << menu.size() << "]" ;
    }

  std::cout << "you entered: " << choice << std::endl;

}
