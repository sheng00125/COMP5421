#ifndef MENU_H
#define MENU_H

#include "Text.h"
#include <iostream>
#include <string>

class Menu
{

  Text* option_list;

  int capacity;

  int count;

  Text top_message;

  Text bottom_message;

  void double_capacity();
  
public:
  Menu();

  Menu( const Menu& mnu );

  virtual ~Menu();

  Menu & operator=(const Menu & m);

  void insert(int index, Text& option);

  void insert(int index, const char* option);

  void push_back(const char* pOption);

  void push_back(const Text& option);

  void remove(int index);

  int size() const;

  int getCapacity() const;

  void pop_back();

  Text get(int k);

  Text toString() const;

  int read_option_number();

  void set_top_message(const Text& m);

  void set_bottom_message(const Text& m);

  void clear_top_message();

  void clear_bottom_message();
  
  bool isEmpty() const;
  
};

std::ostream& operator<<(std::ostream &, const Menu&);

#endif
