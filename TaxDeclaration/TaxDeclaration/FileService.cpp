#include "FileService.h"

FileService::FileService(string _filename)
{
  filename = _filename;
  loadFromFile();
}

vector<TaxDeclaration> FileService::getTaxDeclarations(string vat = "", int submissionYear = 0)
{
  if (vat == "" && submissionYear == 0)
    return declarations;

  vector<TaxDeclaration> ret;
  for (auto iter = declarations.begin(); iter != declarations.end(); iter++)
  {
    if (vat != "")
    {
      if (submissionYear != 0)
      {
        if (iter->getVat() == vat && iter->getSubmissionYear() == submissionYear)
        {
          cout << "Found Tax Declaration.  " << endl;
          ret.push_back(*iter);
        }
      }
      else {
        if (iter->getVat() == vat)
        {
          cout << "Found Tax Declaration.  " << endl;
          ret.push_back(*iter);
        }
      }
    }
    else
    {
      if (submissionYear != 0)
      {
        if (iter->getSubmissionYear() == submissionYear)
        {
          cout << "Found Tax Declaration.  " << endl;
          ret.push_back(*iter);
        }

      }
    }
    return ret;
  }
}

void FileService::insertTaxDeclaration(TaxDeclaration td)
{
  declarations.push_back(td);
  saveToFile();
  cout << "Tax declaration added!" << endl;
}

void FileService::removeTaxDeclaration(TaxDeclaration td)
{
  for (auto iter = declarations.begin(); iter != declarations.end(); iter++)
  {
    if (iter->getVat() == td.getVat() && iter->getSubmissionYear() == td.getSubmissionYear())
    {
      iter = declarations.erase(iter);
      break;
    }
  }
  saveToFile();
}

void FileService::loadFromFile()
{
  ifstream ifs(filename);
  string str;
  vector<string> strings;

  declarations.clear();

  while (getline(ifs, str))
  {
    if (str.find("--") == 0)
    {
      TaxDeclaration td;
      td.deserialize(strings);
      declarations.push_back(td);
      strings.clear();
    }
    else
      strings.push_back(str);
  }
}

void FileService::saveToFile()
{
  ofstream ofs(filename);

  for (auto it = declarations.begin(); it != declarations.end(); it++)
  {
    ofs << it->serialize();
  }
}
