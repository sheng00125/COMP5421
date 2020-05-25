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
  /*
  while( (choice = menu.read_option_number()) <= 0 )
    {
      std::cout << "You must enter a valid integer.\n" ;
    }
  std::cout << "you entered: " << choice << std::endl;
  */
  
  menu.set_top_message("Choose your thirst crusher");
  
  menu.set_bottom_message("Enter a drink number");
  
  std::cout << menu << std::endl;

  Menu newmenu = menu;

  newmenu.set_top_message("I'm newer and better. Which thirst curhser you want m8?");

  std::cout << newmenu << std::endl;  

  /*
    menu.clear_bottom_message();
    menu.set_top_message("Who Says You Can't Buy Happiness?\n"
    "Just Consider Our Seriously Delicious Ice Cream Flavors");
    menu.set_bottom_message("Enter the number of your Happiness! ");
    menu.push_back("Bacon ice cream!");
    menu.push_back("Strawberry ice cream");
    menu.push_back("Vanilla ice cream");
    menu.push_back("Chocolate chip cookie dough ice cream");
    choic = menu.read_option_number();e
    std::cout << "you entered: " << choice << std::endl;
  */
  
}
