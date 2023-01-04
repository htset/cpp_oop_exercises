#pragma once
#include "Entity.h"
#include <iostream>
using namespace std;

class Entity;

enum BlockType { Wall, Point, Empty };

class Pair {
public:
  int x;
  int y;

  Pair(int, int);
  Pair();
  int operator==(Pair p);
};

class Block
{
public:
  BlockType type;
  Entity* entity;

  Block(BlockType type);
  Block();
};

class Map
{
public:
  Block map[32][28];
  Map();
  int sizeX = 32;
  int sizeY = 28;
  bool gameActive = true;
  Pair pacmanLocation;
  int pointsLeft;
  void print();
};
