#include "Entity.h"

void Entity::move(int newX, int newY)
{
  if (newX == x && newY == y)
    cout << "error";
  map->map[newX][newY].entity = map->map[x][y].entity;
  map->map[x][y].entity = NULL;
  x = newX;
  y = newY;
}
