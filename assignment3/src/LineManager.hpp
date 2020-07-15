#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <string>
#include "MiniDB.hpp"
#include "Menu.hpp"

// used in .cpp file
#include <iostream>
#include <algorithm>

class LineManager
{
  MiniDB<std::string> db_store;
  Menu full_menu;
  Menu partial_menu;

  std::size_t upper_span = -2;
  std::size_t lower_span = 2;

  int perform_action(int option_number);
  void readinput();
  
  void append_input_from_the_keyboard();
  void insert_input_from_the_keyboard();
  void append_input_from_text_file();
  void insert_input_from_text_file();
  void print_the_current_line();
  void print_a_span_of_lines_around_the_current_position();
  void set_the_length_of_upper_or_lower_line_spans();
  void print_all();
  void move_the_current_line();
  void delete_the_current_line();
  void write_mini_database_to_file();
  void quit();
  

  
public:
  LineManager();
  void run();
};

#endif /* LINEMANAGER_H */
