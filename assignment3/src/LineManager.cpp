#include <iostream>
#include "LineManager.hpp"


LineManager::LineManager()
{
    
}

void LineManager::run()
{
  db.insert("HI");
  db.append("YO!");
  db.remove();
  std::cout << db.getCurrentIndex();


}
