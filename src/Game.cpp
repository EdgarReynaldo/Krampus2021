



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



void Game::Display(EagleGraphicsContext* win) {
   player.SetupCamera();
   maze.DrawLevel(1);
   Setup2D(1200,900);
   win->DrawTextString(win->DefaultFont() , "Hello Krampus Revenge" , 10 , 10 , EagleColor(255,255,0));
   
}



void Game::SetupMaze(size_t game_depth , size_t game_height , size_t game_width) {
   maze.SetupMaze(game_depth , game_height , game_width);
}
