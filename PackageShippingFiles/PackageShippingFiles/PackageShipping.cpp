#include "UIService.h"
using namespace std;

int main()
{
  vector<Package*> packages;
  UIService ui(&packages);
  ui.loadFromFile();
  ui.menu();
  return 0;
}

