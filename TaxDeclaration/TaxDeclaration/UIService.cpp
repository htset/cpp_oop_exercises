#include "UIService.h"
#include "Apartment.h"
#include "Store.h"
#include "Plot.h"

UIService::UIService(PersistenceService* _ps, StatisticsService* _ss)
{
  this->ps = _ps;
  this->ss = _ss;
}

void UIService::UIService::menu()
{
  int sel;
  TaxDeclaration td;
  do {
    cout << "Options: " << endl;
    cout << "--Transactions--" << endl;
    cout << "1: Add new Tax Declaration" << endl;
    cout << "2: Delete Tax Declaration: " << endl;
    cout << "3: Find Tax Declaration: " << endl;
    cout << "--Statistics--" << endl;
    cout << "11: Get total tax" << endl;
    cout << "12: Get Tax Declaration with highest tax" << endl;
    cout << endl << "0: exit" << endl;

    cout << "Your choice: ";
    cin >> sel;
    cin.ignore();

    switch (sel)
    {
    case 1:
      create();
      break;
    case 2:
      remove();
      break;
    case 3:
      search();
      break;
    case 11:
      cout << "Total Tax is: " << ss->getTotalTax();
      break;
    case 12:
      td = ss->getHighestDeclaration();
      cout << "Highest Tax Declaration is: " << endl;
      cout << td.toString() << endl;
      break;
    default:
      break;
    }
  } while (sel != 0);
}

void UIService::create()
{
  char sel = 'y';
  cout << "Enter person details" << endl;
  TaxDeclaration tax = enterTaxDeclarationDetails();

  cout << "Now enter properties: " << endl;
  while (sel == 'y')
  {
    Property* p = enterProperty();
    if (p != nullptr)
    {
      tax.addProperty(p);
      cout << "Property added" << endl;
    }
    else
      cout << "No property added (user aborted)" << endl;

    cout << "Would you like to add another property? (y/n)" << endl;
    cin >> sel;
    cin.ignore();
  }

  ps->insertTaxDeclaration(tax);
  cout << "Tax declaration added!" << endl;
}

void UIService::remove()
{
  char sel;
  string search_vat;
  int submissionYear;
  cout << "Enter VAT number for search: ";
  getline(cin, search_vat);
  cout << "Enter submission year: ";
  cin >> submissionYear;
  cin.ignore();
  vector<TaxDeclaration> td = ps->getTaxDeclarations(search_vat, submissionYear);

  if (td.size() == 1)
  {
    cout << "Found Tax Declaration:" << endl;
    cout << td[0].toString() << endl;
    cout << "Delete Tax Declaration? (y/n) " << endl;
    cin >> sel;

    if (sel == 'y')
    {
      ps->removeTaxDeclaration(td[0]);
      cout << " Tax declaration deleted" << endl;
    }
  }
  else
    cout << "tax declaration not found" << endl;
}

void UIService::search()
{
  char sel;
  string search_vat;
  int submissionYear;
  cout << "Enter VAT number for search (press return for all VATs): ";
  getline(cin, search_vat);
  cout << "Enter submission year (press 0 for all years): ";
  cin >> submissionYear;
  cin.ignore();

  vector<TaxDeclaration> td = ps->getTaxDeclarations(search_vat, submissionYear);
  cout << "-----Tax Declarations-----" << endl;
  for (auto iter = td.begin(); iter != td.end(); iter++)
    cout << iter->toString() << endl;
}

TaxDeclaration UIService::enterTaxDeclarationDetails()
{
  string name, surname, vat, tel;
  int year;
  cout << "Name: ";
  getline(cin, name);
  cout << endl << "Surname: ";
  getline(cin, surname);
  cout << endl << "VAT number: ";
  getline(cin, vat);
  cout << endl << "Telephone: ";
  getline(cin, tel);
  cout << endl << "Fiscal Year: ";
  cin >> year;
  cin.ignore();

  return TaxDeclaration(0, name, surname, vat, tel, year);
}

Address UIService::enterAddress()
{
  string street, number, zip, city;
  cout << "Street: ";
  getline(cin, street);
  cout << endl << "Number: ";
  getline(cin, number);
  cout << endl << "Zip code: ";
  getline(cin, zip);
  cout << endl << "City: ";
  getline(cin, city);

  return Address(street, number, zip, city);
}

Property* UIService::enterProperty()
{
  char sel, inside, cultivated;
  Address address;
  int surface, floor, commerciality;

  cout << "Select 1 for Apartment, 2 for Store, 3 for Plot, any other to abort: ";
  cin >> sel;
  cin.ignore();

  switch (sel)
  {
  case '1':
    address = enterAddress();
    cout << "Surface: ";
    cin >> surface;
    cout << "Floor: ";
    cin >> floor;
    cin.ignore();
    return new Apartment(0, surface, address, floor);
  case '2':
    address = enterAddress();
    cout << "Surface: ";
    cin >> surface;
    cout << "Commerciality: ";
    cin >> commerciality;
    cin.ignore();
    return new Store(0, surface, address, commerciality);
  case '3':
    address = enterAddress();
    cout << "Surface: ";
    cin >> surface;
    cout << "Inside town? ";
    cin >> inside;
    cout << "Cultivated?";
    cin >> cultivated;
    cin.ignore();
    return new Plot(0, surface, address, (inside == 'y') ? true : false, (cultivated == 'y') ? true : false);
  default:
    return nullptr;

  }
}

