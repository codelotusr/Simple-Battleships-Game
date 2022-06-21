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
      game.main_menu();
  }


    return 0;
}