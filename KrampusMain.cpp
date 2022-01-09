



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
   al_set_new_display_option(ALLEGRO_FLOAT_DEPTH , 1 , ALLEGRO_SUGGEST);
   al_set_new_display_option(ALLEGRO_DEPTH_SIZE , 24 , ALLEGRO_SUGGEST);
   
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
      win->LoadImageFromFile("WestWall.png")
   };
   
   Game game;
   game.TextureMaze(textures);
   if (game.Init() != SCENE_READY) {
      EagleCritical() << "Failed to setup game." << std::endl;
      return 1;
   }
   
   sys->GetSystemTimer()->Start();
   
   while (!quit) {
      if (redraw) {
         win->Clear(EagleColor(255,255,255,255));
         game.Display(win);
//         win->Draw(textures[FACE_UP] , 10,40);
         win->FlipDisplay();
         redraw = false;
      }
      do {
         EagleEvent e = sys->WaitForSystemEventAndUpdateState();
         if (game.HandleEvent(e) == SCENE_COMPLETE) {
            quit = true;
         }
         if (e.type == EAGLE_EVENT_TIMER) {
            game.Update(e.timer.eagle_timer_source->SPT());
            redraw = true;
         }
      } while (!sys->UpToDate());
   }
   return 0;
}









