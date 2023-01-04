#include "Plot.h"

Plot::Plot(int _id, int _surface, Address _address, bool _withinCityLimits, bool _cultivated)
  :Property(_id, _surface, _address)
{
  withinCityLimits = _withinCityLimits;
  cultivated = _cultivated;
}

Plot::Plot()
{
  withinCityLimits = true;
  cultivated = false;
}

string Plot::toString()
{
  stringstream ss;
  ss << "--Plot--" << endl;
  ss << "Surface: " << surface << endl;
  ss << "Address" << address.toString();
  ss << "Is within city limits: " << withinCityLimits << endl;
  ss << "Is cutlivated: " << cultivated << endl;
  return ss.str();
}

double Plot::calculateTax()
{
  return (0.3 * surface + 100 * cultivated + 200 * withinCityLimits);
}

string Plot::serialize()
{
  return "plot|" + to_string(surface) + "|" + to_string(withinCityLimits) + "|" + to_string(cultivated) + "|" + address.serialize();
}

void Plot::deserialize(string s)
{
  stringstream ss(s);
  string token;
  vector<string> words;
  while (getline(ss, token, '|'))
    words.push_back(token);

  surface = atoi(words[1].c_str());
  withinCityLimits = (words[2] == "1") ? true : false;
  cultivated = (words[3] == "1") ? true : false;
  address = Address(words[5], words[6], words[7], words[8]);
}