#include "MyString.h"

MyString::MyString()
{
  str = new char[1];
  str[0] = '\0';
}

MyString::MyString(const char* s)
{
  size_t length = strlen(s);
  str = new char[length + 1]; // +1 for '\0' character
  strcpy_s(str, length + 1, s);
}

MyString::MyString(const MyString& s)
{
  size_t length = strlen(s.str);
  str = new char[length + 1];
  strcpy_s(str, length + 1, s.str);
}

MyString::~MyString()
{
  delete[] str;
}

MyString& MyString::operator=(const MyString& s)
{
  if (str != nullptr)
    delete[]str;

  size_t length = strlen(s.str);
  str = new char[length + 1];
  strcpy_s(str, length + 1, s.str);

  return *this;
}

MyString& MyString::operator=(const char* s)
{
  if (str != nullptr)
    delete[]str;

  size_t length = strlen(s);
  str = new char[length + 1];
  strcpy_s(str, length + 1, s);

  return *this;
}

MyString MyString::operator+(const MyString s)
{
  size_t length1 = strlen(str);
  size_t length2 = strlen(s.str);
  size_t total_length = length1 + length2 + 1;

  char* temp_str = new char[total_length];
  strcpy_s(temp_str, total_length, str);
  strcat_s(temp_str, total_length, s.str);

  MyString temp(temp_str);

  return temp;
}

MyString MyString::operator+(const char* s)
{
  size_t length1 = strlen(str);
  size_t length2 = strlen(s);
  size_t total_length = length1 + length2 + 1;

  char* temp_str = new char[total_length];
  strcpy_s(temp_str, total_length, str);
  strcat_s(temp_str, total_length, s);

  MyString temp(temp_str);

  return temp;
}

bool MyString::operator==(const MyString s)
{
  return strcmp(str, s.str) == 0;
}

char& MyString::operator[](size_t pos)
{
    return str[pos];
}

size_t MyString::length()
{
  return strlen(str);
}

ostream& operator<<(ostream& output, const MyString& s)
{
  output << s.str;
  return output;  // for multiple << operator chaining
}

istream& operator >> (istream& input, MyString& s)
{
  char input_string[200];

  input >> input_string;

  if (s.str != nullptr)
    delete[]s.str;

  s.str = new char[strlen(input_string) + 1];
  strcpy_s(s.str, strlen(input_string) + 1, input_string);

  return input;
}
