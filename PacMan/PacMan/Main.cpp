#include <chrono>
#include <thread>
#include <Windows.h>
#include "Entity.h"
#include "Map.h"
#include "PacMan.h"
#include "Ghost.h"

int main()
{
  bool exit = false;
  Map game;
  Entity* player[4];
  player[0] = new PacMan(&game, 23, 13);
  game.map[23][13].entity = player[0];
  game.pacmanLocation = Pair(23, 13);

  player[1] = new Ghost(&game, 5, 5);
  game.map[5][5].entity = player[1];

  player[2] = new Ghost(&game, 5, 20);
  game.map[5][20].entity = player[2];

  player[3] = new Ghost(&game, 8, 5);
  game.map[8][5].entity = player[3];

  int counter = 0;
  while (game.gameActive == true && exit != true)
  {
    if (GetAsyncKeyState(VK_UP) & 0x8000)
      player[0]->direction = Up;
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
      player[0]->direction = Right;
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
      player[0]->direction = Down;
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
      player[0]->direction = Left;

    if (GetKeyState(VK_SPACE) & 0x8000)
    {
      exit = true;
    }
    this_thread::sleep_for(20ms);

    if (counter++ > 10)
    {
      counter = 0;
      for (int i = 0; i < 4; i++)
        player[i]->play();

      game.print();
    }
  }
}