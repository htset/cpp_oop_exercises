#include "UIService.h"
UIService::UIService(vector<Package*>* _packages)
{
  packages = _packages;
}

void UIService::menu()
{
  int option;
  do
  {
    cout << "Options: " << endl;
    cout << "1) Add package " << endl;
    cout << "2) Search package " << endl;
    cout << "3) Delete package " << endl;
    cout << "4) View all packages " << endl;
    cout << "0) Exit " << endl;
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1:
      addPackage();
      break;
    case 2:
      searchPackage();
      break;
    case 3:
      deletePackage();
      break;
    case 4:
      listPackages();
      break;
    case 0:
      break;
    default:
      cout << "Please type again:";
      break;
    }
  } while (option != 0);
}

void UIService::addPackage()
{
  int option;
  string recipient_name, recipient_address;
  float weight;

  cout << "Type of package (1-Basic, 2-Advanced, 3-Overnight)" << endl;
  cin >> option;
  cin.ignore();
  cout << "Recipient name: " << endl;
  getline(cin, recipient_name);
  cout << "Recipient address: " << endl;
  getline(cin, recipient_address);
  cout << "Weight (kilos):" << endl;
  cin >> weight;
  cin.ignore();

  switch (option)
  {
  case 1:
    packages->push_back(new BasePackage(recipient_name, recipient_address, weight, Date()));
    saveToFile();
    break;
  case 2:
    packages->push_back(new AdvancedPackage(recipient_name, recipient_address, weight, Date()));
    saveToFile();
    break;
  case 3:
    packages->push_back(new OvernightPackage(recipient_name, recipient_address, weight, Date()));
    saveToFile();
    break;
  default:
    break;
  }
}

void UIService::searchPackage()
{
  string recipient_name;
  cout << "Enter recipient name (also partial): ";
  getline(cin, recipient_name);

  for (int i = 0; i < (*packages).size(); i++)
  {
    if ((*packages)[i]->getRecipient().find(recipient_name) != string::npos)
    {
      cout << (*packages)[i]->toString();
    }
  }
}

void UIService::deletePackage()
{
  string recipient_name;
  cout << "Enter recipient name (also partial): ";
  getline(cin, recipient_name);

  cout << "The following packages were found:" << endl;
  for (int i = 0; i < (*packages).size(); i++)
  {
    if ((*packages)[i]->getRecipient().find(recipient_name) != string::npos)
    {
      cout << "Package no. " << i + 1 << ":" << endl;
      cout << (*packages)[i]->toString();
    }
  }

  int option;
  cout << "Please enter the no. of package to delete (0 to cancel): ";
  cin >> option;
  cin.ignore();

  if (option > 0)
    packages->erase(packages->begin() + option - 1);

  cout << "package deleted" << endl;
  saveToFile();
}

void UIService::listPackages()
{
  for (int i = 0; i < (*packages).size(); i++)
  {
    cout << (*packages)[i]->toString();
  }
}

void UIService::saveToFile()
{
  ofstream ofs("packages.txt");
  for (int i = 0; i < (*packages).size(); i++)
  {
    ofs << (*packages)[i]->serialize();
  }
}

void UIService::loadFromFile()
{
  packages->clear();

  ifstream ifs("packages.txt", ios::in);
  if (ifs)
  {
    string package_str;
    string temp_str;
    while (getline(ifs, temp_str))
    {
      if (temp_str.find("--") == 0)
      {
        Package* p;
        if (package_str.find("Base Package") == 0)
          p = new BasePackage();
        else if (package_str.find("Advanced Package") == 0)
          p = new AdvancedPackage();
        else if (package_str.find("Overnight Package") == 0)
          p = new OvernightPackage();
        else
        {
          cout << "error loading packages. Exiting.." << endl;
          exit(0);
        }
        p->deserialize(package_str);
        packages->push_back(p);
        package_str = "";
      }
      else
      {
        package_str += temp_str + "\n";
      }
    }
  }
  else
    cout << "Packages file not found" << endl;
}
