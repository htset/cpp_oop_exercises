#include <iostream>
#include "MyString.h"
#include "MyVector.h"
#define DEFAULT_SIZE 10
using namespace std;

int main()
{
  MyString ms1;
  MyString ms2("hello world");
  MyString ms3(ms2);
  MyString ms4 = ms2 + ms3;

  cout << ms4 << endl;
	cout << "Please type \"hello\": ";
  cin >> ms1;

  if (ms1 == "hello")
    cout << "thanks!" << endl;
  else
    cout << "You did not insert \"hello\"" << endl;

  ms2[0] = 'H';
	cout << ms2 << endl;

  cout << "Vector" << endl;
  MyVector<MyString> v;
  v.push_back(ms1);
  v.push_back(ms2);
  v.push_back(ms3);
  v.push_back(ms4);

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << endl;
  }

  return 0;
}
