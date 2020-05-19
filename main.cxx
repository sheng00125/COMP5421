#include "Text.h"
#include <iostream>

void demoText();

int main(int argc, char *argv[])
{
  demoText();
  return 0;
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
