#pragma once
#include "Map.h"
#include <iostream>
using namespace std;

class Map;

enum Direction { Up, Right, Down, Left };

class Entity
{
public:
  int x;
  int y;
  Direction direction;
  string type;
  Map* map;

  void move(int newX, int newY);
  virtual void play() = 0;
  virtual void display() = 0;
  virtual string printSymbol() = 0;
};
