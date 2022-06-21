#include "Game.h"
#include "GameBoard.h"
#include "Player.h"
#include "Scoreboard.h"




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
      std::cout << e.what() << '\n';
      game.main_menu();
    }
  }


    return 0;
}


