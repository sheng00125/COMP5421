#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <string>
#include "MiniDB.hpp"
#include "Menu.hpp"

class LineManager
{
   MiniDB<std::string> db;
   Menu FullMenu;
   Menu PartialMenu;

   std::size_t upper_span;
   std::size_t lower_span;
  
public:
  LineManager();
  void run();
};

#endif /* LINEMANAGER_H */
