#include "Menu.hpp"

Menu::Menu()
{
   
}

void Menu::insert(int index, std::string& option)
{

  option_list.insert( option_list.begin() + index, option);
  
}

void Menu::push_back(std::string&option)
{
    option_list.insert( option_list.end(), option );
}

void Menu::remove(int index)
{
  auto it { option_list.begin() + index };
  
  option_list.erase(it);
}

int Menu::size() const
{
  return option_list.size();
}

void Menu::pop_back()
{
  option_list.erase( option_list.end() - 1 );
}

std::string Menu::get(int k)
{
  auto it { option_list.begin() + k };

  return *it;
}

std::string Menu::toString() const
{
  std::string prompt;

  prompt = top_message;

  /*
  for ( struct {std::vector<std::string>::const_iterator it; int idx;} v = {option_list.begin(), 1} ; v.it != option_list.end(); v.it++, v.idx++) {
    prompt += std::to_string(v.idx) + ". " + *(v.it) + "\n";    
  }
  */
  for ( auto it = option_list.begin() ; it != option_list.end(); ++it) {
    prompt += std::to_string(it - option_list.begin() + 1) + ". " + *it + "\n";    
  }
  
  prompt += bottom_message;
  
  return prompt;
}

int Menu::read_option_number()
{
  return 0;
}

void Menu::set_top_message(const std::string &m)
{
  top_message = m;
}

void Menu::set_bottom_message(const std::string &m)
{
  bottom_message = m;
}

void Menu::clear_top_message()
{
  top_message = "";
}

void Menu::clear_bottom_message()
{
  bottom_message = "";
}

bool Menu::isEmpty() const
{
  return option_list.size() == 0 ? true : false;
}
