#include <iostream>
#include "LineManager.hpp"


LineManager::LineManager()
{

  // setting top and bottom messages
  full_menu.set_top_message("Welcome to LineManager!\n=======================\n\nChoose one of the following options:\n");
  partial_menu.set_top_message("Welcome to LineManager!\n=======================\n\nChoose one of the following options:\n");

  full_menu.set_bottom_message("Enter an option number\n??");
  partial_menu.set_bottom_message("Enter an option number\n??");

  // setting option list

  std::string menuitem1 = "Hey there!";
  partial_menu.insert(0, menuitem1);
  
}

void LineManager::run()
{
  if ( db_store.size() == 0 )
    std::cout << partial_menu.toString();
  
}
