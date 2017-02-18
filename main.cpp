#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, Right, Left, Up, Down};
eDirection dir;

void Setup()
{
    srand(time(NULL));
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void Draw()
{
    system("clear");

    for (int i = 0; i <= width + 1; i++)
      std::cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        if(j == 0)
          cout << "#";

        if (i == x && j == y)
          cout << "O";
        else if (i == fruitX && j == fruitY)
          cout << "F";
        else
          cout << " ";

        if (j == width - 1)
          cout << "#";
      }
      cout << endl;
    }

    for (int i = 0; i <= width + 1; i++)
      std::cout << "#";
    cout << endl;
}

void Input()
{
  char i;
    cin >> i;
   switch (i)
   {
   case 'q':
     dir = Left;
     break;
   case 'd':
     dir = Right;
     break;
   case 'z':
     dir = Up;
     break;
   case 's':
     dir = Down;
     break;
   case 'x':
    gameOver = true;
  }
}

void Logic()
{
  switch (dir)
  {
    case Left:
      y--;
      break;
    case Right:
      y++;
      break;
    case Up:
      x--;
      break;
    case Down:
      x++;
      break;
  }

  if (x == fruitX && y == fruitY)
  {
    srand(time(NULL));
    fruitX = rand() % width;
    fruitY = rand() % height;
  }

  if (x == width || x == -1 || y == height || y == -1)
  {
    gameOver = true;
  }
}

int main()
{
    Setup();
    while (!gameOver)
    {
      Draw();
      Input();
      Logic();
    }

    cout << "GAME OVER" << endl;
}
