#include <iostream>
#include <string>
#include <sstream>
#include "Address.h"
#include "Apartment.h"
#include "Store.h"
#include "Plot.h"
#include "TaxDeclaration.h"

using namespace std;

TaxDeclaration::TaxDeclaration(int _id, string _name, string _surname, string _vat, string _phone, int _submissionYear)
{
	id = _id;
	name = _name;
	surname = _surname;
	vat = _vat;
	phone = _phone;
	submissionYear = _submissionYear;
}

string TaxDeclaration::toString()
{
	stringstream ss;
	ss << "<-- Tax Declaration -->" << endl;
	ss << "VAT number: " << vat << endl;
	ss << "Name: " << name << endl;
	ss << "Surname: " << surname << endl;
	ss << "Phone: " << phone << endl;
	ss << "Submission year: " << submissionYear << endl;

	for (auto p : properties)
	{
		ss << p->toString() << endl;
	}

	return ss.str();
}

void TaxDeclaration::addProperty(Property* _property)
{
	properties.push_back(_property);
}

double TaxDeclaration::calculateTax()
{
	double totalTax = 0;
	for (auto prop : properties)
	{
		totalTax += prop->calculateTax();
	}
	return totalTax;
}

string TaxDeclaration::serialize()
{
	string ret = "td|" + vat + "|" + surname + "|" + name + "|" + phone + "|" + to_string(submissionYear) + "\n";
	ret += "\n";
	for (auto it = properties.begin(); it != properties.end(); it++)
	{
		ret += (*it)->serialize() + "\n";
	}
	ret += "---\n";

	return ret;
}

void TaxDeclaration::deserialize(vector<string> strings)
{
	for (string s : strings)
	{
		if (s.find("td") == 0)
		{
			stringstream ss(s);
			string token;
			vector<string> words;
			while (getline(ss, token, '|'))
				words.push_back(token);

			vat = words[1];
			name = words[2];
			surname = words[3];
			phone = words[4];
			submissionYear = atoi(words[5].c_str());
		}
		else if (s.find("apartment") == 0)
		{
			Apartment* a = new Apartment();
			a->deserialize(s);
			properties.push_back(a);
		}
		else if (s.find("store") == 0)
		{
			Store* st = new Store();
			st->deserialize(s);
			properties.push_back(st);
		}
		else if (s.find("plot") == 0)
		{
			Plot* p = new Plot();
			p->deserialize(s);
			properties.push_back(p);
		}
	}
}
