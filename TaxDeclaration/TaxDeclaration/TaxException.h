#include <iostream>
using namespace std;

#ifndef _TAXEXCEPTION_H
#define _TAXEXCEPTION_H

class TaxException
{
public:
  string message;
  int code;

  TaxException(string _message, int _code)
  {
    message = _message;
    code = _code;
  }
};

#endif // !_TAXEXCEPTION_H
