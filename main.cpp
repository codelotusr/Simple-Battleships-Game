#include "Game.h"
#include "GameBoard.h"
#include "Player.h"
#include "Scoreboard.h"
#include "color.hpp"


int main() 
{
 
  srand(time(NULL));
  Game game;
  while(game.get_playing_status())
  {
    try
    {
      game.main_menu();
    }
    catch(const GameException& e)
    {
      std::cout << '\n';
      std::cout << hue::red << e.what() << hue::reset << '\n';
      game.main_menu();
    }
  }


    return 0;
}