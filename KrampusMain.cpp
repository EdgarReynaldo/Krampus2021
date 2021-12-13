



#include "Eagle/Backends/Allegro5Backend.hpp"



int main(int argc , char** argv) {
   
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
   
   return 0;
}

