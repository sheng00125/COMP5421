#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <string>
#include "MiniDB.hpp"
#include "Menu.hpp"

class LineManager
{
   MiniDB<std::string> db_store;
   Menu full_menu;
   Menu partial_menu;

   std::size_t upper_span = 2;
   std::size_t lower_span = 2;
  
public:
  LineManager();
  void run();
};

#endif /* LINEMANAGER_H */
