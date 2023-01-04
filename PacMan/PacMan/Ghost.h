#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Entity.h"
#include "Map.h"

using namespace std;

class Ghost : public Entity
{
public:
  Ghost(Map* map, int x, int y);
  void play();
  void display();
  string printSymbol();
};

