#include "Ghost.h"
Ghost::Ghost(Map* map, int x, int y)
{
  this->map = map;
  this->type = "ghost";
  this->x = x;
  this->y = y;
}

void Ghost::play()
{
  vector<Pair> candidateBlocks;
  vector<float> distanceToPacman;
  for (int i = x - 1; i <= x + 1; i++)
    for (int j = y - 1; j <= y + 1; j++)
    {
      if (i >= 0 && i < map->sizeX
        && j >= 0 && j < map->sizeY
        && !(i == x && j == y)
        && map->map[i][j].type != Wall)
      {
        candidateBlocks.push_back(Pair(i, j));
        distanceToPacman
          .push_back(
            sqrt(pow(i - map->pacmanLocation.x, 2) + pow(j - map->pacmanLocation.y, 2)));
      }
    }

  int minDistanceIndex = distance(distanceToPacman.begin(), 
    min_element(distanceToPacman.begin(), distanceToPacman.end()));

  if (map->
    map[candidateBlocks[minDistanceIndex].x][candidateBlocks[minDistanceIndex].y]
    .entity != NULL)
  {
    //move only if pacman is there
    if (map->
      map[candidateBlocks[minDistanceIndex].x][candidateBlocks[minDistanceIndex].y]
      .entity->type == "pacman")
    {
      //eat pacman
      map->
        map[candidateBlocks[minDistanceIndex].x][candidateBlocks[minDistanceIndex].y]
        .entity = NULL;
      map->gameActive = false;
      move(candidateBlocks[minDistanceIndex].x, candidateBlocks[minDistanceIndex].y);
    }
  }
  else
  {
    move(candidateBlocks[minDistanceIndex].x, candidateBlocks[minDistanceIndex].y);
  }
}

void Ghost::display()
{
  cout << "Ghost: (" << x << ", " << y << ")" << endl;
}

string Ghost::printSymbol()
{
  return "A";
}

