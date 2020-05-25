#include <iostream>
#include "Menu.h"

Menu::Menu()
{
  this->top_message = "";
  this->bottom_message = "";
  this->capacity = 1;
  this->count = 0;
  this->option_list = new Text[1];
}


Menu::Menu( const Menu& mnu ){
  
  std::cout << "inside the assignment constructor, this is " << this << '\n';
    
  *this = mnu;
    
}

Menu::~Menu() {

	delete[] this->option_list;
}

Menu &Menu::operator=(const Menu & m) {

  std::cout << "inside the assignment operator, this is " << this << " and m is " << &m << "\n" ;
  
  this->option_list = m.option_list;
  this->capacity = m.capacity;
  this->count = m.count;
  this->top_message = m.top_message;
  this->bottom_message = m.bottom_message;

  return *this;
}

void Menu::double_capacity()
{
	this->capacity *= 2;
	Text* tmp = new Text[this->capacity];
	for (int i = 0; i < this->count; i++)
	{
		tmp[i] = this->option_list[i];
	}
	this->option_list = tmp;
}

void Menu::insert(int index, Text& option) {
	if (index > this->count)
		return;

	if (this->count == this->capacity)
		this->double_capacity();

	for (int i = this->count-1, j = this->count; j > index; i--, j--)
	{
		this->option_list[j] = this->option_list[i];
	}
	this->option_list[index] = option;
	this->count++;
}

void Menu::insert(int index, const char* option){
	if (index > this->count)
		return;

	if (this->count == this->capacity)
		this->double_capacity();

	for (int i = this->count - 1, j = this->count; j > index; i--, j--)
	{
		this->option_list[j] = this->option_list[i];
	}
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

  if (!this->top_message.isEmpty())
    promptmsg.append(this->top_message); promptmsg.append("\n");


  for (int i = 0; i < count; ++i) {
    promptmsg.append(option_list[i]);
  }
  
  if (!this->bottom_message.isEmpty())
    promptmsg.append(this->bottom_message); promptmsg.append("\n");

  promptmsg.append("??");

  
  return promptmsg;

}

int Menu::read_option_number() {

  int choice;

  std::cin >> choice;
  
  if (std::cin.fail())
    choice = -1;

  std::cin.clear(); // clear buffer
  std::cin.ignore(INT_MAX, '\n'); // do not consider '\n' as input.
 
  return choice;
  
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

std::ostream& operator<<(std::ostream & sout, const Menu& m)
{
    sout << m.toString(); 
  return sout;
}
