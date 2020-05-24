#include <iostream>

class Text
{
  char *pStore = new char[128]{'\0'};
  
 public:
  char irrelevant = 'A';
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
