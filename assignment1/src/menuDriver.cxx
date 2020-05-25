#include <iostream>
#include "Text.h"
#include "Menu.h"

void demoText();
void demoMenu();

int main(int argc, char *argv[])
{

  //  demoText();
  demoMenu();
  return 0;
  
}

void demoMenu(){

  // 1. Create an empty menu
  Menu menu;
  
  std::cout << "*********************************************\n";
  // 2. Print an empty menu

  std::cout << menu << std::endl;
  
  std::cout << "*********************************************\n";
  // 3. Display the menu and read user's input
  
  int choice = menu.read_option_number();
  
  std::cout << "you entered: " << choice << std::endl;
  
  std::cout << "*********************************************\n";
  // 4. Add an option to our menu

  menu.push_back("Pepsi");
  std::cout << menu << std::endl;
  
  std::cout << "*********************************************\n";
  // 5. Let's add a couple of more options to our menu

  menu.push_back("Apple juice");
  menu.push_back("Root beer");
  choice = menu.read_option_number();
  std::cout << "you entered: " << choice << std::endl;
  
  std::cout << "*********************************************\n";
  // 6. Let's set the top and bottom messages

  menu.set_top_message("Choose your thirst crusher");
  menu.set_bottom_message("Enter a drink number");
  std::cout << menu << std::endl;

    std::cout << "*********************************************\n";
  // 7. Let's remove the last option and then insert a new option at number 2

  menu.pop_back();
  menu.insert(2, "Iced tea with lemon");
  choice = menu.read_option_number();
  std::cout << "you entered: " << choice << std::endl;

  std::cout << "*********************************************\n";
  // 8. The menu object lets you remove an option by option number.

  menu.pop_back();
  menu.remove(1);
  std::cout << menu << std::endl;

  std::cout << "*********************************************\n";
  // 9. The following segment removes the only remaining option, leaving the menu with an empty option list.

  menu.pop_back();
  std::cout << menu << std::endl;

  std::cout << "*********************************************\n";
  // 10. Here is our final example
  
  menu.clear_bottom_message();
  menu.set_top_message("Who Says You Can't Buy Happiness?\n"
		       "Just Consider Our Seriously Delicious Ice Cream Flavors");
  menu.set_bottom_message("Enter the number of your Happiness! ");
  menu.push_back("Bacon ice cream!");
  menu.push_back("Strawberry ice cream");
  menu.push_back("Vanilla ice cream");
  menu.push_back("Chocolate chip cookie dough ice cream");

  choice = menu.read_option_number();
  std::cout << "you entered: " << choice << std::endl;
}

void demoText()
{
  Text t1;
  Text t2("quick brown fox");
  Text t3{ t2 };

  std::cout << "t1: " << t1 << std::endl;
  std::cout << "t2: " << t2 << std::endl;
  std::cout << "t3: " << t3 << std::endl;

  t1.append("The ");
  std::cout << "t1: " << t1 << std::endl;
  t1.append(t2);
  std::cout << "t1: " << t1 << std::endl;

  t2 = Text(" jumps over ");
  std::cout << "t2: " << t2 << std::endl;

  t3.assign("a lazy dog");
  std::cout << "t3: " << t3 << std::endl;

  t1.append(t2);
  std::cout << "t1: " << t1 << std::endl;
  t1.append(t3);
  std::cout << "t1: " << t1 << std::endl;

  return;
  
}
