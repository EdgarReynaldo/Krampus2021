



#include "Eagle/Backends/Allegro5Backend.hpp"
#include "Game.hpp"




int main(int argc , char** argv) {
   
   (void)argc;
   (void)argv;
   
   
   
   Allegro5System* sys = GetAllegro5System();
   
   if (EAGLE_FULL_SETUP != sys->Initialize(EAGLE_FULL_SETUP)) {
      EagleWarn() << "Failed to initialize some subsystem. Continuiing." << std::endl;
   }
   int sw = 800;
   int sh = 600;
   int flags = EAGLE_OPENGL | EAGLE_WINDOWED;
   EagleGraphicsContext* win = sys->CreateGraphicsContext("Main" , sw , sh , flags);
   EAGLE_ASSERT(win && win->Valid());
   
   win->Clear();
   win->FlipDisplay();
   
   sys->Rest(3.0);
   
   bool quit = false;
   bool redraw = true;
   
   Camera cam(Vec3(0,0,0) , Orient(Vec3(0,0,0)) , M_PI/4.0 , 1.6);
   
   EagleImage* textures[NUM_FACE_DIRECTIONS] = {
      win->LoadImageFromFile("Ceiling.png"),
      win->LoadImageFromFile("NorthWall.png"),
      win->LoadImageFromFile("EastWall.png"),
      win->LoadImageFromFile("Floor.png"),
      win->LoadImageFromFile("SouthWall.png"),
      win->LoadImageFromFile("WestWall.png"),
   };
   
   Game game;
   if (game.Init() != SCENE_READY) {
      game.TextureMaze(textures);
      EagleCritical() << "Failed to setup game." << std::endl;
      return 1;
   }
   
   while (!quit) {
      if (redraw) {
         win->Clear();
         game.Display(win);
         win->FlipDisplay();
         redraw = false;
      }
      do {
         EagleEvent e = sys->WaitForSystemEventAndUpdateState();
         if (game.HandleEvent(e) == SCENE_COMPLETE) {
            quit = true;
         }
         if (e.type == EAGLE_EVENT_TIMER) {
            redraw = true;
         }
      } while (!quit);
   }
   return 0;
}









