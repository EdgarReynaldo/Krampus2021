



#ifndef GAME_HPP
#define GAME_HPP



#include "Maze.hpp"
#include "Scene.hpp"
#include "Player.hpp"
#include "MazeCamera.hpp"



void CheckGL();

class Game : public Scene {
   
   Maze maze;
   Inventory inventory;

   HumanPlayer player;
   Minotaur minotaur;

   MazeCamera cam;
   //(Vec3(12.5,12.5,10.0) , Orient(-90.0f,-90.0f,0.0f) , 2.0*M_PI/3.0 , 1.6);
public :
//   Game();
   Game() :
         Scene(),
         maze(),
         inventory(),
         player(),
         minotaur(),
         cam()
   {
   }
   void TextureMaze(EagleImage* textures[NUM_FACE_DIRECTIONS]);

   virtual SCENE_STATUS Init();/// returns SCENE_READY or SCENE_NOTREADY
   
   virtual SCENE_STATUS HandleEvent(EagleEvent e);/// returns SCENE_RUNNING or SCENE_COMPLETE
   virtual SCENE_STATUS Update(double dt);/// returns SCENE_RUNNING or SCENE_COMPLETE
   virtual void Display(EagleGraphicsContext* win);

      
   void SetupMaze(size_t game_depth , size_t game_height , size_t game_width);/// Looking from top down depth is z , height is y , width is x
};



#endif // GAME_HPP
