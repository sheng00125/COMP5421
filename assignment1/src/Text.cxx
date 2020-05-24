#include <iostream>
#include "Text.h"

Text::Text() {

}

Text::Text(const Text& txt) {
  
  strcpy_s(pStore, 128, txt.pStore);
  
}

Text::Text(const char* pCstr) {

  strcpy_s(pStore, 128, pCstr);
  
}

void Text::assign(const char* pCstr) {


  strcpy_s(pStore, 128, pCstr);
    
}

Text Text::operator = (const Text & txt) {

  strcpy_s(pStore,128, txt.pStore);

  return *this;
}

void Text::append( const char* pCstr) {

  // suspectible to buffer overflow.
  strcat(pStore, pCstr);
}

void Text::append(const Text& txt) {
  
  strcat(pStore, txt.pStore);

}

void Text::clear() {

  pStore[0] = 0;

}

int Text::length() const {
 
  return strlen(pStore);
  
}

const char* Text::getCstring() const {

  return pStore;

}

bool Text::isEmpty() const {

  return pStore[0] == '\0';
  
}

Text::~Text() {
  
  delete pStore;
  
}

std::ostream& operator<<( std::ostream & sout, const Text& txt) {
  sout << txt.getCstring();
  return sout;
}
