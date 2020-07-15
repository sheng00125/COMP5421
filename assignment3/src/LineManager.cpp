#include "LineManager.hpp"


LineManager::LineManager()
{

  // setting top and bottom messages
  full_menu.set_top_message("Welcome to LineManager!\n=======================\n\nChoose one of the following options:\n");
  partial_menu.set_top_message("Welcome to LineManager!\n=======================\n\nChoose one of the following options:\n");


  std::vector<std::string> option_list { "append input from the keyboard",
					 "insert input from the keyboard",
					 "append input from text file",
					 "insert input from text file",
					 "print the current line",
					 "print a span of lines around the current position",
					 "set the length of upper or lower line spans",
					 "print all",
					 "move the current line",
					 "delete the current line",
					 "write mini database to file",
					 "quit"

  };

  
  full_menu.insert(0, option_list.at(0));
  full_menu.insert(1, option_list.at(1));
  full_menu.insert(2, option_list.at(2));
  full_menu.insert(3, option_list.at(3));
  full_menu.insert(4, option_list.at(4));
  full_menu.insert(5, option_list.at(5));
  full_menu.insert(6, option_list.at(6));
  full_menu.insert(7, option_list.at(7));
  full_menu.insert(8, option_list.at(8));
  full_menu.insert(9, option_list.at(9));
  full_menu.insert(10, option_list.at(10));
  full_menu.insert(11, option_list.at(11));

  partial_menu.insert(0, option_list.at(0));
  partial_menu.insert(1, option_list.at(1));
  partial_menu.insert(2, option_list.at(2));
  partial_menu.insert(3, option_list.at(3));
  partial_menu.insert(4, option_list.at(11));

  full_menu.set_bottom_message("Enter an option number\n??");
  partial_menu.set_bottom_message("Enter an option number\n??");

}

void LineManager::run()
{
  int option_number;

  while(1)
    {
      if ( db_store.size() == 0 )
	option_number =  partial_menu.read_option_number();
      else
	option_number = full_menu.read_option_number();

      if ( perform_action(option_number) == 12 )
	break;
    }
}

int LineManager::perform_action(int option_number)
{
  if ( db_store.size() == 0 && option_number == 5 )
    option_number = 12;
    
  switch(option_number)
    {
    case 1:
      append_input_from_the_keyboard();
      break;

    case 2:
      insert_input_from_the_keyboard();
      break;
      
    case 3:
      append_input_from_text_file();
      break;

    case 4:
      insert_input_from_text_file();
      break;

    case 5:
      print_the_current_line();
      break;
      
    case 6:
      print_a_span_of_lines_around_the_current_position();
      break;

    case 7:
      set_the_length_of_upper_or_lower_line_spans();
      break;

    case 8:
      print_all();
      break;

    case 9:
      move_the_current_line();
      break;

    case 10:
      delete_the_current_line();
      break;

    case 11:
      write_mini_database_to_file();
      break;

    case 12:
      quit();
      break;
  
    }
  
  return option_number;
}

void LineManager::append_input_from_the_keyboard() {

  std::string line;

  int idx = 1;
  
  while(1) {
    std::cout << idx << "-> ";
    
    std::getline(std::cin, line);

    if ( line == "." )
      break;
    
    db_store.append(line);
    idx++;
    
  }

}

void LineManager::insert_input_from_the_keyboard() {
  
  std::string line;

  int idx = 1;
  
  while(1) {
    std::cout << idx << "-> ";
    
    std::getline(std::cin, line);

    if ( line == "." )
      break;
    
    db_store.insert(line);
    idx++;
    
  }

}

void LineManager::append_input_from_text_file() {
  
}

void LineManager::insert_input_from_text_file() {
  
}

void LineManager::print_the_current_line() {

  std::cout << db_store.getCurrentIndex() + 1 << ": " << db_store.getValue() << std::endl;

}

void LineManager::print_a_span_of_lines_around_the_current_position() {

  int currentpositionidx = db_store.getCurrentIndex();

  int upperidx = currentpositionidx + upper_span;
  int loweridx = currentpositionidx + lower_span ;
  
  if (upperidx < 0)
    std::cout << "**BOF\n";

  for (int i = std::max(upperidx, 0); i < std::min(loweridx, static_cast<int>(db_store.size())); ++i) {
    db_store.moveToIndex(i);
    std::cout << db_store.getCurrentIndex() + 1 << ": " << db_store.getValue() << std::endl;
  }

  if (loweridx > db_store.size())
    std::cout << "**EOF\n";

}

void LineManager::set_the_length_of_upper_or_lower_line_spans() {
  
  std::string bad_data;
  int span;
  
  std::cout << "What's the length of the span\n";
  std::cin >> span;
  
  while ( ! std::cin )
    {
      std::cin.clear();
      std::getline(std::cin, bad_data);
      std::cout << "input must be an integer\n";
      std::cin >> span;
    }
  
  std::getline(std::cin, bad_data);

  if ( span < 0 ) {

    if ( !(span < -db_store.getCurrentIndex() ) )
      upper_span = span;
    else
      std::cout << "That's a large span of lines. Max is " << db_store.getCurrentIndex() << std::endl;
    
  }

    
  if ( span > 0 ) {
    
    if ( (! span > (db_store.size() - db_store.getCurrentIndex() - 1) ) )
      lower_span = span;
    else
      std::cout << "That's a large span of lines. Max is " << db_store.size() - db_store.getCurrentIndex() - 1 << std::endl;

  }

}

void LineManager::print_all() {

  db_store.moveToFirst();
  
  for (int i = 0; i < db_store.size(); ++i) {
    db_store.moveToIndex(i);
    std::cout << db_store.getCurrentIndex() + 1 << ": " << db_store.getValue() << std::endl;
  }
  
}

void LineManager::move_the_current_line() {
  
  std::string bad_data;
  int linenumber;
  
  std::cout << "which line do you want to move to?" << std::endl;
  std::cin >> linenumber;
  
  while ( ! std::cin )
    {
      std::cin.clear();
      std::getline(std::cin, bad_data);
      std::cout << "input must be an integer\n";
      std::cin >> linenumber;
    }
    
    std::getline(std::cin, bad_data);

    if (linenumber > 0 && linenumber <= db_store.size())
      db_store.moveToIndex(--linenumber);
    else
      std::cout << "invalid line number. line number must be between 0 and " << db_store.size() << std::endl;

}

void LineManager::delete_the_current_line() {
}

void LineManager::write_mini_database_to_file() {
}

void LineManager::quit() {
  // let the perform_action() return 12, which will break the while loop and hence quit.
}

  
