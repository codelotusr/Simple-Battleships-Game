#include "Game.h"
#include "GameBoard.h"
#include "Player.h"
#include "Scoreboard.h"
#include "colorsprint.h"




int main() 
{
 
  srand(time(NULL));
  Game game;
  print_first_launch();
  while(game.get_playing_status())
  {
    try
    {
      game.main_menu();
    }
    catch(const GameException& e)
    {
      std::cout << '\n';
      error_message(e.what());
      game.main_menu();
    }
  }


    return 0;
}


