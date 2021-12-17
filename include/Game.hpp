



#ifndef GAME_HPP
#define GAME_HPP


#include "Maze.hpp"

class Player;
class AIPlayer;


class Game {
   
   Maze maze;
   Inventory inventory;

   Player* player;
   AIPlayer* minotaur;


};




#endif // GAME_HPP
