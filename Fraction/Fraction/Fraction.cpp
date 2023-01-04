#include <iostream>
#include <vector>
using namespace std;

class Fraction
{
private:
  int nom; //nominator
  int denom; //denominator
public:
  Fraction()
  {
    nom = 0;
    denom = 1;
  }

  Fraction(int _nom, int _denom)
  {
    if (_denom == 0)
    {
      throw exception("Zero denominator!");
    }
    else
      denom = _denom;

    nom = _nom;
  }

  Fraction operator++() //prefix
  {
    nom = nom + denom;
    return Fraction(nom, denom);

    /*
    //alternative implementation:
    nom = nom + denom;
    return *this;
    */
  }

  Fraction operator++(int) //postfix
  {
    Fraction temp(nom, denom);
    nom = nom + denom;
    return temp;
  }

  Fraction operator + (Fraction f)
  {
    Fraction temp;
    temp.denom = denom * f.denom;
    temp.nom = nom * f.denom + denom * f.nom;
    return temp;
  }

  Fraction operator + (int x)
  {
    Fraction temp;
    temp.denom = denom;
    temp.nom = nom + x * denom;
    return temp;
  }

  Fraction operator - (Fraction f)
  {
    Fraction temp;
    temp.denom = denom * f.denom;
    temp.nom = nom * f.denom - denom * f.nom;
    return temp;
  }

  Fraction operator - (int x)
  {
    Fraction temp;
    temp.denom = denom;
    temp.nom = nom - x * denom;
    return temp;
  }

  void display()
  {
    cout << nom << "/" << denom << endl;
  }
};

int main()
{
  try
  {
    Fraction a(1, 2);
    Fraction b(3, 1);
    Fraction c;
    c = a + b;
    c.display();
    c = a + 4;
    c.display();

    Fraction d;
    d = ++a;
    d.display();

    Fraction e;
    e = a++;
    e.display();
  }
  catch (exception ex)
  {
    cout << ex.what();
  }

  return 0;
}