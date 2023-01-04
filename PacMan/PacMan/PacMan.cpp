#include "PacMan.h"

PacMan::PacMan(Map* map, int x, int y)
{
  this->map = map;
  this->type = "pacman";
  this->x = x;
  this->y = y;
}

void PacMan::play()
{
  vector<Pair> candidateBlocks;
  for (int i = x - 1; i <= x + 1; i++)
    for (int j = y - 1; j <= y + 1; j++)
    {
      if (i >= 0 && i < map->sizeX
        && j >= 0 && j < map->sizeY
        && !(i == x && j == y)
        && map->map[i][j].type != Wall)
      {
        candidateBlocks.push_back(Pair(i, j));
      }
    }

  if (direction == Up 
    && count(candidateBlocks.begin(), candidateBlocks.end(), Pair(x - 1, y)))
  {
    move(x - 1, y);
  }
  else if (direction == Right 
    && count(candidateBlocks.begin(), candidateBlocks.end(), Pair(x, y + 1)))
  {
    move(x, y + 1);
  }
  else if (direction == Down 
    && count(candidateBlocks.begin(), candidateBlocks.end(), Pair(x + 1, y)))
  {
    move(x + 1, y);
  }
  else if (direction == Left 
    && count(candidateBlocks.begin(), candidateBlocks.end(), Pair(x, y - 1))) 
  {
    move(x, y - 1);
  }
  map->pacmanLocation.x = x;
  map->pacmanLocation.y = y;
  if (map->map[x][y].type == Point)
  {
    map->map[x][y].type = Empty;
    map->pointsLeft--;
    if (map->pointsLeft == 0)
      map->gameActive = false;
  }
}

void PacMan::display()
{
  cout << "PacMan: (" << x << ", " << y << ")" << endl;
}

string PacMan::printSymbol()
{
  return "C";
}

