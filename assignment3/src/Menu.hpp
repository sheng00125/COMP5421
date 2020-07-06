#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

class Menu
{
  std::vector<std::string> option_list;
  std::string top_msg;
  std::string bottom_msg;

public:
  Menu();

  void insert( int index, std::string& option );

  void push_back(std::string option);

  void remove(int index);

  int size() const;

  void pop_back();

  std::string get(int k);

  std::string toString() const;

  int read_option_number();
  
  void set_top_message(const std::string &m);
  void set_bottom_message(const std::string &m);

  void clear_top_message();
  void clear_bottom_message();

  bool isEmpty() const;
  
};

#endif /* MENU_H */
