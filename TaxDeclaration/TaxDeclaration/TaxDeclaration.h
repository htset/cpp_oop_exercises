#include <iostream>
#include <string>
#include <vector>
#include "Address.h"
#include "Property.h"

using namespace std;

#ifndef _TAXDECLARATION_H_
#define _TAXDECLARATION_H_

class TaxDeclaration
{
private:
	int id;
	string name;
	string surname;
	string vat;
	string phone;
	int submissionYear;
	vector<Property*> properties;

	void parseDetails(string s);
public:
	TaxDeclaration(int, string, string, string, string, int);
	TaxDeclaration() = default;
	string toString();
	int getId() { return id; }
	string getName() { return name; }
	void setName(string _name) { name = _name; }
	string getSurname() { return surname;  }
	void setSurname(string _surname) { surname = _surname; }
	string getVat() { return vat; }
	void setVat(string _vat) { vat = _vat; }
	string getPhone() { return phone; }
	void setPhone(string _phone) { phone = _phone; }
	int getSubmissionYear() { return submissionYear;  }
	void setSubmissionYear(int _submissionYear) { submissionYear = _submissionYear; }
	vector<Property*>* getProperties() { return &properties; }
	void addProperty(Property* _property);
	double calculateTax();
	string serialize();
	void deserialize(vector<string> strings);

};

#endif // !_TAXDECLARATION_H_
