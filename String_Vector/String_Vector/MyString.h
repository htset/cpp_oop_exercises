#include <iostream>
using namespace std;

class MyString
{
  char* str;

public:
  MyString();
  MyString(const char* s);
  MyString(const MyString& s);
  ~MyString();
  MyString& operator=(const MyString& s);
  MyString& operator=(const char* s);
  MyString operator+(const MyString s);
  MyString operator+(const char* s);
  bool operator==(const MyString s);
  char& operator[](size_t pos);
  size_t length();
  friend ostream& operator<<(ostream&, const MyString&);
  friend istream& operator>>(istream&, MyString&);
};

