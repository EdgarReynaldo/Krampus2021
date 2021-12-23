



#ifndef GAME_HPP
#define GAME_HPP


#include "Maze.hpp"

class Player;
class AIPlayer;


class Game : public Scene {
   
   Maze maze;
   Inventory inventory;

   Player* player;
   AIPlayer* minotaur;

public :
   Game();
   Game() :
         maze(),
         inventory(),
         player(0),
         minotaur(0)
   {}
   
   void SetupMaze(size_t game_depth , size_t game_height , size_t game_width);/// Looking from top down depth is z , height is y , width is x
   void SetupMaze(size_t game_depth , size_t game_height , size_t game_width) {
      maze.SetupMaze(game_depth , game_height , game_width);
   }
};




#endif // GAME_HPP
