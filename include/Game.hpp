



#ifndef GAME_HPP
#define GAME_HPP



#include "Maze.hpp"
#include "Scene.hpp"
#include "Player.hpp"



class Game : public Scene {
   
   Maze maze;
   Inventory inventory;

   HumanPlayer player;
   Minotaur minotaur;

public :
//   Game();
   Game() :
         Scene(),
         maze(),
         inventory(),
         player(),
         minotaur()
   {
   }

   virtual SCENE_STATUS Init();/// returns SCENE_READY or SCENE_NOTREADY
   
   virtual SCENE_STATUS HandleEvent(EagleEvent e);/// returns SCENE_RUNNING or SCENE_COMPLETE
   virtual SCENE_STATUS Update(double dt);/// returns SCENE_RUNNING or SCENE_COMPLETE
   virtual void Display();

      
   void SetupMaze(size_t game_depth , size_t game_height , size_t game_width);/// Looking from top down depth is z , height is y , width is x
};



#endif // GAME_HPP
