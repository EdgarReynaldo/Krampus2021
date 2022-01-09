



#include "Game.hpp"
#include "Eagle/GraphicsContext.hpp"



void Game::TextureMaze(EagleImage* textures[NUM_FACE_DIRECTIONS]) {
   maze.textures[FACE_DN] = textures[FACE_DN];
   maze.textures[FACE_S] = textures[FACE_S];
   maze.textures[FACE_W] = textures[FACE_W];
   maze.textures[FACE_UP] = textures[FACE_UP];
   maze.textures[FACE_N] = textures[FACE_N];
   maze.textures[FACE_E] = textures[FACE_E];
}



SCENE_STATUS Game::Init() {
   SetupMaze(1 , 25 , 25);
   player.location = Location(1,1,1);
   minotaur.location = Location(1,25,25);
   
   inventory = CreateGameInventory();
   minotaur.inventory.AddItem(inventory.TakeItemAll("Gold Coin"));
   
   minotaur.pmaze = &maze;
   
   return status = SCENE_READY;
}



SCENE_STATUS Game::HandleEvent(EagleEvent e) {
   if (e.type == EAGLE_EVENT_DISPLAY_CLOSE) {return status = SCENE_COMPLETE;}
   if (e.type == EAGLE_EVENT_KEY_DOWN && e.keyboard.keycode == EAGLE_KEY_ESCAPE) {
      return status = SCENE_COMPLETE;
   }
   player.React(e);
   minotaur.React(e);
   return status = SCENE_RUNNING;
}



SCENE_STATUS Game::Update(double dt) {
   player.Update(dt);
   return status = SCENE_RUNNING;
}

#include "GL/gl.h"
#include "Eagle/System.hpp"
#include "Eagle/Timer.hpp"
#include "Eagle/StringWork.hpp"

void Game::Display(EagleGraphicsContext* win) {
//   player.SetupCamera();
//   glEnable(GL_CULL_FACE);
//   glCullFace(GL_BACK);
   glDisable(GL_CULL_FACE);
   glEnable(GL_TEXTURE_2D);
   glEnable(GL_COLOR_MATERIAL);
   glEnable(GL_DEPTH_TEST);
   /// Brute force all of maze
   glClear(GL_DEPTH_BUFFER_BIT);

///   Camera cam(Vec3(12.5,12.5,10.0) , Orient(-90.0f,-90.0f,0.0f) , 2.0*M_PI/3.0 , 1.6);
///   cam.Setup3D(false);
   player.SetupCamera();
   maze.DrawLevel(win , 1);
   Setup2D(win->Width() , win->Height());
   glDisable(GL_CULL_FACE);
   glDisable(GL_DEPTH_TEST);
   win->DrawTextString(win->DefaultFont() , StringPrintF("Hello Krampus Revenge %lf" , win->GetSystem()->GetSystemTimer()->TimePassed()) , 10 , 10 , EagleColor(127,64,0));
   Orient* o = &player.movement.current.orient;
   win->DrawTextString(win->DefaultFont() , StringPrintF("loc = %d,%d,%d , orient = %lf,%lf,%lf" , player.location.z , player.location.y , player.location.x , 
   o->theta.yaw , o->theta.pitch , o->theta.roll) , 10 , 40 , EagleColor(255,0,64));
   
}



void Game::SetupMaze(size_t game_depth , size_t game_height , size_t game_width) {
   maze.SetupMaze(game_depth , game_height , game_width);
}
