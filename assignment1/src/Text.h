#ifndef TEXT_H
#define TEXT_H
#include <iostream>
const int MAX_SIZE = 1024;

class Text

{
  char *pStore;
  
 public:

  Text();

  Text(const Text& txt);

  Text(const char* pCstr);

  void assign(const char* pCstr);
  
  Text operator = (const Text& txt);

  void append(const char* pCstr);

  void append(const Text& txt);

  void clear();

  int length() const;

  bool isEmpty() const;
  
  const char* getCstring() const;
  
  virtual ~Text();
};

std::ostream& operator<<(std::ostream & sout, const Text& txt);

#endif
