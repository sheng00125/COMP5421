#include <iostream>
#include "Menu.h"

Menu::Menu() {
  this->top_message = "";
  this->bottom_message = "";
  this->capacity = 1;
  this->count = 0;
  this->option_list = new Text[1];
}


Menu::Menu( const Menu& mnu ){
    
  *this = mnu;
}

Menu::~Menu() {

  delete[] this->option_list;
}

Menu &Menu::operator=(const Menu & m) {

  this->option_list = m.option_list;
  this->capacity = m.capacity;
  this->count = m.count;
  this->top_message = m.top_message;
  this->bottom_message = m.bottom_message;

  return *this;
}

void Menu::double_capacity() {
  this->capacity *= 2;
  Text* tmp = new Text[this->capacity];
  for (int i = 0; i < this->count; i++)
    {
      tmp[i] = this->option_list[i];
    }
  delete[] this->option_list;
  this->option_list = tmp;
}

void Menu::insert(int index, Text& option) {
  index--;
  if (index > this->count)
    return;

  if (this->count == this->capacity)
    this->double_capacity();

  for (int i = this->count-1, j = this->count; j > index; i--, j--)
    {
      this->option_list[j] = this->option_list[i];
    }
  std::cout << "Option inserted successfully!\n";
  this->option_list[index] = option;
  this->count++;
}

void Menu::insert(int index, const char* option){
  index--;
  if (index > this->count)
    return;

  if (this->count == this->capacity)
    this->double_capacity();

  for (int i = this->count - 1, j = this->count; j > index; i--, j--)
    {
      this->option_list[j] = this->option_list[i];
    }

  std::cout << "Option inserted successfully!\n";
  this->option_list[index] = Text(option);
  this->count++;
}

void Menu::push_back(const char* pOption) {
  if (this->count == this->capacity)
    this->double_capacity();

  this->option_list[this->count] = Text(pOption);
  this->count++;
}

void Menu::push_back(const Text& option) {
  if (this->count == this->capacity)
    this->double_capacity();

  this->option_list[this->count] = option;
  this->count++;
}					  

void Menu::remove(int index) {
  index--; 
  if (index > this->count - 1)
    return;

  //shift the array elements to the left
  for (int i = index, j = index+1; j < this->count; i++, j++)
    {
      this->option_list[i] = this->option_list[j];
    }
  this->count--;

}

int Menu::size() const {

  return this->count;
}

int Menu::getCapacity() const {

  return this->capacity;
}

void Menu::pop_back() {
  if (this->count == 0)
    return;
  this->count--;
}

Text Menu::get(int k) {

  return option_list[k];
}

Text Menu::toString() const {

  Text promptmsg;

  promptmsg.append("\n");
  if (!this->top_message.isEmpty())
    {
      promptmsg.append(this->top_message);
      promptmsg.append("\n");
    }

  for (int i = 0; i < count; ++i) {
    promptmsg.append("   ");
    promptmsg.append(std::to_string(i+1).c_str());
    promptmsg.append(". ");
    promptmsg.append(option_list[i]);
    promptmsg.append("\n");
  }
    
  if (!this->bottom_message.isEmpty())
    {
      promptmsg.append(this->bottom_message);
      promptmsg.append("\n");
    }
  promptmsg.append("??");
    
  return promptmsg;

}

int Menu::read_option_number() {
  
  int choice = 0 ;

  while( 1 ) {

    std::cout << *this;

    std::cin >> choice;
    std::cin.clear(); // clear buffer
    std::cin.ignore(INT_MAX, '\n'); // do not consider '\n' as input.

    if ( choice == 0) {
      std::cout << "Please enter an integer that is greater than 0.\n";
      continue;
    }

    if ( this->size() == 0 ) {
      return choice;
    }
    
    if ( choice < 0 || this->size() < choice ) {
      std::cout << "Invalid choice " << choice << ". Input must be an integer in the range [1, " << this->size() << "]\n" ;
    } else {
      return choice;
    }
  }
}

void Menu::set_top_message(const Text& m) {

  this->top_message = m;
}

void Menu::set_bottom_message(const Text& m) {

  this->bottom_message = m;
}

void Menu::clear_top_message() {

  this->top_message = "";
}

void Menu::clear_bottom_message() {

  this->bottom_message = "";
}
  
bool Menu::isEmpty() const {

  return count == 0 ? 0 : 1;
}

std::ostream& operator<<(std::ostream & sout, const Menu& m) {
  
  sout << m.toString(); 
  return sout;
}
